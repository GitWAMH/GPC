#pragma once

#include "GameElement.h"

class Player : public GameElement {

private:
	int score;
	ofRectangle rectangleObject;

public:

	Player(float x, float y, ofColor color) :GameElement(x, -y, color) 
	{
		score = 0;
		rectangleObject = ofRectangle(x, -y, PLAYER_WIDTH, PLAYER_HEIGHT);
	};

	void printPlayer();
	void movePlayer(Direccion direccion);
	void addScore(int score);
	void subtractScore(int score);
	int getScore();
	void setScore(int score);
	ofRectangle getFigure();

};