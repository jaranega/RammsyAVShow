//
//  RibbonAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 21/11/14.
//
//

#ifndef __RammsyAVShow__RibbonAnimation__
#define __RammsyAVShow__RibbonAnimation__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"
#include "ofxTween.h"

class RibbonAnimation {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void noteOn(int pitch);
    void noteOff(int pitch);
    void restart();
    
    void mouseMoved(int x, int y );
    void changeColor(int r, int g, int b);
    
    //this holds all of our points
    vector<ofVec3f> points;
    //this keeps track of the center of all the points
    ofVec3f center;
    
    ofMesh mesh;
    
    int actualPitch;
    
    vector<int> noteson;
    vector<int> pitchToPoint;
    
    ofColor color;
   

};


#endif /* defined(__RammsyAVShow__RibbonAnimation__) */
