//
//  VideoSporas.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 06/03/15.
//
//

#ifndef __RammsyAVShow__VideoSporas__
#define __RammsyAVShow__VideoSporas__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"


class VideoSporas {
public:
    void setup();
    void update(float scaledVol);
    void draw();
    void init();
    void stop();
    
    void sendControlChange(ofxMidiMessage &controlMessage);
    
    int redFilter = 0;
    int greenFilter = 0;
    int blueFilter = 0;
    float volFilter = 0;
    
    ofVideoPlayer video;	//Declare video player object
    ofVideoPlayer video2;
    ofImage image;		//Declare image object
    ofImage image2;
    int table[24];		//Declare table for color replacing
    
};




#endif /* defined(__RammsyAVShow__VideoSporas__) */
