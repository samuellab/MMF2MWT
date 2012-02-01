/* 
 * File:   MWT_Image_CV.cpp
 * Author: Marc
 * 
 * Created on January 30, 2012, 2:13 PM
 */
#include <iostream>
#include "MWT_Image_CV.h"
#include "cv.h"
using namespace std;
//IplImage *MWT_Image_CV::createImageHeaderForMWTImage(const Image& im) {
//    IplImage *hdr = cvCreateImageHeader(cvSize(im.size.x, im.size.y), IPL_DEPTH_16S, 1);
//    if (hdr == NULL) {
//        return hdr;
//    }
//    hdr->widthStep = hdr->width*sizeof(short);
//    cvSetData(hdr, im.pixels, hdr->widthStep);
//    CvRect roi = cvRect(im.bounds.near.x, im.bounds.near.y, im.bounds.width(), im.bounds.height());
//    cvSetImageROI(hdr, roi);
//    return hdr;
//}

Image MWT_Image_CV::IplImageToMWTImage(const IplImage* src) {

    return MWT_Image_CV(src);
//    Image im(Point(src->width, src->height), false);
  //  im.bin = 1;
   // IplImage *tmp = createImageHeaderForMWTImage(im);
   // cvConvert(src, tmp);
    // CvRect roi = cvGetImageROI(src);
   
//    im.bounds = cvRectangleToMWTRectangle(roi);
   // cout << "im.bounds.near = " << im.bounds.near.x << " , " << im.bounds.near.y << " im.bounds.far = " << im.bounds.far.x << " , " << im.bounds.far.y << endl;
  //  cvReleaseImageHeader(&tmp);
   // return im;
}


IplImage *MWT_Image_CV::toIplImage(IplImage** dst) const {
    return MWTImagetoIplImage(*this, dst);
}

IplImage *MWT_Image_CV::MWTImagetoIplImage(const Image& src, IplImage** dst) {
    IplImage *dstim;
//    IplImage *srcim = createImageHeaderForMWTImage(src);
  //  CvRect roi = cvGetImageROI(srcim);

    //verify that destination image, if it exists, has proper size and depth
    Rectangle r = src.getBounds();
    if (dst != NULL && *dst != NULL){
        if ((*dst)->width != r.width() || (*dst)->height != r.height() ||
                (*dst)->depth != IPL_DEPTH_16S
                || (*dst)->nChannels != 1) {
            cvReleaseImage(dst);
        }
    }
    if (dst == NULL || *dst == NULL) {
        dstim = cvCreateImage(cvSize(r.width(), r.height()), IPL_DEPTH_16S, 1);
    } else {
        dstim = *dst;
    }

    for (int j = 0; j < r.height(); ++j) {
        short *ptr = (short *) (dstim->imageData + j*dstim->widthStep);
        for (int i = 0; i < r.width(); ++i) {
            ptr[i] = src.get(i+r.near.x,j+r.near.y);
        }
    }

    if (dst != NULL) {
        *dst = dstim;
    }
    return dstim;
}

IplImage *MWT_Image_CV::MWTImagetoIplImage8U(const Image &src, IplImage **dst, bool scaleToRange) {
    IplImage *temp = MWTImagetoIplImage(src, NULL);
    IplImage *dstim;

    if (dst != NULL && *dst != NULL){
        if ((*dst)->width != temp->width || (*dst)->height != temp->height ||
                (*dst)->depth != IPL_DEPTH_8U
                || (*dst)->nChannels != 1) {
            cvReleaseImage(dst);
        }
    }
     if (dst == NULL || *dst == NULL) {
        dstim = cvCreateImage(cvGetSize(temp), IPL_DEPTH_8U, 1);
    } else {
        dstim = *dst;
    }
    double scale, shift;
    if (scaleToRange) {
        double minval, maxval;
        cvMinMaxLoc(temp, &minval, &maxval, NULL, NULL, NULL);
        scale = 255.0/(maxval-minval);
        shift = -minval*scale;        
    } else {
        shift = -128;
        scale = 1.0 / (1<<(src.depth - 8));
    }
    cvConvertScale(temp, dstim, scale, shift);

    cvReleaseImage(&temp);
    if (dst != NULL) {
        *dst = dstim;
    }
    return dstim;
}

