#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);

    float diam;
    float distance;
    float scaleddiam;
    float scaleddist;
    float radian;
    ofColor hue;
    
};
