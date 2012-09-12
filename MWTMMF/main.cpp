/* 
 * File:   main.cpp
 * Author: Marc
 *
 * Created on January 30, 2012, 4:54 PM
 * (C) Marc Gershow; licensed under the Creative Commons Attribution Share Alike 3.0 United States License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to
 * Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.

 */

#include <cstdlib>
#include "MWT_Image_CV.h"
#include "MWT_Library.h"
#include "MMF_MWT_Processor.h"

#include "StackReader.h"
#include "highgui.h"
#include "tictoc/tictoc.h"

using namespace std;

/*
 * 
 */

struct ParamsT{
    bool valid;
    string mmfname;
    string outpath;
    string outname;
    string batchname;
};

int testLibraryMMF (void);
int testCVConversion (void);
int testMMF_MWT_Processor (void);
void properUsage (const char *argv);
int parseArguments (int argc, char **argv, ParamsT &p) ;
int runProgram (int argc, char **argv);
void badargs (ParamsT &p, int argc, char **argv);

#define defaultSettingsFile "defaultMWTSettings.txt"
#define programName "mmf2mwt"

int main(int argc, char** argv) {
   
    return runProgram(argc, argv);
    //return testCVConversion();
    //return testMMF_MWT_Processor();
  //  return  testLibraryMMF();
}
int runProgram (int argc, char **argv) {
    ParamsT p;
    int rv;
    if ((rv = parseArguments(argc, argv, p)) || !p.valid) {
        return rv;
    }
    MMF_MWT_Processor mp;
    bool defaultbatch;
    if (defaultbatch = p.batchname.empty()) { //single = sign is correct
        p.batchname = string(defaultSettingsFile);
    }
    ifstream ifs(p.batchname.c_str());
    if (!ifs.good()) {
        ifs.close();
        if (defaultbatch) {
            ofstream os(defaultSettingsFile);
            os << mp;
        } else {
            cout << "batch file not found" << endl;
            badargs(p, argc, argv);
            return 1;
        }
    } else {
        ifs >> mp;
    }
    if (rv = mp.process(p.mmfname.c_str(), p.outpath.empty() ? NULL : p.outpath.c_str(), p.outname.empty() ? NULL : p.outname.c_str())) {
        cout << "processing failed with return value: " << rv << endl;
        badargs(p, argc, argv);
        return rv;
    }
    return rv;
}
void badargs (ParamsT &p, int argc, char **argv) {
    cout << "Your command: ";
    for (int j = 0; j < argc; ++j) {
        cout << argv[j] << " ";
    }
    cout << endl << "was interpreted as " << endl;
    cout << "mmf name (with path): " << (p.mmfname.empty() ? "empty" : p.mmfname) << endl;
    cout << "batch file name (with path): " << (p.batchname.empty() ? defaultSettingsFile: p.batchname) << endl;
    cout << "output path: " << (p.outpath.empty() ? "empty" : p.outpath) << endl;
    cout << "output prefix: " << (p.outname.empty() ? "empty" : p.outname) << endl;
    return;
}
int parseArguments (int argc, char **argv, ParamsT &p) {
    p.valid = false;
    cout <<  "nargs = " << argc << endl << "args are: ";
    for (int j = 0; j < argc; ++j) {
        cout << argv[j] << endl;
    }
    switch (argc) {
        case 0:
            cout << "argc = 0; this should never happen!";
            properUsage(programName);
            return 1;
        case 5:
            p.outname = string(argv[4]);
        case 4:
            p.outpath = string(argv[3]);
        case 3:            
            p.batchname = string(argv[2]);
        case 2:
            p.mmfname = string(argv[1]);
            p.valid = true;
            return 0;
            break;
        case 1: {
            properUsage(programName);
            ifstream ifs(defaultSettingsFile);
            if (!ifs.good()) {
                ifs.close();
                ofstream os(defaultSettingsFile);
                MMF_MWT_Processor mp;
                os << mp;
            }
            return 0;
            break;
        }
        default:
            properUsage(programName);
            return 1;
            break;
    }
    return 1;
}
void properUsage (const char *argv) {
    cout << argv << " imagestack.mmf :" << endl << "runs MWT on imagestack.mmf using settings defined in: " << defaultSettingsFile << endl;
    cout << "outputpath and prefix are determined by path and name of imagestack" << endl;
    cout << "data is stored in pathToMMF/datestring/stackname.blobs etc." << endl;
    cout << "--------------" << endl;
    cout << argv << " imagestack.mmf settingsFile.txt :" << endl << "runs MWT on imagestack.mmf using settings defined in settingsFile.txt" << endl;
    cout << "outputpath and prefix are determined by path and name of imagestack" << endl;
    cout << "data is stored in pathToMMF/datestring/stackname.blobs etc." << endl;
    cout << "--------------" << endl;
    cout << argv << " imagestack.mmf settingsFile.txt pathToOutput" << endl << "runs MWT on imagestack.mmf using settings defined in settingsFile.txt" << endl;
    cout << "data is stored in pathToOutput/datestring/stackname.blobs etc." << endl;
    cout << "--------------" << endl;
    cout << argv << " imagestack.mmf settingsFile.txt pathToOutput outputPrefix" << endl << "runs MWT on imagestack.mmf using settings defined in settingsFile.txt" << endl;
    cout << "data is stored in pathToOutput/datestring/outputPrefix.blobs etc." << endl;
    cout << "--------------" << endl;
    cout << endl << endl << "other parsing options available if someone wants to write them" <<endl;
}

