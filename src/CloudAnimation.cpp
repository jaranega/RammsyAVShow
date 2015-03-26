//
//  CloudAnimation.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 22/11/14.
//
//

#include "CloudAnimation.h"

const int N = 256;		//Number of bands in spectrum
float spectrum[ N ];	//Smoothed spectrum values
float Rad = 500;		//Cloud raduis parameter
float Vel = 0.5;		//Cloud points velocity parameter
int bandRad = 2;		//Band index in spectrum, affecting Rad value
int bandVel = 100;		//Band index in spectrum, affecting Vel value

const int n = 500;		//Number of cloud points

//Offsets for Perlin noise calculation for points
float tx[n], ty[n], tz[n];
ofPoint p[n];			//Cloud's points positions

float time0 = 0;		//Time value, used for dt computing

//--------------------------------------------------------------
void CloudAnimation::setup(){

    //Initialize points offsets by random numbers
    for ( int j=0; j<n; j++ ) {
        tx[j] = ofRandom( 0, 1000 );
        ty[j] = ofRandom( 0, 1000 );
        tz[j] = ofRandom( 0, 1000 );
    }
}

//--------------------------------------------------------------
void CloudAnimation::update(float scaledVol){
    
    //Computing dt as a time between the last
    //and the current calling of update()
   
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp( dt, 0.0, 0.01 );
    time0 = time;
    
    //Update Rad and Vel from spectrum
    //Note, the parameters in ofMap's were tuned for best result
    //just for current music track
    Rad = ofMap( scaledVol , 0, 1, ofGetHeight()/1.5, ofGetWidth()/1.5, true );
    Vel = ofMap( scaledVol , 0, 1, 0.01, 0.5 );
  
    //Update particles positions
    for (int j=0; j<n; j++) {
        tx[j] += Vel * dt;	//move offset
        ty[j] += Vel * dt;	//move offset
        tz[j] += Vel * dt;	//move offset
        //Calculate Perlin's noise in [-1, 1] and
        //multiply on Rad
        p[j].x = ofSignedNoise( tx[j] ) * Rad;
        p[j].y = ofSignedNoise( ty[j] ) * Rad;
        p[j].z = ofSignedNoise( tz[j] ) * Rad;
    }
}

//--------------------------------------------------------------
void CloudAnimation::draw(){
    
    //Draw cloud
    //ofLight light;
    //light.move(0, 0, 0);
    //Move center of coordinate system to the screen center
    ofEnableDepthTest();
    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2);
    
    //Draw points
    ofSetColor( 255, 255, 255, 127);
    ofFill();
    for (int i=0; i<n; i++) {
        //ofSphere(p[i].x, p[i].y, p[i].z, 3); //
        ofCircle(p[i], 2 );
    }
    
    //Draw lines between near points
    float dist = 30;	//Threshold parameter of distance
    for (int j=0; j<n; j++) {
        for (int k=j+1; k<n; k++) {
            if ( ofDist( p[j].x, p[j].y, p[k].x, p[k].y )
                < dist ) {
                ofSetColor(redFilter, greenFilter, blueFilter);
                ofLine( p[j], p[k] );
            }
        }
    }
    
    //Restore coordinate system
    ofPopMatrix();
}

void CloudAnimation::sendControlChange(ofxMidiMessage &controlMesssage) {
    
    switch (controlMesssage.control) {
            
        case 10:
            redFilter = controlMesssage.value * 2;
            break;
            
        case 74:
            greenFilter = controlMesssage.value * 2;
            break;
            
        case 71:
            blueFilter = controlMesssage.value * 2;
            break;
            
        case 76:
            volFilter = ofMap( (float)controlMesssage.value ,  0.0 , 127.0, 0.0, 1.0 );
            break;
    }

    
}

//--------------------------------------------------------------
void CloudAnimation::keyPressed(int key){
}

//--------------------------------------------------------------
void CloudAnimation::keyReleased(int key){
    
}

//--------------------------------------------------------------
void CloudAnimation::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void CloudAnimation::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void CloudAnimation::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void CloudAnimation::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void CloudAnimation::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void CloudAnimation::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void CloudAnimation::dragEvent(ofDragInfo dragInfo){
    
}