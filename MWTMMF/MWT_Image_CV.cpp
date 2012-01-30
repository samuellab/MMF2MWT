/* 
 * File:   MWT_Image_CV.cpp
 * Author: Marc
 * 
 * Created on January 30, 2012, 2:13 PM
 */

#include "MWT_Image_CV.h"

IplImage *MWT_Image_CV::createImageHeaderForMWTImage(const Image& im) {
    IplImage *hdr = cvCreateImageHeader(CvSize(im.size.x, im.size.y), IPL_DEPTH_16S, 1);
    if (hdr == NULL) {
        return hdr;
    }
    hdr->widthStep = hdr->width;
    cvSetData(hdr, im.pixels, hdr->widthStep);
    CvRect roi = cvRect(im.bounds.near.x, im.bounds.near.y, im.bounds.width(), im.bounds.height());
    cvSetImageROI(hdr, roi);
    return hdr;
}

Image MWT_Image_CV::IplImageToMWTImage(const IplImage* src) {

    Image im(Point(src->width, src->height), false);
    IplImage *tmp = createImageHeaderForMWTImage(im);
    cvConvert(src, tmp);
    CvRect roi = cvGetImageROI(src);    
    im.bounds = Rectangle(roi.x, roi.y, roi.width+roi.x - 1, roi.height + roi.y - 1);
    cvReleaseImageHeader(&tmp);
    return im;
}

IplImage *MWT_Image_CV::MWTImagetoIplImage(const Image& src, IplImage** dst) {
    IplImage *dstim;
    IplImage *srcim = createImageHeaderForMWTImage(src);
    CvRect roi = cvGetImageROI(srcim);

    //verify that destination image, if it exists, has proper size and depth
    if (dst != NULL && *dst != NULL){
        if ((*dst)->width != roi->width || (*dst)->height != roi->height || (*dst)->depth != IPL_DEPTH_16S || (*dst)->nChannels != 1) {
            cvReleaseImage(dst);
        }
    }
    if (dst == NULL || *dst == NULL) {
        dstim = cvCreateImage(cvSize(roi.width, roi.height), IPL_DEPTH_16S, 1);
    } else {
        dstim = *dst;
    }
    cvCopyImage(srcim, dstim);
    cvReleaseImage(&srcim);
    if (dst != NULL) {
        *dst = dstim;
    }

    
}

MWT_Image_CV::MWT_Image_CV() {
}

MWT_Image_CV::MWT_Image_CV(const MWT_Image_CV& orig) {
}

MWT_Image_CV::~MWT_Image_CV() {
}

