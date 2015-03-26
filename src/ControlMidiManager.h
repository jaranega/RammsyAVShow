//
//  ControlMidiManager.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 19/11/14.
//
//

#ifndef __RammsyAVShow__ControlMidiManager__
#define __RammsyAVShow__ControlMidiManager__

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include "ofxMidi.h"


class ControlMidiManager {
    
public:
    
    void setup();
    void update();
    void draw();
    void exit();

    void changeMidiChannel(int channel_number);
    
    stringstream text;
    
    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    
    int channelSelected;
    int midiPort;
    
};




#endif /* defined(__RammsyAVShow__ControlMidiManager__) */
