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
	Player(float width, float height);
	Player(float xPos, float width, float height);
	void setPlayer(float width, float height);
	void setHitbox();
	FloatRect getHitbox();
	void movePlayerUp(float moveSpeed);
	void movePlayerDown(float moveSpeed);
	float getPlayerPositionY();
	float getPlayerHeight();
private:
	virtual void draw(RenderTarget& target, RenderStates states) const
	{
		target.draw(m_player, states);
	}
	RectangleShape m_player;
	FloatRect m_playerHitbox;
};

#endif // !PLAYER_H

