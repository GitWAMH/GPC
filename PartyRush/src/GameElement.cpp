#include "GameElement.h"

GameElement::GameElement(float x, float y, ofColor color) {
	this->point.x = x;
	this->point.y = y;
	this->color = color;
}

//--------------------------------------------------------------
void GameElement::setPoint(float x, float y) {
	this->point.x = x;
	this->point.y = y;
}


//--------------------------------------------------------------
float GameElement::getX() {
	return this->point.x;
}

//--------------------------------------------------------------
float GameElement::getY() {
	return this->point.y;
}

//--------------------------------------------------------------
ofColor GameElement::getColor() {
	return this->color;
}

//--------------------------------------------------------------
void GameElement::setColor(ofColor color) {
	this->color = color;
}
