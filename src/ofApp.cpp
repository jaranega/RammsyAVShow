#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetCoordHandedness(OF_RIGHT_HANDED);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
	//ofSetLogLevel(OF_LOG_VERBOSE);
    ofHideCursor();
    

    // Setup post-processing chain
    postReactive.init(ofGetWidth(), ofGetHeight());
    postReactive.createPass<FxaaPass>()->setEnabled(false);
    postReactive.createPass<BloomPass>()->setEnabled(false);
    postReactive.createPass<DofPass>()->setEnabled(false);
    postReactive.createPass<KaleidoscopePass>()->setEnabled(false);
    postReactive.createPass<NoiseWarpPass>()->setEnabled(false);
    postReactive.createPass<PixelatePass>()->setEnabled(false);
    postReactive.createPass<EdgePass>()->setEnabled(false);
    postReactive.createPass<ZoomBlurPass>()->setEnabled(false);
    postReactive.createPass<RGBShiftPass>()->setEnabled(false);
    
    // Setup post-processing chain
    postMidi.init(ofGetWidth(), ofGetHeight());
    postMidi.createPass<FxaaPass>()->setEnabled(false);
    postMidi.createPass<BloomPass>()->setEnabled(false);
    postMidi.createPass<DofPass>()->setEnabled(false);
    postMidi.createPass<KaleidoscopePass>()->setEnabled(false);
    postMidi.createPass<NoiseWarpPass>()->setEnabled(false);
    postMidi.createPass<PixelatePass>()->setEnabled(false);
    postMidi.createPass<EdgePass>()->setEnabled(false);
    postMidi.createPass<ZoomBlurPass>()->setEnabled(false);
    postMidi.createPass<RGBShiftPass>()->setEnabled(false);
    
    
    //SETUP MIDI IN & MIDI CONTROL
    
    liveMidi.setup(midiAnimation);
    
    controlMidi.setup();
    controlMidiListener.setup(liveMidi, postMidi, postReactive, reactiveAnimation);  //Aqui tenemos que pasar todas las clases que ncesiten cambiar con el controlador midi
    controlMidi.midiIn.addListener(&controlMidiListener);
    
    reactiveAnimation.setup();
    midiAnimation.setup();
    
    // AUDIO IN
    
    //soundStream.listDevices();
    
    //if you want to set a different device id
    //soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
        //AUDIO IN
        //lets scale the vol up to a 0-1 range
        scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
        //lets record the volume into an array
        volHistory.push_back( scaledVol );
    
        //if we are bigger the size we want to record - lets drop the oldest value
        if( volHistory.size() >= 400 ){
            volHistory.erase(volHistory.begin(), volHistory.begin()+1);
        }
    
        reactiveAnimation.update(scaledVol);
        midiAnimation.update();


}

//--------------------------------------------------------------
void ofApp::draw(){
   postReactive.begin();
        if(bDrawMidi)
             midiAnimation.draw();
        reactiveAnimation.draw();
   postReactive.end();
    
    //postReactive.begin();
    //if (!bDrawMidi)
    //    midiAnimation.draw();
    //postReactive.end();
    
    //ofSetColor(225);
    //string reportString = "buffers received: "+ofToString(bufferCounter)+"\nvolume: "+ofToString(scaledVol)+"\nticks: " + ofToString(soundStream.getTickCount());
    //ofDrawBitmapString(reportString, 32, 589);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'f')
        ofToggleFullscreen();
    
    if (key == 'm')
        bDrawMidi = !bDrawMidi;
    
    if (key == 'p')
        bDrawParticles = !bDrawParticles;
    
    if( key == 's' ){
        soundStream.start();
    }
    
    if( key == 'e' ){
        soundStream.stop();
    }

    
    unsigned idx = key - '0';
    unsigned idxMidi = key - '0';
    
    if (idx < postReactive.size()) postReactive[idx]->setEnabled(!postReactive[idx]->getEnabled());
    //if (idx < postMidi.size()) postMidi[idx]->setEnabled(!postMidi[idx]->getEnabled());
     
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
