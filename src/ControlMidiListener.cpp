//
//  ControlMidiListener.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 18/11/14.
//
//

#include "ControlMidiListener.h"

//--------------------------------------------------------------
void ControlMidiListener::setup(LiveMidiManager& liveMidi, ofxPostProcessing& postMidi, ofxPostProcessing& postReactive, ReactiveAnimation& reactiveAnimation){
    
    this->liveMidi = &liveMidi;
    this->reactiveAnimation = &reactiveAnimation;
    this->postMidi = &postMidi;
    this->postReactive = &postReactive;
}

//--------------------------------------------------------------
void ControlMidiListener::newMidiMessage(ofxMidiMessage& msg) {
   
    midiMessage = msg;
    int midiChannel = -1;
    int reactiveIndex =-1;
    int postIndex = -1;
    
    
    //Activation of MidiDraw Channel
    
    switch (midiMessage.pitch)
    {
        case 44: midiChannel = MidiConstants::TETRA_CHANNEL; break;
        case 45: midiChannel = MidiConstants::BASS_CHANNEL; break;
        case 46: midiChannel = MidiConstants::DRUM_CHANNEL; break;
        
        case 36: reactiveIndex = 1; break;
        case 37: reactiveIndex = 2; break;
        case 38: reactiveIndex = 3; break;
        case 39: reactiveIndex = 4; break;
        case 40: reactiveIndex = 5; break;
        case 41: reactiveIndex = 6; break;
        case 42: reactiveIndex = 7; break;
        case 43: reactiveIndex = 8; break;
        case 51: reactiveIndex = 9; break;
        case 50: reactiveIndex = 10; break;
            
       /* case 47: postIndex = 1; break;
        case 48: postIndex = 2; break;
        case 49: postIndex = 3; break;
        case 50: postIndex = 4; break;
        case 51: postIndex = 5; break;
        case 59: postIndex = 6; break;
        case 60: postIndex = 7; break;*/
            
        default:
            break;
    }
    
    if (midiChannel != -1)
    {
        if (midiMessage.getStatusString(midiMessage.status) == "Note On") liveMidi->addMidiChannel(midiChannel);
            else if (midiMessage.getStatusString(midiMessage.status) == "Note Off") liveMidi->removeMidiChannel(midiChannel);
    }
    
    
    if (reactiveIndex != -1)
    {
        if (midiMessage.getStatusString(midiMessage.status) == "Note On") reactiveAnimation->addAnimation(reactiveIndex);
        else if (midiMessage.getStatusString(midiMessage.status) == "Note Off") reactiveAnimation->removeAnimation(reactiveIndex);
            
    }
    
    if (midiMessage.getStatusString(midiMessage.status) == "Control Change") {
        reactiveAnimation->sendControlChange(midiMessage);
        liveMidi->sendControlChange(midiMessage);
    }
    
    /*if (postIndex != -1)
    {
        unsigned idx = postIndex - '0';
        
        if (idx < postReactive->size()) (*postReactive)[idx]->setEnabled(!(*postReactive)[idx]->getEnabled());
        if (idx < postMidi->size()) (*postMidi)[idx]->setEnabled(!(*postMidi)[idx]->getEnabled());
    }*/
    
    
    
    //Activation de Effect to Apply
    cout << "newmidimessage " << midiMessage.pitch << " " << midiMessage.channel << "\n" ;
}


