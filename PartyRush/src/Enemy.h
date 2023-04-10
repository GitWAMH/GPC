#pragma once

#include "GameElement.h"

class Enemy : public GameElement {
	private:
		int direction;
	public:

		Enemy(float x, float y, ofColor color, int direction) :GameElement(x, y, color) {

			this->direction = direction;
		};

		int getDirection();
		void setDirection(int direction);

};