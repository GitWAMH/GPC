#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Tank.h"
#include "Bullet.h"
#include "Timer.h"

class ofApp : public ofBaseApp{
	private:

		Player* player1;
		Player* player2;
		Tank* tank;
		Timer timer;
		ofImage imageBG;

		bool crazyTime;
		ofColor colorText;
		int probShoot;
		bool crazyRotation;

	public:

		enum class Estado { Esperando, Jugando, Final };
		Estado estadoActual;

		ofSoundPlayer juegoInicia;
		ofSoundPlayer juegoEspera;
		ofSoundPlayer puntoGana;
		ofSoundPlayer puntoPierde;
		ofSoundPlayer powerUp;
		ofSoundPlayer finJuego;
		ofSoundPlayer fondoJuego;

		vector<GameElement *> gameObjects;
		vector<Bullet *> bulletsVector;

		int tankX, tankY;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void resetGame();
		~ofApp();
};
