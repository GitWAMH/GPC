#pragma once
#include "ofMain.h"
#include "Parameters.h"

class GameElement {
	protected:
		ofPoint point;

	private:
		
		ofColor color;

	public:

		enum class Direccion { Arriba, Abajo, Izquierda, Derecha };

		GameElement(float x, float y, ofColor color);

		void setPoint(float x, float y);
		float getX();
		float getY();		
		ofColor getColor();
		void setColor(ofColor color);


};

