#pragma once

/* Game parameters */
const int INITIAL_TIME = 90; // time in seconds
const int CRAZY_TIME = 60;
const int DURATION = 15;

/* Player parameters */
const int PLAYER_WIDTH = 70;
const int PLAYER_HEIGHT = 50;

const int PLAYER_RED = 255;
const int PLAYER_GREEN = 255;
const int PLAYER_BLUE = 255;

/* Tank parameters */
const int NUM_BULLETS = 256;
const int TANK_RADIUS = 50;

const int TANK_RED = 0;
const int TANK_GREEN = 0;
const int TANK_BLUE = 255;

const int CANNON_WIDTH = 20;
const int CANNON_HEIGHT = 30;

enum class Cannons { CANNON_UP = 1, CANNON_RIGHT = 2, CANNON_DOWN = 3, CANNON_LEFT = 4 };

/* Bullet parameters */
	/* Bullet green colors */
const int BULLET_PLUS_RED = 0;
const int BULLET_PLUS_GREEN = 255;
const int BULLET_PLUS_BLUE = 0;
	/* Bullet red colors */
const int BULLET_MINUS_RED = 255;
const int BULLET_MINUS_GREEN = 0;
const int BULLET_MINUS_BLUE = 0;

const int BULLET_SIZE = 15;

const int POINTS_NORMAL = 50;
const int POINTS_CRAZY_TIME = 100;


/* Common functions (between App and GameElements) */
int randomGenerator(int min, int max);