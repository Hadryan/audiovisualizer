#include "ofApp.h"


//Variables related to the bars of the audio visualizer
const int numberOfBars = 400;
float soundRange[numberOfBars];
const int maxBarHeight = 300;
const int minBarHeight = 25;
const int barWidth = 8;
bool maxBarHeightReached = false;
vector<int> xPositionOfBars(numberOfBars);
float soundRangeFlatValue = .96;

//Variables related to the animation of the audio visualizer
const int numberOfDots = 450;
//Two dimensional vector-like structure to hold dots and their x,y coordinates
ofVec2f dots[numberOfDots];
vector<bool> isLinked(numberOfDots, false);
//Vector that determines the offset of the x,y coordindates of each dot to ensure they remain centered and on screen
vector<double> yOffset(numberOfDots), xOffset(numberOfDots);
float dotRadius = 2;
float lineWidth = 1;
float speedFactor = 1.1;
int distanceRange = 50;
double dotSpeed = .1;
int animationRadius = 550;
double currentTime = 0;

//Variables related to the background brightness of the audio visualizer
int backColor = 150;
const int maxColorValue = 255;


void ofApp::setup() {
	//Setup, load, and play specified audio file
	soundPlayer.loadSound("..//..//audio//epiphany.wav");
	soundPlayer.play();
	//Setup random initial x,y coordinate positions for each dot 
	for (int i = 0; i < numberOfDots; i++) {
		xOffset[i] = ofRandom(0, 1000);
		yOffset[i] = ofRandom(0, 1000);
	}
	//Setup bars and their positioning initially
	for (int i = 0; i < numberOfBars; i++) {
		soundRange[i] = 0;
		xPositionOfBars[i] = (barWidth + 1) * i;
	}
}

//Update the sound of the audio as well as the dot and bars positioning
void ofApp::update(){
	ofSoundUpdate();
	updateDots();
	updateBars();
}

//Set the background brightness (gradually increase/brighten till max reached).
//Draw the bars and dots for visualizer.
void ofApp::draw(){
	if (maxBarHeightReached && backColor <= maxColorValue) {
		backColor++;
	}
	else if (backColor >= 100) {
		backColor--;
	}
	ofSetColor(backColor);
	drawBars();
	drawDots();
}

//Settings for the animation when bar achieves maximum height
void spike() {
	dotRadius = 4;
	lineWidth = 2;
	speedFactor = 1.1;
}

//Regular settings for the animation if the bar is not at maximum height
void clearSpike() {
	dotRadius = 2;
	lineWidth = 1;
	speedFactor = .8;
}

//Return the highest frequency value within the sound range
float ofApp::getHighestFreq() {
	float highestFrequency = 0.0F;
	for (int i = 0; i < numberOfBars; i++) {
		if (highestFrequency < soundRange[i]) {
			highestFrequency = soundRange[i];
		}
	}
	return highestFrequency;
}

//Draw dots for foreground animation of the audio visualizer
void ofApp::drawDots() {
	//Changes animation settings based on the high frequency levels of audio 
	if (maxBarHeightReached) {
		spike();
	} else {
		clearSpike();
	}
	//Centers the dots within the animation 
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//Choose the color of the dots and create circles at those dots
	for (int i = 0; i < numberOfDots; i++) {
		if (isLinked[i]) {
			ofDrawCircle(dots[i].x, dots[i].y, dotRadius);
		}
	}
	linkDots();
	ofPopMatrix();
}

//Link dots when they are a specific distance from one another
void ofApp::linkDots() {
	for (int i = 0; i < numberOfDots; i++) {
		isLinked[i] = false;
		for (int j = i + 1; j < numberOfDots; j++) {
			double distance = ofDist(dots[i].x, dots[i].y, dots[j].x, dots[j].y);
			if (distance < distanceRange) {
				isLinked[i] = true;
				ofSetLineWidth(lineWidth);
				ofDrawLine(dots[i], dots[j]);
			}
		}
	}
}

//Updates the positioning of the dots on the screen
void ofApp::updateDots() {
	double timeElapsed = ofGetElapsedTimef();
	//Comes up with the difference in time since the last update happened
	double timeDifference = timeElapsed - currentTime;
	currentTime = timeElapsed;
	for (int i = 0; i < numberOfDots; i++) {
		//Get the total moved distance by the dots. Speed of point depends on the highest freq at current time
		yOffset[i] += dotSpeed * getHighestFreq() * timeDifference;
		xOffset[i] += dotSpeed * getHighestFreq() * timeDifference;
		//Update the coordinates of each dot
		dots[i].x = animationRadius * ofSignedNoise(xOffset[i]);
		dots[i].y = animationRadius * ofSignedNoise(yOffset[i]);
	}
}

//Draw the bars at the bottom of the screen for the audio visualizer within a certain height range 
void ofApp::drawBars() {
	maxBarHeightReached = false;
	float barHeight;
	float barHeightRange;
	//Draw rectangles based on audio frequency
	for (int i = 0; i < numberOfBars; i++) {
		barHeight = -soundRange[i] * maxBarHeight;
		barHeightRange = maxBarHeight - minBarHeight;
		if (-barHeight >= barHeightRange) {
			maxBarHeightReached = true;
		}
		ofRect(xPositionOfBars[i], ofGetHeight(), barWidth, barHeight - minBarHeight);
	}
}

//Updates the bars reactive to the audio frequency
void ofApp::updateBars() {
	//Assistance in creating bars sensitive to audio freuency through tutorial: https://www.youtube.com/watch?v=IiTsE7P-GDs
	float *value = ofSoundGetSpectrum(numberOfBars);
	for (int i = 0; i < numberOfBars; i++) {
		soundRange[i] *= soundRangeFlatValue;
		soundRange[i] = max(soundRange[i], value[i]);
		xPositionOfBars[i] += 1;
		if (xPositionOfBars[i] > ofGetScreenWidth()) {
			xPositionOfBars[i] = -barWidth;
		}
	}
}








