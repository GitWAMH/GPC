#include "Timer.h"

//--------------------------------------------------------------
void Timer::initTimer() {
	lastTime = ofGetElapsedTimef();
	currentTime = ofGetElapsedTimef();
	countdown = INITIAL_TIME;
}

//--------------------------------------------------------------
int Timer::updateTime() {
	if (countdown > 0) {
		currentTime = ofGetElapsedTimef();
		countdown = round(INITIAL_TIME - (currentTime - lastTime));
	}

	return countdown;
}

//--------------------------------------------------------------
string Timer::getTimeFormat() {

	int minutes = countdown / 60;
	int seconds = countdown % 60;

	return (to_string(minutes) + ":" + ((seconds / 10 >= 1) ? to_string(seconds) : "0" + to_string(seconds)));
}

//--------------------------------------------------------------
bool Timer::timeIsUp() {
	return (countdown > 0) ? false : true;
}

//--------------------------------------------------------------
bool Timer::crazyTime() {
	return (countdown < CRAZY_TIME && countdown >= CRAZY_TIME - DURATION) ? true : false;
}