//
//  LiveLiveMidiManager.cpp
//  RammsyAVShow
//
//  Created by Javier Aránega Azor on 14/11/14.
//
//

#include "LiveMidiManager.h"

//--------------------------------------------------------------
void LiveMidiManager::setup(MidiNotesAnimation &midiAnimation){
    
    this->midiAnimation = &midiAnimation;
    
    midiPort = 1;
    channelSelected = 1;
    
    midiIn.listPorts();
	midiIn.openPort(midiPort);
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, true, false);
	midiIn.addListener(this);
	midiIn.setVerbose(true);
    

}

//--------------------------------------------------------------
void LiveMidiManager::update(){
    
}

//--------------------------------------------------------------
void LiveMidiManager::draw()
{
}

void LiveMidiManager::changeMidiChannel(int channel_number){
    channelSelected = channel_number;
}

void LiveMidiManager::addMidiChannel(int channel_number){
    
    channelsOn.push_back(channel_number);
    midiAnimation->channels = channelsOn;
}

void LiveMidiManager::removeMidiChannel(int channel_number){
    
    vector<int>::iterator it = channelsOn.begin(); // iterator points to first element
    
    for(; it != channelsOn.end();){
        if( *it == channel_number ) {
            it = channelsOn.erase(it); // be sure to return the iterator when erasing so it is not invalidated
            midiAnimation->restart(channel_number);
        }
        else ++it;
    }
    
    midiAnimation->channels = channelsOn;
}

//--------------------------------------------------------------
void LiveMidiManager::exit() {
	midiIn.closePort();
	midiIn.removeListener(this);
}

void LiveMidiManager::sendControlChange(ofxMidiMessage &msg)
{
    midiAnimation->sendControlChange(msg);
}

//--------------------------------------------------------------
void LiveMidiManager::newMidiMessage(ofxMidiMessage& msg) {
    
    midiMessage = msg;

    midiAnimation->newMidiMessage(msg);
    
    /*if (channelSelected == midiMessage.channel)
    {
        posns.push_back(ofVec3f(ofRandom(0, ofGetWidth()), ofClamp(midiMessage.pitch, 0,  ofGetHeight()), ofRandom(-300, 300)));
        cols.push_back(ofColor::fromHsb(255 * ofRandom(NUM_BOXES) / (float)NUM_BOXES, 255, 255, 255));
    }*/
}



