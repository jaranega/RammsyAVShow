//
//  CinematicMesh.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 22/11/14.
//
//

#ifndef __RammsyAVShow__CinematicMesh__
#define __RammsyAVShow__CinematicMesh__

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxMidiMessage.h"

class CinematicMesh {
    
    ofImage image;
    ofMesh mesh;
    ofEasyCam easyCam;
    vector<ofVec3f> offsets;
    
    ofMesh meshCopy;
    bool orbiting;
    float startOrbitTime;
    
    // These variables will let us store the polar coordinates of each vertex
    vector<float> distances;
    vector<float> angles;
    ofVec3f meshCentroid;
    
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
    
    
};

#endif /* defined(__RammsyAVShow__CinematicMesh__) */
