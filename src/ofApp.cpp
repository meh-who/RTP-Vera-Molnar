#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255, 255, 255);
    gui.setup();
    gui.add(intensity.setup("intensity", 10, 0, 100));
    gui.add(interval.setup("interval", 10, 1, 150));
    gui.add(ratio.setup("ratio", .5, -1, 1));
    gui.add(noiseScale.setup("noiseScale", .05, 0, .1));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    ofSetColor(0);
    ofNoFill();
    
    int minWidth = 20;
    int maxWidth = 600;
    int band = 20;
    for (int b = minWidth; b<=maxWidth; b+=band){
        
        //int interval = 10;
        //int intensity = 10;
        //float ratio = ofMap(b, minWidth, maxWidth, 0.5,.1);
        drawSquare(ofGetWidth()/2-b/2,ofGetHeight()/2-b/2,b,b,interval,intensity, ratio);
    }
}

//--------------------------------------------------------------
void ofApp::drawSquare(int posX, int posY, int width, int seed,int interval,int intensity, float ratio){
    ofSeedRandom(seed);
    ofBeginShape();
    float val;
    for (int i = 0; i<width; i+= interval){
        val = ofSignedNoise(ofRandom(100)*noiseScale+seed*.01)*intensity;
        if (val/intensity < ratio){
            ofVertex(posX+i,posY-val);
        }
        else{
            ofVertex(posX+i+val,posY);
        }
    }
    for (int j = 0; j<width; j+= interval){
        val = ofSignedNoise(ofRandom(100)*noiseScale+seed*.01)*intensity;
        if (val/intensity < ratio){
            ofVertex(posX+width+val,posY+j);
        }
        else{
            ofVertex(posX+width,posY+j+val);
        }
        
    }
    for (int k = width; k>0; k-= interval){
        val = ofSignedNoise(ofRandom(100)*noiseScale+seed*.01)*intensity;
        if (val/intensity < ratio){
            ofVertex(posX+k,posY+width+val);
        }
        else{
            ofVertex(posX+k+val,posY+width);
        }
    }
    for (int l = width; l>0; l-= interval){
        val = ofSignedNoise(ofRandom(100)*noiseScale+seed*.01)*intensity;
        if (val/intensity < ratio){
            ofVertex(posX-val,posY+l);
        }
        else{
            ofVertex(posX,posY+l+val);
        }
        
    }
    ofEndShape(true);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
