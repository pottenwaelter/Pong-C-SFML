#ifndef MAIN_H
#define MAIN_H

#include "Input.h"
#include "Player.h"

//Variables globales
//Fenetre
RenderWindow window;
//Instances des raquettes
Player player1;
Player cpu(1024 - 35);
//Creation de la balle
CircleShape ball;
FloatRect ballHitbox;
RectangleShape testRect;

//Instance des inputs
Input input;
//Vitesse IA
float aiSpeed = 3;
//Vitesse balle
float xBallSpeed = 2.5;
float yBallSpeed = 2.5;


//Constantes
const int WIN_HEIGHT = 768;
const int WIN_WIDTH = 1024;
const float PLAYER_SPEED = 3;


//Prototypes de fonctions
void checkKey();
void cpuMovement();
void ballMovement();


#endif // !MAIN_H
