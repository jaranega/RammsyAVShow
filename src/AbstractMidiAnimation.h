//
//  AbstractMidiAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#ifndef __RammsyAVShow__AbstractMidiAnimation__
#define __RammsyAVShow__AbstractMidiAnimation__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"

class AbstractMidiAnimation {
        
    public:
        
        virtual void setup(string name);
        virtual void init();
        virtual void update();
        virtual void draw();
        virtual void newMidiMessage(ofxMidiMessage &midiMessage);
    
        string name;
        ofxMidiMessage midiMessage;
        
};

#endif /* defined(__RammsyAVShow__AbstractMidiAnimation__) */
