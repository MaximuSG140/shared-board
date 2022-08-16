#include "StandaloneApplication.h"

#include "framework/Canvas.h"
#include "framework/SimpleButton.h"

StandaloneApplication::StandaloneApplication()
	: WindowApplication(sf::VideoMode(1280,
		840),
		"Drawer")
{
	auto canvas = addWidget<Canvas>("Main",
		sf::Vector2i{ 10, 10 },
		sf::Vector2u{ 900, 500 });

	addWidget<SimpleButton>("Pencil",
		sf::Vector2i{ 910, 10 },
		sf::Vector2u{ 100, 100 },
		[=]()
	{
		canvas->selectPencil(10);
	});
	addWidget<SimpleButton>("Brush",
		sf::Vector2i{ 910, 110 },
		sf::Vector2u{ 100, 100 },
		[=]()
	{
		canvas->selectBrush(10);
	});
}

void StandaloneApplication::handle(const sf::Event& event)
{}
