//
//  BassMidiAnimation.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#include "BassMidiAnimation.h"

//--------------------------------------------------------------
void BassMidiAnimation::setup(){
    
    // Setup light
    light.setPosition(1000, 1000, 2000);
}

//--------------------------------------------------------------
void BassMidiAnimation::update(){
    
}

//--------------------------------------------------------------
void BassMidiAnimation::draw()
{
    // copy enable part of gl state
    // copy enable part of gl state
    glPushAttrib(GL_ENABLE_BIT);
    
    // setup gl state
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    light.enable();
    
    //cam.begin();
    
    // draw boxes
    for (unsigned i = 0; i < posns.size(); ++i)
    {
        ofSetColor(cols[i]);
        ofPushMatrix();
        ofTranslate(posns[i]);
        boxMesh = ofMesh::box(20, 20, 20);
        boxMesh.draw();
        ofPopMatrix();
    }
    
    //cam.end();
    
    // set gl state back to original
    glPopAttrib();
    
}


//--------------------------------------------------------------
void BassMidiAnimation::newMidiMessage(ofxMidiMessage& msg) {
    
    cout << "bassmidimssg" << endl;
    posns.push_back(ofVec3f(ofRandom(0, ofGetWidth()), ofMap(msg.pitch, 20, 80, 0,  ofGetHeight()), ofRandom(-300, 300)));
    cols.push_back(ofColor::fromHsb(255 * ofRandom(NUM_BOXES) / (float)NUM_BOXES, 255, 255, 255));
    
   // posns.push_back(ofVec3f(ofRandom(-300, 300), ofRandom(-300, 300), ofRandom(-300, 300)));
   // cols.push_back(ofColor::fromHsb(255 * i / (float)NUM_BOXES, 255, 255, 255));

}

void BassMidiAnimation::sendControlChange(ofxMidiMessage &controlMesssage) {
    
    this->controlMessage = controlMessage;

}

void BassMidiAnimation::restart(){
    cout << "restart" << endl;
    posns.clear();
    cols.clear();
    boxMesh.clearIndices();
    boxMesh.clearVertices();
    
}
