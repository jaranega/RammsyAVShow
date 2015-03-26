//
//  TetraMidiAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#ifndef __RammsyAVShow__TetraMidiAnimation__
#define __RammsyAVShow__TetraMidiAnimation__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"
#include "AbstractMidiAnimation.h"
#include "RibbonAnimation.h"

class TetraMidiAnimation : public AbstractMidiAnimation {
    
public:
    
    void setup();
    void update();
    void draw();
    void newMidiMessage(ofxMidiMessage &midiMessage);
    void sendControlChange(ofxMidiMessage &controlMessage);
    
    void restart();
    
    ofxMidiMessage midiMessage;
    ofxMidiMessage controlMessage;
    
    RibbonAnimation ribbon;
    
};

#endif /* defined(__RammsyAVShow__TetraMidiAnimation__) */
