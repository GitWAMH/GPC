#include "Tank.h"

//--------------------------------------------------------------
int Tank::shoot() {
	return randomGenerator(1, 4);

}

void Tank::printTank() {
	ofColor colorDefault(TANK_RED, TANK_GREEN, TANK_BLUE);
	int cannonDistance = TANK_RADIUS + 20;
	float rotationAngle = ofGetElapsedTimef() * rotation;	
	int direction = this->getDirection();

	ofPushMatrix();
	ofPushStyle();
	ofSetColor(colorDefault);
	ofTranslate((ofGetWindowWidth() / 2), (ofGetWindowHeight() / 2));
	ofDrawSphere(this->point.x, this->point.y, TANK_RADIUS);
	//Canon derecha
	
	ofPushMatrix();
	angle1 = (direction == 1) ? rotationAngle : -rotationAngle;
	ofRotateDeg(angle1);
	ofDrawRectangle(canon);
	ofPopMatrix();

	//Canon superior
	ofPushMatrix();
	angle2 = (direction == 1) ? (90 + rotationAngle) : (90 - rotationAngle);
	ofRotateDeg(angle2);
	ofDrawRectangle(canon);
	ofPopMatrix();

	//Canon izquierda
	ofPushMatrix();
	angle3 = (direction == 1) ? (180 + rotationAngle) : (180 - rotationAngle);
	ofRotateDeg(angle3);
	ofDrawRectangle(canon);
	ofPopMatrix();

	//Canon inferior
	ofPushMatrix();
	angle4 = (direction == 1) ? (270 + rotationAngle) : (270 - rotationAngle);
	ofRotateDeg(angle4);
	ofDrawRectangle(canon);
	ofPopMatrix();

	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
float Tank::getAngle(int whichCannon) {
	float returned_angle = 0;
	if (whichCannon == 1) {
		returned_angle = angle1;
	}
	else if (whichCannon == 2) {
		returned_angle = angle2;
	}
	else if (whichCannon == 3) {
		returned_angle = angle3;
	}
	else if (whichCannon == 4) {
		returned_angle = angle4;
	}
	return returned_angle;
}

//--------------------------------------------------------------
void Tank::setRotation(int rotation) {
	this->rotation = rotation;
}