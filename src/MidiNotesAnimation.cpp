//
//  MidiNotesAnimation.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 19/11/14.
//
//

#include "MidiNotesAnimation.h"


void MidiNotesAnimation::setup(){
    tetraAnimation.setup();
    bassAnimation.setup();
    drumAnimation.setup();
}

void MidiNotesAnimation::update(){
    
    for(int i = 0; i < channels.size(); i++){
        
        switch (channels[i]) {
                
            case MidiConstants::TETRA_CHANNEL :
                tetraAnimation.update();
                break;
                
            case MidiConstants::BASS_CHANNEL :
                bassAnimation.update();
                break;
                
            case MidiConstants::DRUM_CHANNEL :
                drumAnimation.update();
                break;
            default:
                break;
        }
    }
    
}

void MidiNotesAnimation::draw(){
    
    for(int i = 0; i < channels.size(); i++){
        
        switch (channels[i]) {
                
            case MidiConstants::TETRA_CHANNEL :
                tetraAnimation.draw();
                break;
                
            case MidiConstants::BASS_CHANNEL :
                bassAnimation.draw();
                break;
            
            case MidiConstants::DRUM_CHANNEL :
                drumAnimation.draw();
                break;
            default:
                break;
        }
    }
    
    
}

void MidiNotesAnimation::newMidiMessage(ofxMidiMessage &midiMessage) {
    
    this->midiMessage = midiMessage;
    
    switch (midiMessage.channel) {
            
        case MidiConstants::TETRA_CHANNEL:
            tetraAnimation.newMidiMessage(midiMessage);
            break;
        
        case MidiConstants::BASS_CHANNEL:
             bassAnimation.newMidiMessage(midiMessage);
            break;
            
        case MidiConstants::DRUM_CHANNEL:
            drumAnimation.newMidiMessage(midiMessage);
            break;
            
        default:
            break;
    }
}

void MidiNotesAnimation::sendControlChange(ofxMidiMessage &controlMessage) {

    this->controlMessage = controlMessage;
    
    cout << controlMessage.control << endl;;
    
    tetraAnimation.sendControlChange(controlMessage);
    bassAnimation.sendControlChange(controlMessage);
    drumAnimation.sendControlChange(controlMessage);
}

void MidiNotesAnimation::restart(int channel) {
    
    switch (channel) {
            
        case MidiConstants::TETRA_CHANNEL:
            tetraAnimation.restart();
            break;
            
        case MidiConstants::BASS_CHANNEL:
            bassAnimation.restart();
            break;
            
        case MidiConstants::DRUM_CHANNEL:
            break;
            
        default:
            break;
    }
    
    
}


