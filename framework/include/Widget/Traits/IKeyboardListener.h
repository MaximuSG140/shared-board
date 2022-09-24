#pragma once
#include "Widget.h"

class IKeyboardListener
{
public:
	virtual void handleKeyPress(const sf::Event::KeyEvent& event) = 0;
	virtual ~IKeyboardListener() = default;
};

