#include "Player.h"

Player::Player()
{

}

Player::Player(float width, float height)
{
	setPlayer(width, height);
	setHitbox();
}

Player::Player(float xPos, float width, float height)
{
	setPlayer(width, height);
	setHitbox();
	m_player.setPosition(xPos, 384);
}

void Player::setPlayer(float width, float height)
{
	//Caracteristiques
	m_player.setSize(Vector2f(width, height));
	m_player.setOrigin(Vector2f(width / 2, height / 2));
	m_player.setFillColor(Color(200, 200, 200));
	m_player.setPosition(35, 384);
}

void Player::setHitbox()
{
	m_playerHitbox = m_player.getGlobalBounds();
}

FloatRect Player::getHitbox()
{
	m_playerHitbox = m_player.getGlobalBounds();
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

float Player::getPlayerHeight()
{
	return m_player.getSize().y;
}
