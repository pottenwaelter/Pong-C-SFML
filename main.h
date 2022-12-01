#ifndef MAIN_H
#define MAIN_H

#include "Input.h"
#include "Player.h"
#include <string>
#include <cmath>

//Variables globales
//Fenetre
RenderWindow window;
//Instances des raquettes
Player player1(10, 100);
Player cpu(1024 - 35, 10, 200);
//Creation de la balle
CircleShape ball;
FloatRect ballHitbox;

//Instance des inputs
Input input;
//Vitesse IA
float aiSpeed = 4;
//Vitesse balle
float xBallSpeed = 4;
float yBallSpeed = 4;
bool hasCollided = false;
Clock collisionClock;
//Texte
Font generalFont;
Text score;
string scoreStr;
//Scores
int playerScore = 0;
int cpuScore = 0;
//Bool pour bloquer la balle un petit moment après un but
bool hasScored = false;
Clock scoreClock;

//Menu pause
bool isGamePaused = false;
Text gamePause;
Clock pauseClock;


//Constantes
const int WIN_HEIGHT = 768;
const int WIN_WIDTH = 1024;
const float PLAYER_SPEED = 4;


//Prototypes de fonctions
void checkKey();
void cpuMovement();
void ballMovement();
void pauseMenu();


#endif // !MAIN_H
