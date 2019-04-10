#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
	ofImage image;
	ofTexture texture;

	public:
		void setup();
		void update();
		void draw();
};
