//
//  Model3D.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 22/11/14.
//
//

#ifndef __RammsyAVShow__Model3D__
#define __RammsyAVShow__Model3D__

#include <stdio.h>

#include "ofMain.h"
#include "ofx3DModelLoader.h"
#include "ofxMidiMessage.h"

class Model3D {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void sendControlChange(ofxMidiMessage &controlMessage);
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofx3DModelLoader squirrelModel;
    
};


#endif /* defined(__RammsyAVShow__Model3D__) */
