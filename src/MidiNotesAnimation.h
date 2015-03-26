//
//  MidiNotesAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 19/11/14.
//
//

#ifndef __RammsyAVShow__MidiNotesAnimation__
#define __RammsyAVShow__MidiNotesAnimation__

#include <stdio.h>
#include <iostream>
#include "ofxMidiMessage.h"
#include "MidiConstants.h"
#include "AbstractMidiAnimation.h"
#include "TetraMidiAnimation.h"
#include "BassMidiAnimation.h"
#include "DrumMidiAnimation.h"

class MidiNotesAnimation {
    
public:
    void setup();
    void update();
    void draw();
    
    void newMidiMessage(ofxMidiMessage &midiMessage);
    void sendControlChange(ofxMidiMessage &controlMessage);
    void restart(int channel);

    ofxMidiMessage midiMessage;
    ofxMidiMessage controlMessage;
    
    vector<int> channels;
   
    //vector<AbstractMidiAnimation> * animations;
    
    TetraMidiAnimation tetraAnimation;
    BassMidiAnimation bassAnimation;
    DrumMidiAnimation drumAnimation;
    
    
    
    
};

#endif /* defined(__RammsyAVShow__MidiNotesAnimation__) */
