#include "Input.h"

//Constructeur
Input::Input()
{
	key.up = key.down = key.start = key.escape = false;
}

Input::KeyboardKey Input::getKey() const
{
	return key;
}

void Input::inputHandler(Event event, RenderWindow& window)
{
	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			key.escape = true;
			break;
		case Keyboard::Z:
			key.up = true;
			break;
		case Keyboard::S:
			key.down = true;
			break;
		case Keyboard::Enter:
			key.start = true;
			break;
		case Keyboard::Space:
			key.space = true;
			break;
		default:
			break;
		}
	}

	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Escape:
			key.escape = false;
			break;
		case Keyboard::Z:
			key.up = false;
			break;
		case Keyboard::S:
			key.down = false;
			break;
		case Keyboard::Enter:
			key.start = false;
			break;
		case Keyboard::Space:
			key.space = true;
			break;
		default:
			break;
		}
	}

}


