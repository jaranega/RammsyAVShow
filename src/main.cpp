#include "ofMain.h"
#include "ofApp.h"
#include "ofxMultiGLFWWindow.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    
    /*ofAppGLFWWindow window;
    window.setMultiDisplayFullscreen(true);
    ofSetupOpenGL(&window, 1920, 1080, OF_FULLSCREEN);
    ofSetWindowPosition(0, 0);*/
    
    
    /*ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
    ofxMultiGLFWWindow glfw;
    glfw.setOpenGLVersion(4,0);
    glfw.windowCount = 2;
    ofSetupOpenGL(&glfw,1024,768,OF_WINDOW);*/
    
    ofAppGLFWWindow window;
    window.setMultiDisplayFullscreen(false);
    ofSetupOpenGL(&window, 800, 600, OF_WINDOW);
    ofSetWindowPosition(0, 0);
    ofRunApp(new ofApp());

}
