//
//  VectorField.hpp
//  Week09_VectorField
//
//  Created by Zinah Bashi on 26/10/2018.
//

#ifndef VectorField_hpp
#define VectorField_hpp

#include "ofMain.h"
//#include <stdio.h>

class VectorField{
    
public:
    void setup();
    void update();
    void draw();
    
    //nested arraylist aka 2d vector so a vector within a vector
    vector< vector <ofPoint> > field;
    
    ofPoint getForce(ofPoint _loc); 
    int cols, rows;
    int resolution;
  
    void noise(float t);
};

#endif /* VectorField_hpp */
