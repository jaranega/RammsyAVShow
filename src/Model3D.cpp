//
//  Model3D.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 22/11/14.
//
//

#include "Model3D.h"
#include "Model3D.h"

GLfloat lightOnePosition[] = {40.0, 40, 100.0, 0.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 0.5};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 0.5};

//--------------------------------------------------------------
void Model3D::setup(){
    //ofBackground(255,255,255);
    
    ofSetVerticalSync(true);
    
    //some model / light stuff
    ofEnableDepthTest();
    glShadeModel (GL_SMOOTH);
    
    /* initialize lighting */
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    glEnable (GL_LIGHT0);
    glLightfv (GL_LIGHT1, GL_POSITION, lightTwoPosition);
    glLightfv (GL_LIGHT1, GL_DIFFUSE, lightTwoColor);
    glEnable (GL_LIGHT1);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
    
    //load the squirrel model - the 3ds and the texture file need to be in the same folder
    squirrelModel.loadModel("Uhfsatcom/Uhfsatcom.3ds", 80);
    
    //you can create as many rotations as you want
    //choose which axis you want it to effect
    //you can update these rotations later on
    squirrelModel.setRotation(0, 90, 1, 0, 0);
    squirrelModel.setRotation(1, 270, 0, 0, 1);
    squirrelModel.setScale(0.9, 0.9, 0.9);
    squirrelModel.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    
}

//--------------------------------------------------------------
void Model3D::update(){
    squirrelModel.setRotation(1, 270 + ofGetElapsedTimef() * 60, 0, 0, 1);
    
}

//--------------------------------------------------------------
void Model3D::draw(){
    
    //lets tumble the world with the mouse
    glPushMatrix();
    
    //draw in middle of the screen
    glTranslatef(ofGetWidth()/2,ofGetHeight()/2,0);
    //tumble according to mousex
    glTranslatef(-ofGetWidth()/2,-ofGetHeight()/2,0);
    
    //ofSetColor(255, 255, 255, 255);
    squirrelModel.draw();
    
    glPopMatrix();
    
    //ofSetHexColor(0x000000);
    //ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);
    
}

void Model3D::sendControlChange(ofxMidiMessage &controlMesssage) {
    
    cout << "CC " << controlMesssage.control << " " << controlMesssage.value << endl;
    
    //switch (controlMesssage.control) {  }
    
}

//--------------------------------------------------------------
void Model3D::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Model3D::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Model3D::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Model3D::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Model3D::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Model3D::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Model3D::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Model3D::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Model3D::dragEvent(ofDragInfo dragInfo){ 
    
}
