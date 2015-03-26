//
//  GPUParticles.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 18/11/14.
//
//

#ifndef __RammsyAVShow__GPUParticles__
#define __RammsyAVShow__GPUParticles__

#include <stdio.h>
#include "ofxGpuParticles.h"
#include "ofxMidiMessage.h"

class GPUParticles {
public:
    void setup();
    void update();
    void draw();
    
    void sendControlChange(ofxMidiMessage &controlMessage);
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    // set any update uniforms in this function
    void onParticlesUpdate(ofShader& shader);
    ofxGpuParticles particles;
};


#endif /* defined(__RammsyAVShow__GPUParticles__) */