IplImage *MWT_Image_CV::toIplImage8U(IplImage** dst, bool scaleToRange) const {
    return MWTImagetoIplImage8U(*this, dst, scaleToRange);
}

/*
 IplImage *MWT_Image_CV::MWTImagetoIplImage(const Image& src, IplImage** dst) {
    IplImage *dstim;
    IplImage *srcim = createImageHeaderForMWTImage(src);
    CvRect roi = cvGetImageROI(srcim);

    //verify that destination image, if it exists, has proper size and depth
    if (dst != NULL && *dst != NULL){
        if ((*dst)->width != roi.width || (*dst)->height != roi.height || (*dst)->depth != IPL_DEPTH_16S || (*dst)->nChannels != 1) {
            cvReleaseImage(dst);
        }
    }
    if (dst == NULL || *dst == NULL) {
        dstim = cvCreateImage(cvSize(roi.width, roi.height), IPL_DEPTH_16S, 1);
    } else {
        dstim = *dst;
    }
    cvCopyImage(srcim, dstim);
    cvReleaseImageHeader(&srcim);
    if (dst != NULL) {
        *dst = dstim;
    }


}

 */
void MWT_Image_CV::setImageDataFromIplImage(const IplImage* src) {
    if (src == NULL) {
        return;
    }
    if (size != sizeOfIplImageOrROI(src)) {
        if (owns_pixels) {
            delete[] pixels;
        }
        size = sizeOfIplImageOrROI(src);
        bounds = Rectangle(Point(0,0),size-1);
        pixels = new short[ bounds.area() ];
    }
    IplImage *temp = NULL;
    if (src->depth != IPL_DEPTH_16S) {
        temp = cvCreateImage(cvSize(size.x, size.y), IPL_DEPTH_16S, 1);
        cvConvert(src, temp);
        src = temp;
    }


    CvRect roi = cvGetImageROI(src);
    for (int j = 0; j < size.y; ++j) {
        int y = roi.y + j;
        short *ptr = (short *) (src->imageData + y*src->widthStep);
        for (int i = 0; i < size.x; ++i) {
            int x = roi.x + i;    
            set(i,j, ptr[x]);
        }
    }
    if (temp != NULL) {
        cvReleaseImage(&temp);
    }
   

}

void MWT_Image_CV::setBitDepthFromIplImage(const IplImage* src) {
    if (src == NULL) {
        return;
    }
    switch (src->depth) {
        case IPL_DEPTH_1U:
        case IPL_DEPTH_8U:
        case IPL_DEPTH_8S:
            depth = 8;
            break;
        case IPL_DEPTH_16U:
        case IPL_DEPTH_16S:
        case IPL_DEPTH_32F:
        case IPL_DEPTH_32S:
        case IPL_DEPTH_64F:
            depth = 16;
            break;
    }
    
}

Rectangle MWT_Image_CV::cvRectangleToMWTRectangle(const CvRect& cvr) {
    return Rectangle(cvr.x, cvr.width+cvr.x - 1, cvr.y, cvr.height + cvr.y - 1);
}

CvRect MWT_Image_CV::mwtRectangleToCvRectangle(const Rectangle& r) {
    return cvRect (min (r.near.x, r.far.x), min (r.near.y, r.far.y), abs(r.far.x-r.near.x) + 1, abs(r.far.y - r.near.y) + 1);
}

Point MWT_Image_CV::sizeOfIplImageOrROI(const IplImage* src) {
    if (src == NULL) {
        return Point(0,0);
    }
    return cvRectangleToMWTRectangle(cvGetImageROI(src)).size();
}

MWT_Image_CV::MWT_Image_CV() {
}

MWT_Image_CV::MWT_Image_CV(const MWT_Image_CV& orig) {
}

MWT_Image_CV::~MWT_Image_CV() {
}

