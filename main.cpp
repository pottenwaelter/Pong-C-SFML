#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.h"

using namespace sf;
using namespace std;

int main()
{
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), "SFML Pong");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    //Initialisation de la balle
    ball.setFillColor(Color::White);
    ball.setRadius(10);
    ball.setOrigin(10, 10);
    ball.setPosition(512, 384);
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            
            input.inputHandler(event, window);
        }

        checkKey();
        cpuMovement();
        ballMovement();

        window.clear();
        window.draw(player1);
        window.draw(cpu);
        window.draw(ball);
        window.display();

    }

    return 0;
}

//Fonction de gestion des inputs clavier
void checkKey()
{
    if (input.getKey().up == true)
    {
        if (player1.getPlayerPositionY() > 50) // si on est tout en haut (position y 0 + 50 -> la moitié de la hauteur de la raquette), on peut pas aller plus en haut
        {
            player1.movePlayerUp(PLAYER_SPEED);
        }
    }

    if (input.getKey().down == true)
    {
        if (player1.getPlayerPositionY() < (WIN_HEIGHT - 50))
        {
            player1.movePlayerDown(PLAYER_SPEED);

        }
    }

    if (input.getKey().escape == true)
    {
        window.close();
    }
}

//Gestion du déplacement de l'IA
void cpuMovement()
{
    cpu.movePlayerUp(aiSpeed);
    if (cpu.getPlayerPositionY() <= 50 || cpu.getPlayerPositionY() >= (WIN_HEIGHT - 50))
    {
        aiSpeed *= -1;
    }
}

//Gestion du mouvement de la balle
void ballMovement()
{
    ballHitbox = ball.getGlobalBounds();
    cout << ballHitbox.left << endl;
    ball.move(-xBallSpeed, yBallSpeed);
    if (ball.getPosition().x <= 0 || ball.getPosition().x >= 1024)
    {
        xBallSpeed *= -1;
    }

    if (ball.getPosition().y <= 0 || ball.getPosition().y >= 768)
    {
        yBallSpeed *= -1;
    }

    if (ballHitbox.intersects(player1.getHitbox()))
    {
        cout << "Collision" << endl;
    }
}