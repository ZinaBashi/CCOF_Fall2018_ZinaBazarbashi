#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    x = 100;
    y = -50;
}

//--------------------------------------------------------------
void ofApp::update(){
    
   
    sine = sin(ofGetElapsedTimef()*2.0) * x;
    cosine = cos(ofGetElapsedTimef()*2.0) * y;
    
    x = x +0.2;
    y = y -0.2;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 64);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    ofSetColor(255);
    ofDrawCircle(sine, cosine, 50);
    ofSetCircleResolution(100);
    ofPopMatrix();
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
