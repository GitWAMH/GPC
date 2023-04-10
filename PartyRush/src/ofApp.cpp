#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetEscapeQuitsApp(false);
	imageBG.load("spaceBG.jpg");

	estadoActual = Estado::Esperando;

	powerUp.load("Barra aumenta.mp3");
	puntoGana.load("Gana punto.mp3");
	puntoPierde.load("Pierde punto.mp3");
	juegoInicia.load("Inicio juego.mp3");
	finJuego.load("Fin juego.mp3");
	fondoJuego.load("Fondo juego.mp3");
	juegoEspera.load("Esperando juego.mp3");
	juegoEspera.setLoop(true);
	juegoEspera.play();

	//Crear tanque
	tank = new Tank(0, 0, ofColor::blue, 1);

	//Crear jugadores
	player1 = new Player(-400, 200, ofColor::cyan);
	player2 = new Player(400, -200, ofColor::pink);


	crazyTime = false;
	colorText = ofColor::white;
	probShoot = 3;
	crazyRotation = false;
}

//--------------------------------------------------------------
void ofApp::update(){

	switch (estadoActual)
	{
		case Estado::Esperando:
			break;

		case Estado::Jugando:
			if (!timer.timeIsUp()) {
				if (!juegoInicia.getIsPlaying() && !fondoJuego.getIsPlaying()) {
					fondoJuego.setLoop(true);
					fondoJuego.play();
				}

				if (!crazyTime && timer.crazyTime()) { // Activar hora loca
					tank->setRotation(300);
					colorText = ofColor::red;
					crazyTime = true;
					crazyRotation = true;
					probShoot = 10;
					powerUp.play();
				}
				else if (crazyTime && !timer.crazyTime()) { // Desactivar hora loca
					tank->setRotation(100);
					tank->setDirection(1); // Rotará en sentido horario
					colorText = ofColor::white;
					crazyTime = false;
					crazyRotation = false;
					probShoot = 3;
					powerUp.play();
				}

				bulletsVector.erase(std::remove_if(
					bulletsVector.begin(), bulletsVector.end(),
					[](Bullet* bullet) {
						bool isDead = bullet->isDead();
						if (isDead) {
							delete bullet; // Liberar memoria del objeto eliminado
						}
						return isDead;
					}),
					bulletsVector.end()
						);

				int windowWidth = (ofGetWindowWidth() / 2);
				int windowHeight = (ofGetWindowHeight() / 2);

				for (Bullet* bullet : bulletsVector) {
					bullet->move();

					ofRectangle bulletRect = bullet->getFigure();
					ofRectangle player1Rect = player1->getFigure();
					ofRectangle player2Rect = player2->getFigure();

					if (bulletRect.intersects(player1Rect) || bulletRect.inside(player1Rect)) {
						player1->addScore(bullet->getPoints());
						if (bullet->getPoints() > 0) {
							puntoGana.play();
						}
						else {
							puntoPierde.play();
						}
						bullet->die();
					}
					else if (bulletRect.intersects(player2Rect) || bulletRect.inside(player2Rect)) {
						player2->addScore(bullet->getPoints());
						if(bullet->getPoints() > 0) {
							puntoGana.play();
						}
						else {
							puntoPierde.play();
						}
						bullet->die();
					}

					if (bulletRect.x <= -windowWidth || bulletRect.x + bulletRect.width >= windowWidth ||
						bulletRect.y <= -windowHeight || bulletRect.y + bulletRect.height >= windowHeight) {
						bullet->die();
					}
				}

				if (crazyRotation) {
					if (randomGenerator(0, 100) > 99) {
						tank->setDirection((tank->getDirection() + 1) % 2); // Rotará en sentido antihorario
					}

				}

				bool shoot = (randomGenerator(0, 100) > probShoot) ? false : true;

				if (shoot) {
					int whichCannon = tank->shoot();
					int red = BULLET_PLUS_RED;
					int green = BULLET_PLUS_GREEN;
					int blue = BULLET_PLUS_BLUE;

					bool isGood = (randomGenerator(0, 1) == 0) ? false : true;
					if (!isGood) {
						red = BULLET_MINUS_RED;
						green = BULLET_MINUS_GREEN;
						blue = BULLET_MINUS_BLUE;
					}

					ofColor color(red, green, blue);
					float angle = (tank->getAngle(whichCannon) * 3.14) / 180;
					float xBullet = TANK_RADIUS * cos(angle);
					float yBullet = TANK_RADIUS * sin(angle);

					bulletsVector.push_back(new Bullet(xBullet, -yBullet, color, whichCannon, angle));
				}
				
				timer.updateTime();
			}
			else {
				estadoActual = ofApp::Estado::Final;
				juegoInicia.stop();
				fondoJuego.stop();
				finJuego.setLoop(true);
				finJuego.play();
			}
			break;

		case Estado::Final:
			break;

		default:
			break;
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::black);

	/* Drawing the texts */
	ofPushStyle();
	ofSetColor(colorText);
	imageBG.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofDrawBitmapString("Tiempo: " + timer.getTimeFormat(), (ofGetWindowWidth() / 2) - 50, 100);

	ofColor colorPlayer1 = (player1->getScore() > player2->getScore()) ? ofColor::limeGreen : colorText;
	ofSetColor(colorPlayer1);
	ofDrawBitmapString("Jugador 1: " + to_string(player1->getScore()), 50, 100);

	ofColor colorPlayer2 = (player1->getScore() < player2->getScore()) ? ofColor::limeGreen : colorText;
	ofSetColor(colorPlayer2);
	ofDrawBitmapString("Jugador 2: " + to_string(player2->getScore()), ofGetWindowWidth() - 150, 100);

	ofPopStyle();
	string text = "";
	switch (estadoActual)
	{
		case Estado::Esperando:
			text = "PRESIONA LA TECLA P PARA EMPEZAR\nPRESIONA LA TECLA O PARA SALIR";
			ofPushStyle();
			ofSetColor(ofColor::red);
			ofDrawBitmapString(text, (ofGetWindowWidth() / 2) - 150, ofGetWindowHeight() / 2);
			ofPopStyle();
			break;

		case Estado::Jugando:
			/* Drawing the players */
			player1->printPlayer();
			player2->printPlayer();

			/* Drawing the tank */
			tank->printTank();

			/* Drawing the bullets */ 
			for (Bullet* bullet : bulletsVector) {
				bullet->printBullet();
			}
			break;

		case Estado::Final:
			text = "FINAL DEL JUEGO!!\n";
			if (player1->getScore() > player2->getScore()) {
				text += "JUGADOR 1 GANA!!\n";
			}
			else if (player1->getScore() < player2->getScore()) {
				text += "JUGADOR 2 GANA!!\n";
			}
			else {
				text += "EMPATE!!\n";
			}
			text += "PRESIONA LA TECLA P PARA VOLVER A JUGAR\nPRESIONA LA TECLA O PARA SALIR";
			ofPushStyle();
			ofSetColor(ofColor::red);
			ofDrawBitmapString(text, (ofGetWindowWidth() / 2) - 150, ofGetWindowHeight() / 2);
			ofPopStyle();
			break;

		default:
			break;
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (estadoActual == ofApp::Estado::Esperando)
	{
		switch (key) {
			case 'p': case 'P':
				juegoEspera.stop();
				juegoInicia.play();
				timer.initTimer();
				estadoActual = ofApp::Estado::Jugando;
				break;
			case 'o': case 'O':
				ofExit();
				break;
			default:
				break;
		}
	}
	else if (estadoActual == ofApp::Estado::Jugando)
	{
		switch (key)
		{
			case 'w': case 'W':
				player1->movePlayer(GameElement::Direccion::Arriba);
				break;

			case 's': case 'S':
				player1->movePlayer(GameElement::Direccion::Abajo);
				break;

			case 'a': case 'A':
				player1->movePlayer(GameElement::Direccion::Izquierda);
				break;

			case 'd': case 'D':
				player1->movePlayer(GameElement::Direccion::Derecha);
				break;

			case 57357:
				player2->movePlayer(GameElement::Direccion::Arriba);
				break;

			case 57359:
				player2->movePlayer(GameElement::Direccion::Abajo);
				break;

			case 57356:
				player2->movePlayer(GameElement::Direccion::Izquierda);
				break;

			case 57358:
				player2->movePlayer(GameElement::Direccion::Derecha);
				break;

			default:
				break;
		}
	}
	else if (estadoActual == ofApp::Estado::Final)
	{

		switch (key)
		{
			case 'p': case 'P':
				resetGame();
				finJuego.stop();
				juegoInicia.play();
				timer.initTimer();
				estadoActual = ofApp::Estado::Jugando;
				break;
			case 'o': case 'O':
				ofExit();
				break;
			default:
				break;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	//tankX = ofGetWindowWidth() / 2;
	//tankY = ofGetWindowHeight() / 2;
	//tank->setPoint(tankX, tankY);
	//player1->setPoint(player1->getX() + 100, player1->getY() + 100);
	//player2->setPoint(player2->getX() + (ofGetWindowWidth() - 200), player2->getY() + (ofGetWindowHeight() - 200));
	/*for (Bullet* bullet : bulletsVector)
	{
		bullet->setPoint(bullet->getX() + ((ofGetWindowWidth() / 2) - 10), bullet->getY() + ((ofGetWindowHeight() / 2) - 10));
	}
	*/
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::resetGame() {

	/* Resetear tanque */
	delete tank;
	tank = new Tank(0, 0, ofColor::blue, 1);

	/* Resetear jugadores */
	delete player1;
	delete player2;
	player1 = new Player(-400, 200, ofColor::cyan);
	player2 = new Player(400, -200, ofColor::pink);

	/* Borrar todas las balas del juego */
	bulletsVector.clear();
}

ofApp::~ofApp() {
	delete player1;
	delete player2;
	delete tank;
	bulletsVector.clear();
}