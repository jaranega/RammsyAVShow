//
//  RibbonAnimation.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 21/11/14.
//
//

#include "RibbonAnimation.h"

void RibbonAnimation::setup() {
    
}


void RibbonAnimation::update() {
    /*ofVec3f sumOfAllPoints(0,0,0);
    for(unsigned int i = 0; i < points.size(); i++){
        points[i].z -= 4;
        sumOfAllPoints += points[i];
    }
    center = sumOfAllPoints / points.size();*/
    
}

void RibbonAnimation::draw() {
    
    ofPushMatrix();
    ofSetColor(color.r, color.g, color.b);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for(unsigned int i = 2; i < points.size(); i++){
        
        //find this point and the next point
        ofVec3f thisPoint = points[i-1];
        ofVec3f nextPoint = points[i];
               //get the direction from one to the next.
        //the ribbon should fan out from this direction
        ofVec3f direction = (nextPoint - thisPoint);
        
        //get the distance from one point to the next
        float distance = direction.length();
        
        //get the normalized direction. normalized vectors always have a length of one
        //and are really useful for representing directions as opposed to something with length
        ofVec3f unitDirection = direction.normalized();
        
        //find both directions to the left and to the right
        ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
        ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
        
        //use the map function to determine the distance.
        //the longer the distance, the narrower the line.
        //this makes it look a bit like brush strokes
        float thickness = ofMap(distance, 0, 60, 20, 2, true);
        
        //calculate the points to the left and to the right
        //by extending the current point in the direction of left/right by the length
        ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
        ofVec3f rightPoint = thisPoint+toTheRight*thickness;
        
        //add these points to the triangle strip
        mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
        mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
    }
    
    //end the shape
    mesh.draw();
    
    ofPopMatrix();
    

}

void RibbonAnimation::noteOn(int pitch){
    cout << "noteon tetra" << endl;
    actualPitch = pitch;
    ofVec3f mousePoint(ofMap(pitch, 48, 76, 0, ofGetWidth()),ofRandom(0, ofGetHeight()), 0);
    points.push_back(mousePoint);
    //noteson.push_back(pitch);
    
    
   
}

void RibbonAnimation::mouseMoved(int x, int y ){

}



void RibbonAnimation::noteOff(int pitch){
    
    
   /* vector<int>::iterator it = noteson.begin(); // iterator points to first elemen
    for(; it != noteson.end();){
        
        if( *it == pitch ) it = noteson.erase(it); // be sure to return the iterator when erasing so it is not invalidated
        else ++it;
        
        noteson.pop_back();
    }*/
    
}

void RibbonAnimation::changeColor(int r, int g, int b){
    cout << "color " << color.r << " " << color.g << " " << color.b << endl;
    color = ofColor(r,g,b);
}

void RibbonAnimation::restart(){
    points.clear();
    mesh.clearIndices();
    mesh.clearVertices();

}