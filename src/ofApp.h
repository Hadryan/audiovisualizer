#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	struct Color {
		Color(int purple, int white, int pink) : purpleColor(purple), whiteColor(white), pinkColor(pink) {};
		int purpleColor;
		int whiteColor;
		int pinkColor;
	};
	Color *backgroundColor = new Color(175, 175, 175);
	Color *dotColor = new Color(0, 0, 0);

	int distanceThreshold = 50;
	double dotSpeed = .05;
	int animationRadius = 500;
	double currentTime = 0;

	public:
		void setup();
		void update();
		void draw();
		void drawDots();
		void updateDots();
		void linkDots();
};
