//
//  TriangleSphere.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 06/03/15.
//
//

#ifndef __RammsyAVShow__TriangleSphere__
#define __RammsyAVShow__TriangleSphere__

#include <stdio.h>
#include "ofMain.h"
#include "ofxMidiMessage.h"

class TriangleSphere {
    
public:
    void setup();
    void update(float scaledVol);
    void draw();
    void sendControlChange(ofxMidiMessage &controlMessage);
    void restart();

    
    ofShader shader;	//Shader
private:
    vector<ofPoint> vertices;
    vector<ofColor> colors;
    int nTri;		//The number of triangles
    int nVert;		//The number of the vertices equals nTri * 3
    float time1 = 0;
    float phase = 0;
    float distortAmount = 0;
    
    float volFilter = 0;
    int redFilter = 0;
    int greenFilter = 0;
    int blueFilter = 0;
 
    int numNotes = 0;
    
};


#endif /* defined(__RammsyAVShow__TriangleSphere__) */
