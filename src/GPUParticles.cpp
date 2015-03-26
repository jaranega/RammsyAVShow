//
//  GPUParticles.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 18/11/14.
//
//

#include "GPUParticles.h"


//--------------------------------------------------------------
void GPUParticles::setup()
{
        // 1,000,000 particles
    unsigned w = 1000;
    unsigned h = 1000;
    
    particles.init(w, h);
    
    // initial positions
    // use new to allocate 4,000,000 floats on the heap rather than
    // the stack
    float* particlePosns = new float[w * h * 4];
    for (unsigned y = 0; y < h; ++y)
    {
        for (unsigned x = 0; x < w; ++x)
        {
            unsigned idx = y * w + x;
            particlePosns[idx * 4] = ofRandom(ofGetWidth()) * x / (float)w - ofRandom(ofGetHeight()); //.f; // particle x
            particlePosns[idx * 4 + 1] = ofRandom(ofGetWidth()) * y / (float)h - ofRandom(ofGetHeight()); // particle y
            particlePosns[idx * 4 + 2] =  ofRandom (100.f); // particle z
            particlePosns[idx * 4 + 3] = 0.f; // dummy
        }
    }
    particles.loadDataTexture(ofxGpuParticles::POSITION, particlePosns);
    delete[] particlePosns;
    
    // initial velocities
    particles.zeroDataTexture(ofxGpuParticles::VELOCITY);
    
    // listen for update event to set additonal update uniforms
    ofAddListener(particles.updateEvent, this, &GPUParticles::onParticlesUpdate);
}

//--------------------------------------------------------------
void GPUParticles::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
    particles.update();
}

// set any update uniforms in this function
void GPUParticles::onParticlesUpdate(ofShader& shader)
{
    ofVec3f mouse(ofGetMouseX() - .5f * ofGetWidth(), .5f * ofGetHeight() - ofGetMouseY() , 0.f);
    shader.setUniform3fv("mouse", mouse.getPtr());
    shader.setUniform1f("elapsed", ofGetLastFrameTime());
    shader.setUniform1f("radiusSquared", 100.f * 100.f);
}

//--------------------------------------------------------------
void GPUParticles::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    particles.draw();
    ofDisableBlendMode();
}

void GPUParticles::sendControlChange(ofxMidiMessage &controlMesssage) {
    
    cout << "CC " << controlMesssage.control << " " << controlMesssage.value << endl;
    
    //switch (controlMesssage.control) {  }

}

//--------------------------------------------------------------
void GPUParticles::keyPressed(int key){
    
}

//--------------------------------------------------------------
void GPUParticles::keyReleased(int key){
    
}

//--------------------------------------------------------------
void GPUParticles::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void GPUParticles::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GPUParticles::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GPUParticles::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void GPUParticles::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void GPUParticles::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void GPUParticles::dragEvent(ofDragInfo dragInfo){
    
}