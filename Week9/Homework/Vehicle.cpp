//
//  Vehicle.cpp
//  00-Seek
//
//  Created by Qinzi Tan on 10/18/18.
//

#include "Vehicle.hpp"
//--------------------------------------------------------------
void Vehicle::setup(float _x, float _y){
    loc.set(_x, _y);
    vel.set(0, 0);
    acc.set(0, 0);
    
    r = 2;
    maxSpeed = ofRandom(2,4);
    maxForce = 0.05;
}

//--------------------------------------------------------------
void Vehicle::update(){
    vel += acc;
    vel.limit(maxSpeed);
    loc += vel;
    
    acc *= 0;
}

//--------------------------------------------------------------
void Vehicle::draw(){
    
    float angle = (float)atan2(vel.y, vel.x);
    float heading2D = ofRadToDeg(angle)+90;
    float t = ofGetElapsedTimef();
    ofColor c;
    c.setHsb((ofNoise(t)*360), 200, 225);
    cout << c << endl;
    ofEnableAlphaBlending();
    ofSetColor(c);
    ofFill();
    ofPushMatrix();
    ofTranslate(loc.x, loc.y);
    ofRotateZDeg(heading2D);
    ofDrawCircle(0,0,5,5);
    ofPopMatrix();
    ofDisableAlphaBlending();
    
    if (loc.x < 0 || loc.x >ofGetWindowWidth()){
        
    }
}

//--------------------------------------------------------------
void Vehicle::applyForce(ofPoint force){
    acc += force;
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void Vehicle::follow(VectorField vf){
    ofPoint desired = vf.getForce(loc);
    desired *= maxSpeed;
    
    ofPoint steer = desired - vel;
    steer.limit(maxForce);
    applyForce(steer);
    
}

void Vehicle::checkEdges(){
    if (loc.x > ofGetWindowWidth()){
        loc.x = ofGetWindowWidth();
        vel.x *= -0.9; //bounce back
    }
    else if (loc.x <0){
       loc.x = 0;
        vel.x *= -0.9;
        
    }
    
    if (loc.y >ofGetWindowHeight()) {
        loc.y = ofGetWindowHeight();
        vel.y *= -1.5;
    } else if
        (loc.y < 0) {
            loc.y = 0;
            vel.y *= -1.5;
        }
    
    
    
}
