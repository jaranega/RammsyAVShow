//
//  DrumMidiAnimation.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#include "DrumMidiAnimation.h"

void DrumMidiAnimation::setup() {
}


void DrumMidiAnimation::update() {
    
}

void DrumMidiAnimation::draw() {
    
}

void DrumMidiAnimation::newMidiMessage(ofxMidiMessage &midiMessage) {
    this->midiMessage = midiMessage;
}

void DrumMidiAnimation::sendControlChange(ofxMidiMessage &controlMesssage) {
    
    this->controlMessage = controlMessage;
}

void DrumMidiAnimation::restart(){
    cout << "restart" << endl;
}