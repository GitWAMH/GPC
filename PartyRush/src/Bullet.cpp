#include "Bullet.h"

//--------------------------------------------------------------
void Bullet::move() {

	float newX = this->getX();
	float newY = this->getY();
	int speed = this->getSpeed();
	float angle = this->getAngle();

	float vx = speed * cos(angle);
	float vy = speed * sin(angle);

	newX += vx;
	newY += -vy;

	this->setPoint(newX, newY);
	this->squareObject.setX(newX);
	this->squareObject.setY(newY);

}

//--------------------------------------------------------------
int Bullet::getPoints() {
	return this->points;
}

//--------------------------------------------------------------
void Bullet::printBullet() {

	ofPushMatrix();
	ofPushStyle();
	ofTranslate((ofGetWindowWidth() / 2), (ofGetWindowHeight() / 2));
	ofSetColor(this->getColor());
	ofDrawRectangle(squareObject);
	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
ofRectangle Bullet::getFigure() {
	return this->squareObject;
}

//--------------------------------------------------------------
void Bullet::die() {
	this->dead = true;
}

//--------------------------------------------------------------
bool Bullet::isDead() {
	return this->dead;
}

//--------------------------------------------------------------
float Bullet::getAngle() {
	return this->angle;
}

//--------------------------------------------------------------
void Bullet::setAngle(float angle) {
	this->angle = angle;
}

//--------------------------------------------------------------
int Bullet::getSpeed() {
	return this->speed;
}

//--------------------------------------------------------------
void Bullet::setSpeed(int speed) {
	this->speed = speed;
}
