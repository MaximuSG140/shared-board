#pragma once
#include "framework/include/pch.h"

class IKeyboardListener
{
public:
	virtual void handleKeyPress(const sf::Event::KeyEvent& event) = 0;
	virtual ~IKeyboardListener() = default;
};

