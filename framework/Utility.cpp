#include "pch.h"
#include "Utility.h"

char GetCorrespondingCharacter(const sf::Event::KeyEvent& event)
{
	char character;
	switch(event.code)
	{
	case sf::Keyboard::A:
		character = 'a';
		break;
	case sf::Keyboard::B:
		character = 'b';
		break;
	case sf::Keyboard::C:
		character = 'c';
		break;
	case sf::Keyboard::D:
		character = 'd';
		break;
	case sf::Keyboard::E: 
		character = 'e';
		break;
	case sf::Keyboard::F:
		character = 'f';
		break;
	case sf::Keyboard::G:
		character = 'g';
		break;
	case sf::Keyboard::H:
		character = 'h';
		break;
	case sf::Keyboard::I:
		character = 'i';
		break;
	case sf::Keyboard::J:
		character = 'j';
		break;
	case sf::Keyboard::K:
		character = 'k';
		break;
	case sf::Keyboard::L:
		character = 'l';
		break;
	case sf::Keyboard::M:
		character = 'm';
		break;
	case sf::Keyboard::N:
		character = 'n';
		break;
	case sf::Keyboard::O:
		character = 'o';
		break;
	case sf::Keyboard::P:
		character = 'p';
		break;
	case sf::Keyboard::Q:
		character = 'q';
		break;
	case sf::Keyboard::R:
		character = 'r';
		break;
	case sf::Keyboard::S:
		character = 's';
		break;
	case sf::Keyboard::T:
		character = 't';
		break;
	case sf::Keyboard::U:
		character = 'u';
		break;
	case sf::Keyboard::V:
		character = 'v';
		break;
	case sf::Keyboard::W:
		character = 'w';
		break;
	case sf::Keyboard::X:
		character = 'x';
		break;
	case sf::Keyboard::Y:
		character = 'y';
		break;
	case sf::Keyboard::Z:
		character = 'z';
		break;
	default: 
		character = '\0';
	}
	if(event.shift)
	{
		character = std::toupper(character);
	}
	return character;
}