int testMMF_MWT_Processor(void) {
    MMF_MWT_Processor p;
    ifstream ifs(defaultSettingsFile);
    if (!ifs.good()) {
        ofstream ofs(defaultSettingsFile);
        ofs << p;
        return 0;
    } else {
        ifs >> p;
    }

//    p.windowOutputUpdateInterval = 30;
    return p.process("E:\\from Bruno - photo from Janelia\\20120113 - w1118 temporal run\\20120113 - w1118 temporal run\\2128\\w1118@UAS_TNT_2_0003@t8@l_10A_50s6x50s50s#n#n#n@30.mmf");
}

int testCVConversion (void) {
    int w = 729; int h = 512;
    IplImage *im = cvCreateImage(cvSize(w,h), IPL_DEPTH_8U, 1);
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < h; ++i) {
            cvSet2D(im, i, j, cvScalarAll(255*((i/128 + j/128)%2)));
        }
    }
    cvNamedWindow("cv checkerboard", 0);
    cvShowImage("cv checkerboard", im);

    MWT_Image_CV mwtim(im);
     for (int j = w/3; j < 2*w/3; ++j) {
        for (int i = h/3; i < 2*h/3; ++i) {
             mwtim.set (i,j, 128);
        }
    }
   
    IplImage *dst = NULL;
    mwtim.toIplImage(&dst);
    IplImage *dst2 = cvCreateImage(cvSize(dst->width, dst->height), IPL_DEPTH_8U, 0);
    cvConvert(dst, dst2);
    cvNamedWindow("mwt checkerboard", 0);
    cvShowImage("mwt checkerboard", dst2);

    IplImage *dst4 = cvCreateImage(cvSize(dst->height, dst->width), IPL_DEPTH_8U,0);
    cvTranspose(dst2, dst4);
    cvNamedWindow("mwt checkerboard transposed", 0);
    cvShowImage("mwt checkerboard transposed", dst4);

    cvSetImageROI(im, cvRect(w/4,h/4,w/2,h/2));
    MWT_Image_CV mwtim2(im);
    mwtim2.toIplImage(&dst);
    IplImage *dst3 = cvCreateImage(cvSize(dst->width, dst->height), IPL_DEPTH_8U, 0);
    cvConvert(dst, dst3);
    cvNamedWindow("mwt checkerboard cropped", 0);
    cvShowImage("mwt checkerboard cropped", dst3);
    cvWaitKey(-1);
    return 0;
}

