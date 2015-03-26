//
//  ControlMidiListener.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 18/11/14.
//
//

#ifndef __RammsyAVShow__RammsyMidiListener__
#define __RammsyAVShow__RammsyMidiListener__

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "ofxMidi.h"
#include "LiveMidiManager.h"
#include "ofxPostProcessing.h"
#include "ReactiveAnimation.h"
#include "MidiConstants.h"

class ControlMidiListener: public ofxMidiListener {
    
public:
    void setup(LiveMidiManager& liveMidi, ofxPostProcessing& postMidi, ofxPostProcessing& postReactive, ReactiveAnimation& reactiveAnimation);
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
    ofxMidiMessage midiMessage;
    
    LiveMidiManager * liveMidi;
    ofxPostProcessing * postMidi;
    ofxPostProcessing * postReactive;
    ReactiveAnimation * reactiveAnimation;
    
};



#endif /* defined(__RammsyAVShow__RammsyMidiListener__) */
