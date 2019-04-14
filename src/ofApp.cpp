#include "ofApp.h"

const int numberOfDots = 300;
const int numberOfBars = 300;
ofVec2f dots[numberOfDots];
vector<bool> isConnected(numberOfDots, false);
vector<double> yOffset(numberOfDots), xOffset(numberOfDots);
float soundSpectrum[numberOfBars];



void ofApp::setup() {
	soundPlayer.loadSound("..//..//audio//audioBeats.wav");
	soundPlayer.play();
	for (int i = 0; i < numberOfDots; i++) {
		xOffset[i] = ofRandom(0, 1000);
		yOffset[i] = ofRandom(0, 1000);
	
	}

	for (int i = 0; i < numberOfBars; i++) {
		soundSpectrum[i] = 0.0f;
	}
}

void ofApp::update(){
	ofSoundUpdate();
	float *value = ofSoundGetSpectrum(numberOfBars);
	updateDots();
	for (int i = 0; i < numberOfBars; i++) {
		soundSpectrum[i] *= .97;
		soundSpectrum[i] = max(soundSpectrum[i], value[i]);
	}
}

void ofApp::draw(){
	ofBackground(backgroundColor->blueColor, backgroundColor->redColor, backgroundColor->greenColor);
	drawDots();

}

//Setup, Update, and Draw Dots for foreground animation of the Audio Visualizer
void ofApp::drawDots() {
	//Centers the dots within the animation 
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//Choose the color of the dots and create circles at those dots
	for (int i = 0; i < numberOfDots; i++) {
		if (isConnected[i]) {
			ofDrawCircle(dots[i].x, dots[i].y, 2);
		}
	}
	linkDots();
	ofPopMatrix();
}

//Link dots when they are a specific distance from one another
void ofApp::linkDots() {
	for (int i = 0; i < numberOfDots; i++) {
		isConnected[i] = false;
		for (int j = i + 1; j < numberOfDots; j++) {
			double distance = ofDist(dots[i].x, dots[i].y, dots[j].x, dots[j].y);
			if (distance < distanceThreshold) {
				isConnected[i] = true;
				ofDrawLine(dots[i], dots[j]);
			}
		}
	}
}

void ofApp::updateDots() {
	double timeElapsed = ofGetElapsedTimef();
	//The difference in time since the previous update occured
	double timeDifference = timeElapsed - currentTime;
	currentTime = timeElapsed;
	for (int i = 0; i < numberOfDots; i++) {
		//Retieve the total moved distance by the dots
		yOffset[i] += dotSpeed * timeDifference;
		xOffset[i] += dotSpeed * timeDifference;
		//Update the coordinates of each dot with Perlin Noise 
		dots[i].x = ofSignedNoise(xOffset[i]) * animationRadius;
		dots[i].y = ofSignedNoise(yOffset[i]) * animationRadius;
	}
}






