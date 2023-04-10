#pragma once

#include "Enemy.h"
#include "Bullet.h"

class Tank : public Enemy {
	private:
		ofRectangle canonSuperior, canonInferior, canonIzquierda, canonDerecha, canon;
		float angle1, angle2, angle3, angle4;
		int rotation;

	public:

		Tank(float x, float y, ofColor color, int direction) :Enemy(x, y, color,  direction) 
		{
			this->canon = ofRectangle(-CANNON_WIDTH / 2, -(TANK_RADIUS + 20), CANNON_WIDTH, CANNON_HEIGHT);
			this->angle1 = 0;
			this->angle2 = 90;
			this->angle3 = 180;
			this->angle4 = 270;
			this->rotation = 100;
		};

		void printTank();
		int shoot();
		float getAngle(int whichCannon);
		void setRotation(int rotation);


};