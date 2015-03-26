//
//  TriangleSphere.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 06/03/15.
//
//

#include "TriangleSphere.h"
#include "ofApp.h"



//--------------------------------------------------------------
void TriangleSphere::setup() {
    nTri = 1500;			//The number of the triangles
    nVert= nTri * 3;		//The number of the vertices
    
    float Rad = 250;	//The sphere's radius
    float rad = 25;		//Maximal triangle's ìradiusî
    //(formally, it's the maximal coordinates'
    //deviation from the triangle's center)
    
    //Fill the vertices array
    vertices.resize( nVert );		//Set the array size
    for (int i=0; i<nTri; i++) {	//Scan all the triangles
        //Generate the center of the triangle
        //as a random point on the sphere
        
        //Take the random point from
        //cube [-1,1]x[-1,1]x[-1,1]
        ofPoint center( ofRandom( -1, 1 ),
                       ofRandom( -1, 1 ),
                       ofRandom( -1, 1 ) );
        center.normalize();		//Normalize vector's length to 1
        center *= Rad;			//Now the center vector has length Rad
        
        //Generate the triangle's vertices
        //as the center plus random point from
        //[-rad, rad]x[-rad, rad]x[-rad, rad]
        for (int j=0; j<3; j++) {
            vertices[ i*3 + j ] =
            center + ofPoint( ofRandom( -rad, rad ),
                             ofRandom( -rad, rad ),
                             ofRandom( -rad, rad ) );
        }
    }
    
    //Fill the array of triangles' colors
    colors.resize( nTri );
    for (int i=0; i<nTri; i++) {
        //Take a random color from black to red
        colors[i] = ofColor( ofRandom( 0, 255 ), ofRandom(0, 255), ofRandom(0, 255));
    }
    
    //Load shader
    shader.load( "shaderTriangleVert.c", "shaderTriangleFrag.c" );
}

//--------------------------------------------------------------

void TriangleSphere::update(float scaledVol){
    //Compute dt
    float time = ofGetElapsedTimef();
    float dt = ofClamp( time - time1, 0, 0.2 );
    time1 = time;
    float speed = ofMap( scaledVol*100, 0, 100, 0, 5 );
    phase += speed * dt;
    distortAmount = ofMap( scaledVol*50 , 0, 100, 0, 1.0 );
    
    if (scaledVol > volFilter) {
        if (numNotes<nTri) numNotes++;
        //else numNotes = 0;
    }
}

//--------------------------------------------------------------
void TriangleSphere::draw(){
   

    ofEnableDepthTest();				//Enable z-buffering
    ofPushMatrix();	//Store the coordinate system
    
    //Move the coordinate center to screen's center
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
    
    //Calculate the rotation angle
    float time = ofGetElapsedTimef();	//Get time in seconds
    float angle = time * 15;			//Compute angle. We rotate at speed 10 degrees per second
    ofRotate( angle, 0, 1, 0 );			//Rotate the coordinate system along y-axe
    
    //Enable the shader
    shader.begin();
    shader.setUniform1f( "phase", phase );
    shader.setUniform1f( "distortAmount", distortAmount );
    
    //Draw the triangles
    for (int i=0; i<numNotes; i++) {
        //ofSetColor(colors[i] );	//Set color

        ofColor c;
        
        if (colors[i].r > redFilter) c.r = colors[i].r;
            else c.r = 0;
        
        if (colors[i].g > greenFilter) c.g = colors[i].g;
            else c.g = 0;
        
        if (colors[i].b > blueFilter) c.b = colors[i].b;
            else c.b = 0;
        
        ofSetColor(c);
        
        ofTriangle( vertices[ i*3 ],
                   vertices[ i*3 + 1 ],
                   vertices[ i*3 + 2 ] ); //Draw triangle
    }
    
    shader.end();	//Disable the shader
    ofPopMatrix();	//Restore the coordinate system
}

void TriangleSphere::sendControlChange(ofxMidiMessage &controlMesssage) {
    
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
            cout << volFilter << endl;
            break;
    }
}

void TriangleSphere::restart()
{
    numNotes = 0;
}

