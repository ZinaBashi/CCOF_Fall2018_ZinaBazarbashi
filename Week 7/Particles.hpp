//
//  Particles.hpp
//  Week7_HW_Waves
//
//  Created by Zinah Bashi on 19/10/2018.
//


#ifndef Particles_hpp
#define Particles_hpp
#include "ofMain.h"


class Particles{
    
public:
    void setup();
    void update();
    void draw();
    
    void applyForce(ofPoint _f);
    void checkEdges();
    void addGravityForce(float _g);
    void addUpwardForce(float _u);
    
    ofPoint location;
    ofPoint vel;
    ofPoint acc;
    
    float mass;
    
    
};


#endif /* Particle_hpp */
