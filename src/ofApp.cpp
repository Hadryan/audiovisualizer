#include "ofApp.h"


const int numberOfDots = 450;
const int numberOfBars = 400;
const int maxColorValue = 255;
const int barWidth = 10;
const int maxBarHeight = 300;
const int minBarHeight = 25;
//Two dimensional vector-like structure to hold dots and their x,y coordinates
ofVec2f dots[numberOfDots];
float dotRadius = 3;
float lineWidth = 2;
float speedMultiplier = 1.1;
int distanceThreshold = 50;
double dotSpeed = .1;
int animationRadius = 550;
double currentTime = 0;
vector<int> xPositionOfBars(numberOfBars);
vector<bool> isConnected(numberOfDots, false);
//Vector that determines the offset of the x,y coordindates of each dot to ensure they remain centered and on screen
vector<double> yOffset(numberOfDots), xOffset(numberOfDots);
float soundSpectrum[numberOfBars];
bool maxBarHeightReached = false;
int backColor = 200;
float soundSpectrumSmoothnessVal = .93;




void ofApp::setup() {
	backgroundImage.load("C:\\Users\\simde\\source\\repos\\of_v0.10.1_vs2017_release\\apps\\myApps\\finalProject - sdesai51\\bin\\data\\sunset.jpg`");
	soundPlayer.loadSound("..//..//audio//audioBeats.wav");
	soundPlayer.play();
	for (int i = 0; i < numberOfDots; i++) {
		xOffset[i] = ofRandom(0, 1000);
		yOffset[i] = ofRandom(0, 1000);
	
	}
	for (int i = 0; i < numberOfBars; i++) {
		soundSpectrum[i] = 0;
		xPositionOfBars[i] = (barWidth + 1) * i;
	}
}

void ofApp::update(){
	ofSoundUpdate();
	updateDots();
	updateBars();
}

void ofApp::draw(){
	if (maxBarHeightReached && backColor <= maxColorValue) {
		backColor++;
	}
	else if (backColor >= 100) {
		backColor--;
	}
	ofSetColor(backColor);
	backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
	drawBars();
	drawDots();

}

//Setup, Update, and Draw Dots for foreground animation of the Audio Visualizer
void ofApp::drawDots() {
	if (maxBarHeightReached) {
		bassSpike();
	} else {
		clearBassSpike();
	}
	//Centers the dots within the animation 
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//Choose the color of the dots and create circles at those dots
	for (int i = 0; i < numberOfDots; i++) {
		if (isConnected[i]) {
			ofDrawCircle(dots[i].x, dots[i].y, dotRadius);
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
				ofSetLineWidth(lineWidth);
				ofDrawLine(dots[i], dots[j]);
			}
		}
	}
}

//Updates the positioning of the dots on the screen
void ofApp::updateDots() {
	double timeElapsed = ofGetElapsedTimef();
	//The difference in time since the last update happened
	double timeDifference = timeElapsed - currentTime;
	currentTime = timeElapsed;
	for (int i = 0; i < numberOfDots; i++) {
		//Retrieve the total moved distance by the dots. Speed of point depends on highest freq at current time
		yOffset[i] += dotSpeed * getHighestFreq() * timeDifference;
		xOffset[i] += dotSpeed * getHighestFreq() * timeDifference;
		//Update the coordinates of each dot with Perlin Noise
		dots[i].x = ofSignedNoise(xOffset[i]) * animationRadius;
		dots[i].y = ofSignedNoise(yOffset[i]) * animationRadius;
	}
}

//Retrieves the highest frequency value within the sound spectrum
float ofApp::getHighestFreq() {
	float highestFrequency = 0.0F;
	for (int i = 0; i < numberOfBars; i++) {
		if (highestFrequency < soundSpectrum[i]) {
			highestFrequency = soundSpectrum[i];
		}
	}
	return highestFrequency;
}

void ofApp::drawBars() {
	maxBarHeightReached = false;
	float barHeight;
	float barHeightThreshold;
	//Draw rectangles based on audio frequency
	for (int i = 0; i < numberOfBars; i++) {
		barHeight = -soundSpectrum[i] * maxBarHeight;
		barHeightThreshold = maxBarHeight - minBarHeight;
		if (-barHeight >= barHeightThreshold) {
			maxBarHeightReached = true;
		}
		ofRect(xPositionOfBars[i], ofGetHeight(), barWidth, barHeight - minBarHeight);
	}
}

//Updates the bars reactive to the audio frequency
void ofApp::updateBars() {
	//Assistance in creating audio reactive bars through tutorial: https://www.youtube.com/watch?v=IiTsE7P-GDs
	float *value = ofSoundGetSpectrum(numberOfBars);
	for (int i = 0; i < numberOfBars; i++) {
		soundSpectrum[i] *= soundSpectrumSmoothnessVal;
		soundSpectrum[i] = max(soundSpectrum[i], value[i]);
		xPositionOfBars[i] += 1;
		if (xPositionOfBars[i] > ofGetScreenWidth()) {
			xPositionOfBars[i] = -barWidth;
		}
	}
}

//Settings for when bar achieves maximum height
void bassSpike() {
	dotRadius = 6;
	lineWidth = 3;
	speedMultiplier = 1.1;
}

//Regular settings
void clearBassSpike() {
	dotRadius = 3;
	lineWidth = 2;
	speedMultiplier = .8;
}







