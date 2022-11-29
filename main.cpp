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

    //Préparation affichage du score
    if (!generalFont.loadFromFile("resources/verdana.ttf"))
    {
        cout << "Erreur chargement police" << endl;
    }
    score.setFont(generalFont);
    score.setFillColor(Color(175, 175, 175));
    score.setCharacterSize(30);
    score.setOrigin(textRectangle.getLocalBounds().left + textRectangle.getLocalBounds().width / 2,
                    textRectangle.getLocalBounds().top + textRectangle.getLocalBounds().height / 2);
    score.setPosition(Vector2f(WIN_WIDTH / 2, 10));
    


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
        scoreStr = to_string(playerScore) + " - " + to_string(cpuScore);
        score.setString(scoreStr);

        checkKey();
        cpuMovement();
        ballMovement();

        window.clear();
        window.draw(player1);
        window.draw(cpu);
        window.draw(ball);
        window.draw(score);
        window.display();

    }

    return 0;
}

//Fonction de gestion des inputs clavier
void checkKey()
{
    if (input.getKey().up == true)
    {
        if (player1.getPlayerPositionY() > (player1.getPlayerHeight() / 2)) // si on est tout en haut (position y 0 + 50 -> la moitié de la hauteur de la raquette), on peut pas aller plus en haut
        {
            player1.movePlayerUp(PLAYER_SPEED);
        }
    }

    if (input.getKey().down == true)
    {
        if (player1.getPlayerPositionY() < (WIN_HEIGHT - (player1.getPlayerHeight() / 2)))
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
    if (cpu.getPlayerPositionY() <= (cpu.getPlayerHeight() / 2) || cpu.getPlayerPositionY() >= (WIN_HEIGHT - (cpu.getPlayerHeight() / 2)))
    {
        aiSpeed *= -1;
    }
}

//Gestion du mouvement de la balle
void ballMovement()
{
    if (!hasScored)
    {
        ballHitbox = ball.getGlobalBounds();
        ball.move(-xBallSpeed, yBallSpeed);
        if (ball.getPosition().x <= 0 || ball.getPosition().x >= WIN_WIDTH)
        {
            if (ball.getPosition().x <= 0)
            {
                cpuScore++;
            }
            if (ball.getPosition().x >= WIN_WIDTH)
            {
                playerScore++;
            }
            ball.setPosition(WIN_WIDTH / 2, WIN_HEIGHT / 2);
            xBallSpeed *= -1;
            hasScored = true;
            scoreClock.restart();
        }

        if (ball.getPosition().y <= 0 || ball.getPosition().y >= WIN_HEIGHT)
        {
            yBallSpeed *= -1;
        }
        if (!hasCollided)
        {
            if (ballHitbox.intersects(player1.getHitbox()) || ballHitbox.intersects(cpu.getHitbox()))
            {
                hasCollided = true;
                collisionClock.restart();
                xBallSpeed *= -1;
            }
        }

        if (collisionClock.getElapsedTime().asSeconds() > 1 && hasCollided == true)
        {
            hasCollided = false;
        }
    }

    if (scoreClock.getElapsedTime().asSeconds() > 2)
    {
        hasScored = false;
    }
}