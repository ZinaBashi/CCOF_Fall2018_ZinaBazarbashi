#pragma once

#include "ofMain.h"

#include "ofMain.h"
#include "Particles.hpp"

#define TOTALNUM 1000

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    vector <Particles> particles;
};
