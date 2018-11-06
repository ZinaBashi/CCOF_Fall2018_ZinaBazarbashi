#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofSetCircleResolution(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    vf.setup();
    for (int i=0; i<TOTALNUM; i++){
        Vehicle v;
        v.setup(ofRandomWidth(), ofRandomWidth());
        objects.push_back(v);
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    vf.update();
    
    for (int i=0; i<objects.size(); i++){
        objects[i].follow(vf);
        objects[i].update();
        objects[i].checkEdges();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    vf.draw();
    
    for (int i=0; i<objects.size(); i++){
        objects[i].draw();
    }
}
