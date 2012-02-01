/* 
 * File:   MWT_Image_CV.h
 * Author: Marc
 *
 * Created on January 30, 2012, 2:13 PM
 */

#include "MWT_Geometry.h"
#include "MWT_Image.h"
#include "cxtypes.h"

#ifndef MWT_IMAGE_CV_H
#define	MWT_IMAGE_CV_H


class MWT_Image_CV : public Image {
public:

     /* MWT_Image_Cv(const IplImage *src)
     * creates a new MWT_Image with the same size and image data as src
     *
     * regardless of the bit depth of src, the Image has short data
     * if src has bit depth IPL_DEPTH_8U, IPL_DEPTH_8S, or IPL_DEPTH_1U,
     * no scaling is done in the conversion
     * the bit depth of the image is set to 8
     *
     * if src has bit depth IPL_DEPTH_16U, IPL_DEPTH_16S, IPL_DEPTH_32F, IPL_DEPTH_32S, IPL_DEPTH_64F
     * no scaling is done in the conversion
     * the bit depth of the image is set to 16
     *
     * if src->roi is not NULL, only the area within src->roi is copied (same behavior as cvConvertScale) 
     */
    MWT_Image_CV(const IplImage *src) :
    Image(sizeOfIplImageOrROI(src), false) {
        setImageDataFromIplImage(src);
        setBitDepthFromIplImage(src);
        bin = 0;
    }

    /* Image IplImageToMWTImage(IplImage *src);
     * creates a new MWT_Image with the same size and image data as src
     * 
     * regardless of the bit depth of src, the Image has short data
     * if src has bit depth IPL_DEPTH_8U, IPL_DEPTH_8S, or IPL_DEPTH_1U,
     * no scaling is done in the conversion 
     * the bit depth of the image is set to Image:DEFAULT_BIT_DEPTH
     *
     * if src has bit depth IPL_DEPTH_16U, IPL_DEPTH_16S, IPL_DEPTH_32F, IPL_DEPTH_32S, IPL_DEPTH_64F
     * no scaling is done in the conversion
     * the bit depth of the image is set to 16
     *
     * src->roi is ignored (same behavior as cvConvertScale) when copying the data
     * but Image.bounds is set to src->roi
     */
    static Image IplImageToMWTImage(const IplImage *src);

    /* IplImage *toIplImage(IplImage **dst = NULL);
     * static IplImage *MWTImagetoIplImage(const Image &src, IplImage **dst = NULL);
     *
     * creates a new IPL Image with the same size and data as this image,
     *   bit depth of the IplImage will be IPL_DEPTH_16S
     * if dst == NULL or *dst == NULL, then a new image is created
     * if *dst points to an IplImage:
     *    if *dst has bit depth IPL_DEPTH_16S and the same size,
     *     then the image is copied into *dst and *dst does not change
     *    otherwise, we release *dst and create a new image
     *
     * the return value is a pointer to the new image
     *
     * only the area within image.bounds is copied
     */
    static IplImage *MWTImagetoIplImage(const Image &src, IplImage **dst = NULL);
    IplImage *toIplImage(IplImage **dst = NULL) const;
    
    IplImage *toIplImage8U(IplImage **dst = NULL, bool scaleToRange = false) const;
    static IplImage *MWTImagetoIplImage8U(const Image &src, IplImage **dst = NULL, bool scaleToRange = false);

    virtual ~MWT_Image_CV();
    MWT_Image_CV();

    /* void setImageDataFromIplImage (const IplImage *src);
     * sets data to a copy of src,
     * if src is a different size from this image,
     * we delete pixels (if this image owns_pixels), then create new
     * memory of the appropriate size
     *
     * we set the image size to be that of the src image
     * we set image bounds to match src->roi
     *
     * we do not adjust image bit depth
     */
    void setImageDataFromIplImage (const IplImage *src);
    void setBitDepthFromIplImage (const IplImage *src);

protected:
 //   static IplImage *createImageHeaderForMWTImage(const Image &im);
    static Rectangle cvRectangleToMWTRectangle (const CvRect& cvr);
    static CvRect mwtRectangleToCvRectangle (const Rectangle& r);
    static Point sizeOfIplImageOrROI (const IplImage *src);

private:
    MWT_Image_CV(const MWT_Image_CV& orig);
    

};

#endif	/* MWT_IMAGE_CV_H */

