#include "Player.h"

//--------------------------------------------------------------
void Player::addScore(int score) {
	this->score += score;
}

//--------------------------------------------------------------
void Player::subtractScore(int score) {
	this->score -= score;
}

//--------------------------------------------------------------
void Player::setScore(int score) {
	this->score = score;
}

//--------------------------------------------------------------
int Player::getScore() {
	return this->score;
}

//--------------------------------------------------------------
ofRectangle Player::getFigure() {
	return this->rectangleObject;
}

//--------------------------------------------------------------
void Player::printPlayer() {

	ofPushMatrix();
	ofPushStyle();
	ofSetColor(this->getColor());
	ofTranslate((ofGetWindowWidth() / 2), (ofGetWindowHeight() / 2));
	ofDrawRectangle(rectangleObject);
	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
void Player::movePlayer(Direccion direccion) {

	int windowWidth = ofGetWindowWidth();
	int windowHeight = ofGetWindowHeight();

	int e = -(ofGetWindowWidth() / 2);
	int y = -(ofGetWindowHeight() / 2);

	switch (direccion)
	{
	case Direccion::Arriba:
		if ((rectangleObject.y - 10) >= -(ofGetWindowHeight() / 2)) {
			this->point.y -= 10;
		}
		break;

	case Direccion::Abajo:
		if ((rectangleObject.y + rectangleObject.height + 10) <= (ofGetWindowHeight() / 2)) {
			this->point.y += 10;
		}
		break;

	case Direccion::Izquierda:
		if (rectangleObject.x - 10 >= -(ofGetWindowWidth() / 2)) {
			this->point.x -= 10;
		}
		break;

	case Direccion::Derecha:
		if ((rectangleObject.x + rectangleObject.width + 10) <= (ofGetWindowWidth() / 2)) {
			this->point.x += 10;
		}
		break;

	default:
		break;
	}

	rectangleObject.x = this->point.x;
	rectangleObject.y = this->point.y;


}

