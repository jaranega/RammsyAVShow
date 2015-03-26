//
//  DrumMidiAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#ifndef __RammsyAVShow__DrumMidiAnimation__
#define __RammsyAVShow__DrumMidiAnimation__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"
#include "AbstractMidiAnimation.h"

class DrumMidiAnimation : public AbstractMidiAnimation {
    
public:
    
    void setup();
    void update();
    void draw();
    void newMidiMessage(ofxMidiMessage &midiMessage);
    void sendControlChange(ofxMidiMessage &controlMessage);
    void restart();
    
    ofxMidiMessage controlMessage;
    ofxMidiMessage midiMessage;
    
};

#endif /* defined(__RammsyAVShow__DrumMidiAnimation__) */
