#pragma once

#include "ofMain.h"

#include "LiveMidiManager.h"
#include "ControlMidiManager.h"
#include "ControlMidiListener.h"

#include "ofxPostProcessing.h"

#include "GPUParticles.h"
#include "MidiNotesAnimation.h"
#include "ReactiveAnimation.h"

#include "ofxMultiGLFWWindow.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void audioIn(float * input, int bufferSize, int nChannels);
    
        //MIDI
        LiveMidiManager liveMidi;
        ControlMidiManager controlMidi;
        ControlMidiListener controlMidiListener;
    
        //ANIMATION
    
        //GPUParticles particles;
        MidiNotesAnimation midiAnimation;
        ReactiveAnimation reactiveAnimation;
    
        //EFFECTS
        ofxPostProcessing postReactive;
        ofxPostProcessing postMidi;
    
        ofEasyCam cam;
        ofLight light;
    
        //BOOLEANS
        Boolean bDrawMidi = true;
        Boolean bDrawParticles = false;
    
        //SCREENS
        ofxMultiGLFWWindow *glfw;
        int wIndex;
        vector<GLFWwindow*> *windows;
    
        //AUDIO IN
        vector <float> left;
        vector <float> right;
        vector <float> volHistory;
    
        int 	bufferCounter;
        int 	drawCounter;
    
        float smoothedVol;
        float scaledVol;
    
        ofSoundStream soundStream;

		
};
