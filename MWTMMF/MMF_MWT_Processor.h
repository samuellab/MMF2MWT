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
    int thresholdToMarkObject;
    int thresholdToFillObject;
    

    MMF_MWT_Processor();
    MMF_MWT_Processor(const MMF_MWT_Processor& orig);
    virtual ~MMF_MWT_Processor();
private:

};

#endif	/* MMF_MWT_PROCESSOR_H */

