/* 
 * File:   MMF_MWT_Processor.h
 * Author: Marc
 *
 * Created on February 1, 2012, 3:29 PM
 * (C) Marc Gershow; licensed under the Creative Commons Attribution Share Alike 3.0 United States License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to
 * Creative Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.

 */

#ifndef MMF_MWT_PROCESSOR_H
#define	MMF_MWT_PROCESSOR_H

#include "yaml-cpp/yaml.h"
#include <iostream>
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
    bool writeLog;

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

    YAML::Emitter& toYaml(YAML::Emitter& out) const;
    void fromYaml(const YAML::Node &node);
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
        writeLog = false;
    }
protected:
        YAML::Emitter& yamlBody (YAML::Emitter& out) const;
    private:

};

YAML::Emitter& operator << (YAML::Emitter& out, const MMF_MWT_Processor &mp); 

void operator >> (const YAML::Node &node, MMF_MWT_Processor &mp);

std::ostream& operator << (std::ostream &out, const MMF_MWT_Processor &mp);
std::istream& operator >> (std::istream &in, MMF_MWT_Processor &mp);
#endif	/* MMF_MWT_PROCESSOR_H */

