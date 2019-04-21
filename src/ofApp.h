#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	struct Color {
		Color(int blue, int red, int green) : blueColor(blue), redColor(red), greenColor(green) {};
		int blueColor;
		int redColor;
		int greenColor;
	};
	Color *backgroundColor = new Color(175, 175, 175);
	
	ofSoundPlayer soundPlayer;

	int distanceThreshold = 50;
	double dotSpeed = .1;
	int animationRadius = 450;
	double currentTime = 0;

	public:
		void setup();
		void update();
		void draw();
		void drawDots();
		void updateDots();
		void linkDots();
		void drawBars();
};
