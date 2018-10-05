#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(50);
    ofEnableSmoothing();
    ofSetFrameRate(20);
    ofSetBackgroundAuto(false);
    
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofPushMatrix();
    ofTranslate(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));
    hue.setHsb(ofRandom(255), 150, 150);
    int dropNum = int(ofMap(ofRandom(1), 0, 1, 700, 1000));
    for(int i = 0; i < dropNum; i++){
        diam = pow(ofRandom(1), 20);
        //        distance = ofDistSquared(1.0 - pow(diam, 1), <#double#>), <#float y1#>, <#float x2#>, <#float y2#>)((1.0 - pow(diam, 1)) * ofRandom(1));
        distance = (1.0 - pow(diam, 1) * ofRandom(3));
        scaleddiam = ofMap(diam, 0, 1, 1, 30);
        scaleddist = ofMap(distance, 0, 1, 0, 150);
        radian = ofRandom(TWO_PI);
        ofSetColor(hue);
        ofDrawCircle(scaleddist * cos(radian), scaleddist * sin(radian), scaleddiam);
       
    } //end of for loop
    ofPopMatrix();
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


