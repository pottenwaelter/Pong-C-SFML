#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Player : public Drawable
{
public:
	Player();
	Player(float xPos);
	void setPlayer();
	void setHitbox();
	FloatRect getHitbox();
	void movePlayerUp(float moveSpeed);
	void movePlayerDown(float moveSpeed);
	float getPlayerPositionY();
private:
	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		target.draw(m_player, states);
	}
	RectangleShape m_player;
	FloatRect m_playerHitbox;
};

#endif // !PLAYER_H

