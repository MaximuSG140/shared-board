#pragma once
#include "framework/WindowApplication.h"

class StandaloneApplication
	: public WindowApplication
{
public:
	StandaloneApplication();
	void handle(const sf::Event& event) override;
};

