/* 
 * File:   MWT_Image_CV.cpp
 * Author: Marc
 * 
 * Created on January 30, 2012, 2:13 PM
 * (C) Marc Gershow; licensed under the Creative Commons Attribution Share Alike 3.0 United States License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to
 * Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.

 */
#include <iostream>
#include "MWT_Image_CV.h"
#include "cv.h"
using namespace std;
//note that because MWT_Image stores data is column ordered format & IplImage stores data
//in row order, the IplImage header represents the transpose of the MWT Image
IplImage *MWT_Image_CV::createImageHeaderForMWTImage(const Image& im) {
    IplImage *hdr = cvCreateImageHeader(cvSize(im.size.y, im.size.x), IPL_DEPTH_16S, 1);
    if (hdr == NULL) {
        return hdr;
    }
    hdr->widthStep = hdr->width*sizeof(short);
    cvSetData(hdr, im.pixels, hdr->widthStep);
    CvRect roi = cvRect(im.bounds.near.y, im.bounds.near.x, im.bounds.height(), im.bounds.width());
    cvSetImageROI(hdr, roi);
    return hdr;
}

Image MWT_Image_CV::IplImageToMWTImage(const IplImage* src) {

    return MWT_Image_CV(src);

}


IplImage *MWT_Image_CV::toIplImage(IplImage** dst) const {
    return MWTImagetoIplImage(*this, dst);
}

IplImage *MWT_Image_CV::MWTImagetoIplImage(const Image& src, IplImage** dst) {
    IplImage *dstim;

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

    IplImage *srchdr = createImageHeaderForMWTImage(src);
    cvTranspose(srchdr, dstim);
    cvReleaseImageHeader(&srchdr);

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
    IplImage *hdr = createImageHeaderForMWTImage(*this);
    cvTranspose(src, hdr);
    cvReleaseImageHeader(&hdr);

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

