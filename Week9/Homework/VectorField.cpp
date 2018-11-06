//
//  VectorField.cpp
//  Week09_VectorField
//
//  Created by Zinah Bashi on 26/10/2018.
//

#include "VectorField.hpp"
#include "ofApp.h"
//--------------------------------------------------------------
void VectorField::setup(){
    resolution = 50;
    
    cols = ofGetWindowWidth() / resolution;
    rows = ofGetWindowHeight() / resolution;
    
    for (int x = 0; x < cols; x++){
        //we create a vector to push into the outer vector called field
        vector<ofPoint> column;
        column.resize(rows); // this defines the length of the column array before hand
        field.push_back(column);
        
        for (int y = 0; y < rows; y++){
            //define the forcefield to 1 pixel to the right
//            field[x][y] = ofPoint(1,0);
            
           
        }
    }
    
}

//--------------------------------------------------------------
void VectorField::update(){
    noise(ofGetElapsedTimef());
}
//--------------------------------------------------------------
void VectorField::noise(float t){
    for (int x = 0; x < field.size(); x++){
        for (int y = 0; y < field[x].size(); y++){
//            field[x][y] = ofPoint(ofGetMouseX(),ofGetMouseY());
            //noise value : 0.0 -1.0
            float noiseVal = ofNoise(x*0.05, y* 0.05, t*0.5);
            float noiseOutcome = ofMap(noiseVal, 0, 1, -TWO_PI, TWO_PI);
            
            field[x][y] = ofPoint(sin(noiseOutcome), cos(noiseOutcome));
            
        }
        
}
}
//--------------------------------------------------------------
void VectorField::draw(){
    for (int x = 0; x < field.size(); x++){
        for (int y = 0; y < field[x].size(); y++){
            
            ofPushMatrix();
            ofTranslate(x*resolution, y*resolution); //top left corner of each cell
            ofSetColor(255);
            //draw a force
            ofDrawLine(ofPoint(0,0), field[x][y]*0.5);
            // put a cirlce a the center
//            ofDrawCircle(ofPoint(0,0), 2);
            ofPopMatrix();
            
        }
    }
}

//receives a vector (presumably the location of a vehicle)
//and returns a corresponding vector field position for that location
ofPoint VectorField::getForce(ofPoint _loc){
    
    _loc.x /= resolution;
    _loc.y /= resolution;
    
    //make sure we dont look outside of the vector field.
    int x = ofClamp(_loc.x, 0, cols-1);
    int y = ofClamp(_loc.y, 0, rows-1);
    
    //return the forces of current location
    return field[x][y];
}

