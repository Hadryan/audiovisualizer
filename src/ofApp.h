#pragma once

#include "ofMain.h"

void spike();
void clearSpike();

class ofApp : public ofBaseApp{
	struct Color {
		Color(int blue, int red, int green) : blueColor(blue), redColor(red), greenColor(green) {};
		int blueColor;
		int redColor;
		int greenColor;
	};
	Color *backgroundColor = new Color(180, 180, 180);
	
	ofSoundPlayer soundPlayer;

	public:
		void setup();
		void update();
		void draw();
		void drawDots();
		void updateDots();
		void linkDots();
		void drawBars();
		void updateBars();
		float getHighestFreq();
};
