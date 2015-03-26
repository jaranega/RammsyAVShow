//
//  ReactiveAnimation.h
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#ifndef __RammsyAVShow__ReactiveAnimation__
#define __RammsyAVShow__ReactiveAnimation__

#include <stdio.h>
#include "ofxMidiMessage.h"
#include "MidiConstants.h"
#include "GPUParticles.h"
#include "ImageMesh.h"
#include "CloudAnimation.h"
#include "CinematicMesh.h"
#include "RammsyMesh.h"
#include "Model3D.h"
#include "VideoController.h"
#include "VideoSporas.h"
#include "VideoSporas2.h"
#include "TriangleSphere.h"


class ReactiveAnimation {
    
public:

    void setup();
    void update(float scaledVol);
    void draw();
    
    void addAnimation(int animation);
    void removeAnimation(int animation);
    void sendControlChange(ofxMidiMessage &controlMessage);
    
    ofxMidiMessage midiMessage;
    ofxMidiMessage controlMessage;
    
    GPUParticles gpuParticles;
    ImageMesh imageMesh;
    CinematicMesh cinematic;
    RammsyMesh rammsy;
    CloudAnimation cloud;
    Model3D model;
    VideoController videoControl;
    VideoSporas videoSporas;
    VideoSporas2 videoSporas2;
    TriangleSphere sphere;
    
    
    Boolean bImageMesh = false;
    Boolean bParticles = false;
    Boolean bCloud = false;
    Boolean bModel = false;
    Boolean bCinematic = false;
    Boolean bRammsy = false;
    Boolean bVideo = false;
    Boolean bVideoSporas = false;
    Boolean bVideoSporas2 = false;
    
};

#endif /* defined(__RammsyAVShow__ReactiveAnimation__) */
