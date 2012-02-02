/* 
 * File:   MMF_MWT_Processor.cpp
 * Author: Marc
 * 
 * Created on February 1, 2012, 3:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "MWT_Image.h"
#include "MWT_Library.h"
#include "tictoc/tictoc.h"
#include "MWT_Image_CV.h"
#include "StackReader.h"
#include "MMF_MWT_Processor.h"
#include "highgui.h"
#include "cv.h"

using namespace std;

int MMF_MWT_Processor::process(const char* mmf_filename, const char* output_path, const char* output_prefix){
  TrackerLibrary a_library;
  int i;
  int h1 = a_library.getNewHandle();

  
  string outpath(mmf_filename);
  size_t ind = outpath.find_last_of("/\\");
  string outname = outpath.substr(ind+1);
  outpath = outpath.substr(0,ind + 1);

  ind = outname.find_last_of('.');
  outname = outname.substr(0,ind);

 
  string fname = ((output_path == NULL) ? outpath : string(output_path)) +  ((output_prefix == NULL) ? outname : string(output_prefix)) + ".mwtlog";
  ofstream *outstream = NULL;
  if (writeLog) {
      outstream = new ofstream(fname.c_str());
      if (!outstream->good()) {
          delete outstream;
          outstream = NULL;
      }
  }
  ostream& logstream = (outstream == NULL) ? cout : *outstream;

  a_library.setSubtractionImageCorrectionAlgorithm(h1);
  a_library.setCombineBlobs(h1,true);

  StackReader sr(mmf_filename);
  if (sr.isError()) {
      logstream << "Failed to load: " << mmf_filename << endl << "Error: " << sr.getError() << endl;
      return 1;
  }

  CvSize sz = sr.getImageSize();
  if (sr.isError()) {
      logstream << "Error reading from: " << mmf_filename << endl << "Error: " << sr.getError() << endl;
      return 2;
  }
  int imbits = 8;
  
  i = a_library.setImageInfo(h1,imbits,sz.width,sz.height); if (i!=h1) return 3;
  a_library.setRectangle(h1, 0, sz.width, 0, sz.height);


  //i = a_library.setDate(h1,2007,12,26,10,50,33); if (i!=h1) return 4;

    
  i = a_library.setOutput(h1,output_path == NULL ? outpath.c_str() : output_path, output_prefix == NULL ? outname.c_str() : output_prefix,true,false,false); if (i!=h1) return 4;

  i = a_library.setDancerBorderSize(h1,dancerBorderSize);
  short gray = 1<<a_library.getBitDepth(h1);


  i = a_library.setRefIntensityThreshold(h1, 1, 1); if (i!=h1) return 10;
  i = a_library.setObjectIntensityThresholds(h1,gray + thresholdToFillObject,gray + thresholdToMarkObject); if (i!=h1) return 11;
  i = a_library.setObjectSizeThresholds(h1,minObjectArea,minNewObjectArea,maxNewObjectArea,maxObjectArea); if (i!=h1) return 12;
  i = a_library.setObjectPersistenceThreshold(h1,minFramesObjectMustPersist); if (i!=h1) return 13;
  i = a_library.setAdaptationRate(h1,adpatationAlpha); if (i!=h1) return 14;
  i = a_library.enableOutlining(h1,true); if (i!=h1) return 15;
  i = a_library.enableSkeletonization(h1,true); if (i!=h1) return 16;


 

  i = a_library.beginOutput(h1); if (i!=h1) return 20;
  i = a_library.setUpdateBandNumber(h1,updateBandNumber); if (i!=h1) return 21;
  i = a_library.setVelocityIntegrationTime(h1,1.0); if (i!=h1) return 22;

  IplImage *src = NULL;
  IplImage *src16 = NULL;

  IplImage *dst = NULL;
  IplImage *color = NULL;


  sr.getBackground(0, &src, 10*frame_rate);
  if (src == NULL || sr.isError()) {
      logstream << "failed to read initial background from disk " << endl;
      logstream << "stackReaderError: " << sr.getError() << endl;
      return 25;
  }
  src16 = cvCreateImage(cvGetSize(src), IPL_DEPTH_16S, 1);
  cvConvert(src, src16);

  MWT_Image_CV im0(src16);
  im0.depth = imbits;

  MWT_Image_CV im(src16);
  im.depth = imbits;

  a_library.scanObjects(h1, im0); // initializes the background

  if (windowOutputUpdateInterval > 0) {
      cvNamedWindow("mwt image", 0);
      color = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);
  }
  TICTOC::tictoc tim;

  startFrame = startFrame < 0 ? 0 : startFrame;
  endFrame = endFrame < 0 ? sr.getTotalFrames() : endFrame + 1;
  endFrame = endFrame > sr.getTotalFrames() ? sr.getTotalFrames() : endFrame;
  

  for (int j=startFrame;j < endFrame;j++)
  {
      tim.tic("loop");

      tim.tic("load frame");
      sr.getFrame(j, &src);
      tim.toc("load frame");

      tim.tic("convertTo16S");
      cvConvert(src, src16);
      tim.toc("convertTo16S");

      tim.tic("convertFromIPL");
      im.setImageDataFromIplImage(src16);
      tim.toc("convertFromIPL");

      tim.tic("mwt processing");
      i = a_library.loadImage(h1,im,j/frame_rate); if (i!=h1) return 39;  // Wholistic image loading
      int nobj = a_library.processImage(h1);      
      tim.toc("mwt processing");

      tim.tic("image display and output");
      if (windowOutputUpdateInterval > 0 && (j%windowOutputUpdateInterval == 0)) {
          bool scaleToRange = true;
          im.set(im.bounds, 0);
          tim.tic ("showObjects");
          i = a_library.showObjects(h1, im);// if (i!=h1) return 49;
          tim.toc("showObjects");
         
          tim.tic ("convertToIpl");
          im.toIplImage8U(&dst, scaleToRange);
          tim.toc ("convertToIpl");

          tim.tic ("image display");
          cvConvertImage(src, color, 0);
          cvSetImageCOI(color, 1);
          cvCopy(dst, color, NULL);
          cvShowImage("mwt image", color);
          tim.toc ("image display");

          tim.tic ("waitkey");
          if (tolower(cvWaitKey(1)) == 'q') {
             break;
          }
          tim.toc("waitkey");
          logstream << "frame " << j << " , " << nobj << " objs found " << tim.getStatistics("loop")*1000 << " ms average processing time" << endl;

      }
      tim.toc("image display and output");
//      

      tim.toc("loop");
  }
  logstream << tim.generateReport() << endl;

  i = a_library.complete(h1); if (i!=h1) return 50;

  if (outstream != NULL) {
      delete(outstream);
  }

  return 0;
}


MMF_MWT_Processor::MMF_MWT_Processor(const MMF_MWT_Processor& orig) {
}

MMF_MWT_Processor::~MMF_MWT_Processor() {
}

