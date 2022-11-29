#include "Player.h"

Player::Player()
{
	setPlayer();
	setHitbox();
}

Player::Player(float xPos)
{
	setPlayer();
	setHitbox();
	m_player.setPosition(xPos, 384);
}

void Player::setPlayer()
{
	//Caracteristiques
	m_player.setSize(Vector2f(10, 100));
	m_player.setOrigin(Vector2f(5, 50));
	m_player.setFillColor(Color(200, 200, 200));
	m_player.setPosition(35, 384);
}

void Player::setHitbox()
{
	m_playerHitbox = m_player.getGlobalBounds();
}

FloatRect Player::getHitbox()
{
	return m_playerHitbox;
}

void Player::movePlayerUp(float moveSpeed)
{
	m_player.move(0, -moveSpeed);
}

void Player::movePlayerDown(float moveSpeed)
{
	m_player.move(0, moveSpeed);
}

float Player::getPlayerPositionY()
{
	return m_player.getPosition().y;	
}
