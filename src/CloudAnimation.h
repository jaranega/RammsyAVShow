//
//  CloudAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 22/11/14.
//
//

#ifndef __RammsyAVShow__CloudAnimation__
#define __RammsyAVShow__CloudAnimation__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"


class CloudAnimation {
public:
    void setup();
    void update(float scaledVol);
    void draw();
    void mousePressed(int x, int y, int button);

    
    ofSoundPlayer sound;	//Sound sample
    void sendControlChange(ofxMidiMessage &controlMessage);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float volFilter = 0;
    int redFilter = 0;
    int greenFilter = 0;
    int blueFilter = 0;
};

#endif /* defined(__RammsyAVShow__CloudAnimation__) */
