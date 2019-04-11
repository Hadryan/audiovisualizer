#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	int  blueBackGround = 175;
	int redBackground = 175;
	int greenBackground = 175;
	int blueDot = 0;
	int redDot = 0;
	int greenDot = 0;

	private:
	ofImage image;
	ofTexture texture;

	public:
		void setup();
		void update();
		void draw();
		void dotCoordinateSetUp();
		void drawDots();
};
