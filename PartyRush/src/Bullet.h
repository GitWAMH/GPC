#pragma once

#include "Enemy.h"

class Bullet : public Enemy {
	private:
		int points;
		int speed;
		float angle;
		bool dead;
		ofRectangle squareObject;
	public:

		Bullet(float x, float y, ofColor color, int cannonId, float angle) : Enemy(x, y, color, cannonId) {
			this->speed = randomGenerator(1, 10);
			this->squareObject = ofRectangle(this->getX(), this->getY(), BULLET_SIZE, BULLET_SIZE);
			this->dead = false;
			this->angle = angle;
			this->points = (color == ofColor::red) ? -POINTS_NORMAL : POINTS_NORMAL;
		};

		void move();
		bool isDead();
		void die();
		int getPoints();
		void printBullet();
		float getAngle();
		void setAngle(float angle);
		ofRectangle getFigure();
		void setSpeed(int speed);
		int getSpeed();
		
};