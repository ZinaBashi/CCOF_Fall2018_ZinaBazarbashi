#include "ofApp.h"
// THIS HOMEWORK HAS GUI & TRIGONOMETRY
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    ofSetBackgroundAuto(false);
    
    
    gui.setup();
    gui.add(circlerad.setup("radius", 3, 3, 100));
    gui.add(resolution.setup("Resolution", 100, 1, 300));
    gui.add(time.setup("speed", 5, 3, 10));
    gui.add(toggle.setup("toggle", true));
    gui.add(button.setup("button"));
    gui.add(color.setup("color" ,100,100,130));
    

}

//--------------------------------------------------------------
void ofApp::update(){
 
    
    float t = ofGetElapsedTimef()*time;
    
//    radius += (sin(t)*cos(t))*30;
    radius += (cos(sin(t*3))*sin(t*0.5))*4;
    
    pos.x = ofGetWindowWidth()/2 + sin(angle) * radius;
    pos.y = ofGetWindowHeight()/2 + cos(angle)* radius;
    
    angle +=  ofDegToRad(0.5);
    
    radiuss += cos(t) * sin(t);
    
    if (toggle == false) {
        ofBackground(0, 0, 0);
        radius= radiuss;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

//    ofSetColor(0, 64);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
//
    if (toggle == true) {
    ofSetColor(color, 40);
    ofDrawCircle(pos, circlerad);
    ofSetCircleResolution(resolution);
        gui.draw();}
    
    else {
        ofSetColor(color, 40);
        ofDrawCircle(pos, circlerad);
        ofSetCircleResolution(resolution);
        
        gui.draw();
        
    }
    
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
