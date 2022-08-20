#include "StandaloneApplication.h"

#include "framework/Canvas.h"
#include "framework/FileExplorer.h"
#include "framework/SimpleButton.h"

StandaloneApplication::StandaloneApplication()
	: WindowApplication(sf::VideoMode(DEFAULT_WINDOW_WIDTH,
		DEFAULT_WINDOW_HEIGHT),
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
	addWidget<FileExplorer>("Dialog",
		sf::Vector2i{ 0, 510 },
		sf::Vector2u{ 400, 300 });
}

void StandaloneApplication::handle(const sf::Event& event)
{}
