/* 
 * File:   MMF_MWT_Processor.h
 * Author: Marc
 *
 * Created on February 1, 2012, 3:29 PM
 */

#ifndef MMF_MWT_PROCESSOR_H
#define	MMF_MWT_PROCESSOR_H

class MMF_MWT_Processor {
public:
    double frame_rate;
    int thresholdToMarkObject;
    int thresholdToFillObject;
    int minObjectArea;
    int minNewObjectArea;
    int maxNewObjectArea;
    int maxObjectArea;
    int windowOutputUpdateInterval;
    int startFrame;
    int endFrame;

    int adpatationAlpha;
    int updateBandNumber;
    int dancerBorderSize;
    int minFramesObjectMustPersist;


    MMF_MWT_Processor() {
        setToDefaults();
    }
    int process(const char *mmf_filename, const char* output_path = NULL, const char* output_prefix = NULL);
    MMF_MWT_Processor(const MMF_MWT_Processor& orig);
    virtual ~MMF_MWT_Processor();

    void setToDefaults() {
        frame_rate = 30;
        thresholdToMarkObject = 70;
        thresholdToFillObject = 50;
        minObjectArea = 10;
        minNewObjectArea = 30;
        maxNewObjectArea = 2E4;
        maxObjectArea = 3E4;
        adpatationAlpha = 8;
        updateBandNumber = 16;
        dancerBorderSize = 10;
        minFramesObjectMustPersist = 60;
        windowOutputUpdateInterval = -1;
        startFrame = 0;
        endFrame = -1;
    }

private:

};

#endif	/* MMF_MWT_PROCESSOR_H */

