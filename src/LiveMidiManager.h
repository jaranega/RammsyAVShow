//
//  LiveMidiManager.h
//  RammsyAVShow
//
//  Created by Javier Aránega Azor on 14/11/14.
//
//

#ifndef __RammsyAVShow__LiveMidiManager__
#define __RammsyAVShow__LiveMidiManager__

#include <iostream>
#include <stdio.h>
#include "ofMain.h"
#include "ofxMidi.h"
#include "MidiNotesAnimation.h"
#include "ReactiveAnimation.h"



class LiveMidiManager : public ofxMidiListener {
    
public:
    
    //static const unsigned NUM_BOXES = 100;
    
    static const int BASS_CHANNEL = 4;
    static const int TETRA_CHANNEL = 1;
    static const int DRUM_CHANNEL = 11;
    
    void setup(MidiNotesAnimation &midiAnimation);
    void update();
    void draw();
    void exit();
    
    void newMidiMessage(ofxMidiMessage& eventArgs);
    void sendControlChange(ofxMidiMessage& eventArgs);
    void changeMidiChannel(int channel_number);
    void addMidiChannel(int channel_number);
    void removeMidiChannel(int channel_number);
	
	stringstream text;
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
    
    int channelSelected;
    vector<int> channelsOn;
    
    int midiPort;

    
    MidiNotesAnimation * midiAnimation;
    ReactiveAnimation* reactiveAnimation;
    
    
    // boxes
    vector<ofVec3f> posns;
    vector<ofColor> cols;
    ofVboMesh boxMesh;
    

};


#endif /* defined(__RammsyAVShow__LiveMidiManager__) */
