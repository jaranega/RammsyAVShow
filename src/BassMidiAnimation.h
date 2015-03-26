//
//  BassMidiAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#ifndef __RammsyAVShow__BassMidiAnimation__
#define __RammsyAVShow__BassMidiAnimation__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"
#include "AbstractMidiAnimation.h"

class BassMidiAnimation : public AbstractMidiAnimation {
    
public:
    
    static const unsigned NUM_BOXES = 100;

    
    void setup();
    void update();
    void draw();
    void exit();
    
    void newMidiMessage(ofxMidiMessage &midiMessage);
    void sendControlChange(ofxMidiMessage &controlMessage);
    void restart();

    ofLight light;
    ofEasyCam cam;
    
    // boxes
    vector<ofVec3f> posns;
    vector<ofColor> cols;
    ofVboMesh boxMesh;


    ofxMidiMessage midiMessage;
    ofxMidiMessage controlMessage;
    
    
};

#endif /* defined(__RammsyAVShow__BassMidiAnimation__) */
