//
//  ControlMidiManager.cpp
//  RammsyAVShow
//
//  Created by Javier Aránega Azor on 14/11/14.
//
//

#include "ControlMidiManager.h"

//--------------------------------------------------------------
void ControlMidiManager::setup(){
    
    midiPort = 0;
    channelSelected = 1;
    
    midiIn.listPorts();
    midiIn.openPort(midiPort);
    
    midiIn.ignoreTypes(false, false, false);
    midiIn.setVerbose(true);
    
    
}

//--------------------------------------------------------------
void ControlMidiManager::update(){
    
}


//--------------------------------------------------------------
void ControlMidiManager::draw()
{
}

//--------------------------------------------------------------
void ControlMidiManager::exit() {
    midiIn.closePort();
}




