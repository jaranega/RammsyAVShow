#include "VideoController.h"

//--------------------------------------------------------------
void VideoController::setup(){
     video.loadMovie( "meanwhile.mp4" );
    //video.play();
    
    //Fill the table by random values from 0 to 255
    for ( int i=0; i<24; i++ ) {
        table[i] = ofRandom( 0, 255 );
    }
}

void VideoController::init(){
   
    video.setFrame(0);
    video.play();
}

void VideoController::stop(){
    video.stop();
}

//--------------------------------------------------------------
void VideoController::update(float scaledVol){
    
    video.update();		//Decode the new frame if needed
    
    //Do computing only if a new frame was obtained
    if ( video.isFrameNew() ) {
        
        //Getting pixels
        ofPixels pixels = video.getPixelsRef();
        
        //Scan all the pixels
        for (int y=0; y<pixels.getHeight(); y++) {
            for (int x=0; x<pixels.getWidth(); x++) {
                
                //Getting pixel (x,y) color
                ofColor col = pixels.getColor( x, y );
                
                //cout << scaledVol << " < " << volFilter << endl;
                if (scaledVol > volFilter)
                {
                    if (col.r < redFilter) col.r = table[ col.r/24 ];
                    if (col.g < greenFilter) col.g = table[ col.g/24 ];
                    if (col.b < blueFilter) col.b = table[ col.b/24 ];
                }
                
                //Set the color back to the pixel (x,y)
                pixels.setColor( x, y, col );
                
            }
        }
        
        //Set pixel array to the image
        image.setFromPixels( pixels );
    }
}

//--------------------------------------------------------------
void VideoController::draw(){
    ofPushMatrix();
    //ofTranslate(-ofGetWidth()/2 , -ofGetHeight()/2 );
    image.width = ofGetWidth();
    image.height = ofGetHeight();
    image.draw(0,0);
    ofPopMatrix();
}

void VideoController::sendControlChange(ofxMidiMessage &controlMesssage) {
    
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

            break;
    }

    
}

