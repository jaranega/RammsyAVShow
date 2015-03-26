//
//  ImageMesh.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 21/11/14.
//
//

#include "ImageMesh.h"

//--------------------------------------------------------------
void ImageMesh::setup(){
    
    image.loadImage("spitzer.jpg");
    image.resize(200, 200);
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    float intensityThreshold = 100;
    
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c =  image.getColor(x, y);
            float intensity = c.getBrightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(4*x, 4*y, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                
                // These will allow us to move the x, y and z coordinates of each vertex independently
                offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
            }
        }
    }
    
    float connectionDistance = 10.0;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }

    //ORBITING
    meshCentroid = mesh.getCentroid();
    
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        float distance = vert.distance(meshCentroid);
        float angle = atan2(vert.y-meshCentroid.y, vert.x-meshCentroid.x);
        distances.push_back(distance);
        angles.push_back(angle);
    }
    
    orbiting = false;
    startOrbitTime = 0.0;
    meshCopy = mesh;
}

//--------------------------------------------------------------
void ImageMesh::update(float scaledVol){
    
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        
        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        float displacementScale = scaledVol*5;
        ofVec3f timeOffsets = offsets[i];
        
        // A typical design pattern for using Perlin noise uses a couple parameters:
        // ofSignedNoise(time*timeScale+timeOffset)*displacementScale
        //     ofSignedNoise(time) gives us noise values that change smoothly over time
        //     ofSignedNoise(time*timeScale) allows us to control the smoothness of our noise (smaller timeScale, smoother values)
        //     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise function to control multiple things and have them look as if they are moving independently
        //     ofSignedNoise(time)*displacementScale allows us to change the bounds of the noise from [-1, 1] to whatever we want
        // Combine all of those parameters together, and you've got some nice control over your noise
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert);
    }
    
    if (orbiting) {
        int numVerts = mesh.getNumVertices();
        for (int i=0; i<numVerts; ++i) {
            ofVec3f vert = mesh.getVertex(i);
            float distance = distances[i];
            float angle = angles[i];
            float elapsedTime = ofGetElapsedTimef() - startOrbitTime;
            
            // Lets adjust the speed of the orbits such that things that are closer to
            // the center rotate faster than things that are more distant
            float speed = ofMap(distance, 0, 200, 1, 0.25, true);
            
            // To find the angular rotation of our vertex, we use the current time and
            // the starting angular rotation
            float rotatedAngle = elapsedTime * speed + angle;
            
            // Remember that our distances are calculated relative to the centroid of the mesh, so
            // we need to shift everything back to screen coordinates by adding the x and y of the centroid
            vert.x = distance * cos(rotatedAngle) + meshCentroid.x;
            vert.y = distance * sin(rotatedAngle) + meshCentroid.y;
            
            mesh.setVertex(i, vert);
        }
    }
    
}

//--------------------------------------------------------------
void ImageMesh::draw(){
    
    
    //ofColor centerColor = ofColor(85, 78, 68);
    //ofColor edgeColor(0, 0, 0);
    //ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    easyCam.begin();
    ofPushMatrix();
        //ofVec3f centroid = mesh.getCentroid();
        //ofTranslate(ofGetWidth()/2 - centroid.x, ofGetHeight()/2 - centroid.y);
        ofTranslate(-ofGetWidth()/2 , -ofGetHeight()/2 );
        mesh.draw();
    ofPopMatrix();
    easyCam.end();
    
}

void ImageMesh::sendControlChange(ofxMidiMessage &controlMesssage) {
    
    cout << "CC " << controlMesssage.control << " " << controlMesssage.value << endl;
    
    //switch (controlMesssage.control) {  }
    
}

//--------------------------------------------------------------
void ImageMesh::keyPressed(int key){

    if (key == 'o') {
        orbiting = !orbiting;
        startOrbitTime = ofGetElapsedTimef();
        mesh = meshCopy;
    }
}

//--------------------------------------------------------------
void ImageMesh::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ImageMesh::mouseMoved(int x, int y ){
    
}

void ImageMesh::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ImageMesh::mousePressed(int x, int y, int button){
    
}


//--------------------------------------------------------------
void ImageMesh::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ImageMesh::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ImageMesh::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ImageMesh::dragEvent(ofDragInfo dragInfo){
    
}
