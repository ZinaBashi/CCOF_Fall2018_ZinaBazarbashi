//
//  Particles.cpp
//  Week7_HW_Waves
//
//  Created by Zinah Bashi on 19/10/2018.
//

#include "Particles.hpp"

//--------------------------------------------------------------
void Particles::setup(){
    
    mass = ofRandom(0.2,0.5);
    location.set(ofGetWidth()*2, ofRandomHeight()+50);
    vel.set(0,0);
    acc.set(0,0);
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
// THIS IS IMPORTANT! it is the basic equation of to the positioning on the particles

void Particles::applyForce(ofPoint _f){
    acc += _f/mass;
    
}
//--------------------------------------------------------------
//--------------------------------------------------------------
void Particles::addGravityForce(float _g){
    
    ofPoint gravity;
    gravity.set(0, _g*mass);
    
    applyForce(gravity);
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//this adds the counter force of water
void Particles::addUpwardForce(float _u){
    float speed = vel.length();
    float dragMagnitude = _u * speed * speed;
    ofPoint dragDirection = vel;
    dragDirection *= ofRandom(0,-5);
    dragDirection.normalize();

    ofPoint dragForce = dragMagnitude * dragDirection;

    applyForce(dragForce);

}
//--------------------------------------------------------------
//--------------------------------------------------------------
void Particles::checkEdges(){
    if (location.x > ofGetWindowWidth()){
        location.x = ofGetWindowWidth();
        vel.x *= ofRandom(-0.2,-0.5); //bounce back
    }
    else if (location.x <0){
        location.x = 0;
        vel.x *= ofRandom(-0.2,-0.5);
        
    }
    
    if (location.y >ofGetWindowHeight()) {
        location.y = ofGetWindowHeight();
        vel.y *= ofRandom(-0.2,-0.5);
    }
    
}


//--------------------------------------------------------------
//--------------------------------------------------------------
void Particles::update(){
    vel += acc;
    location += vel;
    
    acc.set(0,0);
}

//--------------------------------------------------------------
//--------------------------------------------------------------
void Particles::draw(){
    
    ofSetColor(0, 200);
    ofDrawCircle(location.x, location.y, mass*8);
    //radius of the circle is defined by the mass * 30
}

