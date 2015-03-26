//
//  TetraMidiAnimation.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#include "TetraMidiAnimation.h"

void TetraMidiAnimation::setup() {
    ribbon.setup();
}

void TetraMidiAnimation::update() {
    ribbon.update();
}

void TetraMidiAnimation::draw() {
    ribbon.draw();
}

void TetraMidiAnimation::restart() {
    ribbon.restart();
}

void TetraMidiAnimation::newMidiMessage(ofxMidiMessage &midiMessage) {
    
    this->midiMessage = midiMessage;
    cout << midiMessage.getStatusString(midiMessage.status) << " " << midiMessage.pitch << endl;
    
    if (midiMessage.getStatusString(midiMessage.status) == "Note On")
        ribbon.noteOn(midiMessage.pitch);
    else if (midiMessage.getStatusString(midiMessage.status) == "Note Off")
        ribbon.noteOff(midiMessage.pitch);
}

void TetraMidiAnimation::sendControlChange(ofxMidiMessage &controlMesssage) {
    
    this->controlMessage = controlMessage;
    
    int r, g, b;
    
    //cout << "CC " << controlMesssage.control << " " << controlMesssage.value << endl;
    
    switch (controlMesssage.control) {
        
        case 10:
            r = controlMesssage.value * 2;
            break;

        case 74:
            g = controlMesssage.value * 2;
            break;
            
        case 71:
            b = controlMesssage.value * 2;
            break;
    }
    
    ribbon.changeColor(r,g,b);
}