//
//  ReactiveAnimation.cpp
//  RammsyAVShow
//
//  Created by Aranega, Javier (BCN-LOH) on 20/11/14.
//
//

#include "ReactiveAnimation.h"

void ReactiveAnimation::setup(){
    gpuParticles.setup();
    imageMesh.setup();
    rammsy.setup();
    cloud.setup();
    model.setup();
    cinematic.setup();
    videoControl.setup();
    videoSporas.setup();
    sphere.setup();
    
}

void ReactiveAnimation::update(float scaledVol){
   if (bImageMesh)
        imageMesh.update(scaledVol);
   
   if (bParticles)
       gpuParticles.update();

    if (bCloud)
       cloud.update(scaledVol);
    
    if (bModel)
        model.update();
    
    if (bCinematic)
        cinematic.update();
    
    if (bRammsy)
        sphere.update(scaledVol);
        //rammsy.update();
    
    if (bVideo)
        videoControl.update(scaledVol);
    
    if (bVideoSporas)
        videoSporas.update(scaledVol);
    
    if (bVideoSporas2)
        videoSporas2.update(scaledVol);

}

void ReactiveAnimation::draw(){
    if (bParticles)
        gpuParticles.draw();
    
    if (bImageMesh)
        imageMesh.draw();
    
    if (bCloud)
        cloud.draw();
    
    if (bModel)
        model.draw();
    
    if (bCinematic)
        cinematic.draw();
    
    if (bRammsy)
        sphere.draw();
        //rammsy.draw();
    
    if (bVideo)
        videoControl.draw();
    
    if (bVideoSporas)
        videoSporas.draw();
    
    if (bVideoSporas2)
        videoSporas2.draw();

}


void ReactiveAnimation::addAnimation(int animation) {
   
    switch (animation)
    {
        case 1:
            bImageMesh = true;
            break;
        case 2:
            bParticles = true;
            break;
        case 3:
            bCloud = true;
            break;
        case 4:
            bModel = true;
            break;
        case 5:
            bCinematic = true;
            break;
        case 6:
            sphere.restart();
            bRammsy = true;
            break;
        case 7:
            videoControl.init();
            bVideo = true;
            break;
        
        case 8:
            videoSporas.init();
            bVideoSporas = true;
            break;

        case 9:
            videoSporas2.init();
            bVideoSporas2 = true;
            break;

    }
}

void ReactiveAnimation::removeAnimation(int animation) {
    
    switch (animation)
    {
        case 1:
            bImageMesh = false;
            break;
        case 2:
            bParticles = false;
            break;
        case 3:
            bCloud = false;
            break;
        case 4:
            bModel = false;
            break;
        case 5:
            bCinematic = false;
            break;
        case 6:
            bRammsy = false;
            break;
        case 7:
            videoControl.stop();
            bVideo = false;
            break;
        case 8:
            videoSporas.stop();
            bVideoSporas = false;
            break;
        case 9:
            videoSporas2.stop();
            bVideoSporas2 = false;
            break;
        


    }
}
    
void ReactiveAnimation::sendControlChange(ofxMidiMessage &controlMessage) {
        
        this->controlMessage = controlMessage;
        cout << controlMessage.control << endl;;

        gpuParticles.sendControlChange(controlMessage);
        imageMesh.sendControlChange(controlMessage);
        rammsy.sendControlChange(controlMessage);
        cloud.sendControlChange(controlMessage);
        model.sendControlChange(controlMessage);
        cinematic.sendControlChange(controlMessage);
        videoControl.sendControlChange(controlMessage);
        videoSporas.sendControlChange(controlMessage);
        videoSporas2.sendControlChange(controlMessage);
        sphere.sendControlChange(controlMessage);
    
}



