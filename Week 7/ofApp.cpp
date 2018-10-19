#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground (255);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    
    for (int i = 0; i < TOTALNUM; i++){
        Particles p;
        p.setup();
        particles.push_back(p);
        // adding 50 particles into the array per frame
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint wind;
    wind.set(-0.05,0);
    
    for (int i = 0 ; i< TOTALNUM ; i++){
        particles[i].applyForce(wind);
        particles[i].addGravityForce(0.08);
        particles[i].checkEdges();
        
        particles[i].update();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0 ; i< TOTALNUM ; i++){
        particles[i].draw();
    }
    
}


