/* 
 * File:   MWT_Image_CV.h
 * Author: Marc
 *
 * Created on January 30, 2012, 2:13 PM
 * (C) Marc Gershow; licensed under the Creative Commons Attribution Share Alike 3.0 United States License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to
 * Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.
 */

#include "MWT_Geometry.h"
#include "MWT_Image.h"
#include "cxtypes.h"

#ifndef MWT_IMAGE_CV_H
#define	MWT_IMAGE_CV_H

/* MWT_Image_CV extends Image (found in MWT_Image.h) to allow
 * translation between IplImage and Image
 *
 * no additional data fields are defined
 * most methods are also available as static equivalents
 * e.g.
 * MWT_Image_CV (const IplImage *src)
 * static Image IplImageToMWTImage(const IplImage *src)
 */
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
     * if src->roi is not NULL, only the area within src->roi is copied 
     */
    MWT_Image_CV(const IplImage *src) :
    Image(sizeOfIplImageOrROI(src), false) {
        setImageDataFromIplImage(src);
        setBitDepthFromIplImage(src);
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
     * the bit depth of the image is set to 8
     *
     * if src->roi is not NULL, only the area within src->roi is copied 
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
     * the entire image is copied; the destination roi is set to im.bounds;
     */
    static IplImage *MWTImagetoIplImage(const Image &src, IplImage **dst = NULL);
    IplImage *toIplImage(IplImage **dst = NULL) const;

    /*  IplImage *toIplImage8U(IplImage **dst = NULL, bool scaleToRange = false) const;
     *  static IplImage *MWTImagetoIplImage8U(const Image &src, IplImage **dst = NULL, bool scaleToRange = false);
     *
     *  convert an MWT image to an 8-bit IPL image;
     *    if scaleToRange is true,
     *       the smallest value in src becomes 0 in dst and the largest becomes 255
     *    if scaleToRange is false,
     *       dstvalue = srcvalue << (src.depth - 8) - 128
     *     
     */
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
     * if src->roi is not NULL, only the area within src->roi is copied
     *
     * we do not adjust image bit depth
     */
    void setImageDataFromIplImage (const IplImage *src);
    void setBitDepthFromIplImage (const IplImage *src);

protected:
    static IplImage *createImageHeaderForMWTImage(const Image &im); //note that image is transposed 
    static Rectangle cvRectangleToMWTRectangle (const CvRect& cvr);
    static CvRect mwtRectangleToCvRectangle (const Rectangle& r);
    static Point sizeOfIplImageOrROI (const IplImage *src);

private:
    MWT_Image_CV(const MWT_Image_CV& orig);
    

};

#endif	/* MWT_IMAGE_CV_H */