int testLibraryMMF (void) {
    TrackerLibrary a_library;

  // Unit tests only support up to binning of 3 (objects may be too small otherwise)
 //   int bin = 1;
  int i;
  int h1 = a_library.getNewHandle();

  a_library.setSubtractionImageCorrectionAlgorithm(h1);
  a_library.setCombineBlobs(h1,true);

  StackReader sr("E:\\from Bruno - photo from Janelia\\20120113 - w1118 temporal run\\20120113 - w1118 temporal run\\2128\\w1118@UAS_TNT_2_0003@t8@l_10A_50s6x50s50s#n#n#n@30.mmf");
  CvSize sz = sr.getImageSize();
  

  
  if (h1!=1) return 1;
  int imbits = 8;
  int shiftbits = imbits - 8;
  int outshiftbits = 15 - imbits;
  
  i = a_library.setImageInfo(h1,imbits,sz.width,sz.height); if (i!=h1) return 2;
   a_library.setRectangle(h1, 0, sz.width, 0, sz.height);

  i = a_library.setDate(h1,2007,12,26,10,50,33); if (i!=h1) return 4;
  i = a_library.setOutput(h1,".","test",true,false,false); if (i!=h1) return 6;
 
  i = a_library.setDancerBorderSize(h1,10);
  short white = 2*(1<<a_library.getBitDepth(h1))-1;
  short gray = 1<<a_library.getBitDepth(h1);
 // short grey = 1<<(a_library.getBitDepth((h1) - 1));
  short low = (1<<a_library.getBitDepth(h1)) * 2 / 3;
  short high = (1<<a_library.getBitDepth(h1)) - 1;
  cout << "white = " << white <<" , gray = " << gray << ", low = " << low << ", high = " << high << endl;

  int lowthresh = 40 << shiftbits;
  int highthresh = 60 << shiftbits;
  int minarea = 10;
  int minnewarea = 30;
  int maxnewarea = 2E4;
  int maxarea = 3E4;
  int alpha = 8;
  int updateBandNumber = 16;
  i = a_library.setRefIntensityThreshold(h1, 1, 1);
  i = a_library.setObjectIntensityThresholds(h1,gray + lowthresh,gray + highthresh); if (i!=h1) return 16;
  i = a_library.setObjectSizeThresholds(h1,minarea,minnewarea,maxnewarea,maxarea); if (i!=h1) return 18;
  i = a_library.setObjectPersistenceThreshold(h1,8); if (i!=h1) return 20;
  i = a_library.setAdaptationRate(h1,alpha); if (i!=h1) return 22;
  i = a_library.enableOutlining(h1,true); if (i!=h1) return 24; 
  i = a_library.enableSkeletonization(h1,true); if (i!=h1) return 25; 

  

  // Make sure error-checking is working; shouldn't be able to process images without loading them!
  i = a_library.processImage(h1); if (i!=0) return 33;
 
  i = a_library.beginOutput(h1); if (i!=h1) return 35;
  i = a_library.setUpdateBandNumber(h1,updateBandNumber); if (i!=h1) return 37;
  i = a_library.setVelocityIntegrationTime(h1,1.2); if (i!=h1) return 38;

  IplImage *src = NULL;
  IplImage *src16 = NULL;
  IplImage *dst = NULL;
  IplImage *color = NULL;
  IplImage *dst3 = NULL;
  double frame_rate = 30;
  
  sr.getBackground(0, &src, 300);
  MWT_Image_CV im0(src);
  im0.depth = imbits;
  im0 <<= shiftbits;
  MWT_Image_CV im(src);
  im.depth = imbits;
  im <<= shiftbits;
  //= MWT_Image_CV::IplImageToMWTImage(src);
  //im0.bin = 0;
//  im.bin = 0;
  a_library.scanObjects(h1, im0);

//  for (int j = 0; j < updateBandNumber; ++j) {
//       cout << j << ": ";
//       sr.getFrame(j, &src);
//       im.setImageDataFromIplImage(src);
//       cout << a_library.scanObjects(h1, im) << "  objs\t";
//  }
  cvNamedWindow("mwt image", 0);
  color = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 3);
  src16 = cvCreateImage(cvGetSize(src), IPL_DEPTH_16S, 1);
  TICTOC::tictoc tim;


  for (int j=0;j<sr.getTotalFrames();j++)
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
      im <<= shiftbits;
      tim.tic("mwt processing");
      i = a_library.loadImage(h1,im,j/frame_rate); if (i!=h1) return 39;  // Wholistic image loading
      int nobj = a_library.processImage(h1);
      tim.toc("mwt processing");
      
      if (j%10 == 0) {
          bool scaleToRange = true;
          im.set(im.bounds, 0);
          tim.tic ("showObjects");
          i = a_library.showObjects(h1, im);// if (i!=h1) return 49;
          tim.toc("showObjects");
         // im <<= outshiftbits;
         // im.toIplImage(&dst);
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
      }
      cout << "frame " << j << " , " << nobj << " objs found " << tim.toc("loop")/1000 << " ms" << endl;

 //     i = a_library.resizeRescaleMemory(h1, im, im.bounds); if (i!=h1) return 49;
      //im <<= outshiftbits;
     // im.toIplImage8U(&dst3, scaleToRange);
    //  cvShowImage("mwt memory image", dst3);
    //  if (tolower(cvWaitKey(1)) == 'q') {
     //    break;
    //  }

//    if ( (j%2) == 0)
//    {
//      printf("frame %02d: %d %d %.2f  %.2f %.2f  %.1f %.2f  %.1f %.2f  %.3f %.2f  %.2f\n",
//        j,a_library.reportNumber(h1),a_library.reportNumberPersisting(h1),a_library.reportPersistence(h1),
//        a_library.reportSpeed(h1),a_library.reportAngularSpeed(h1),
//        a_library.reportLength(h1),a_library.reportRelativeLength(h1),
//        a_library.reportWidth(h1),a_library.reportRelativeWidth(h1),
//        a_library.reportAspect(h1),a_library.reportRelativeAspect(h1),
//        a_library.reportEndWiggle(h1)
//      );
//    }

  }
  cout << tim.generateReport() << endl;

  i = a_library.complete(h1); if (i!=h1) return 50;

  return 0;
}