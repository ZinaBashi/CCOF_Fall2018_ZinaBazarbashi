#pragma once

#include "ofMain.h"
#include "Vehicle.hpp"
#include "VectorField.hpp"

#define TOTALNUM 50

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
   VectorField vf; //creating once instance from that class
    vector <Vehicle> objects;
};
