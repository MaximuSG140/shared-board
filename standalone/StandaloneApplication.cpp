#include "StandaloneApplication.h"

#include "framework/Canvas.h"
#include "framework/FileDialog.h"
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
	addWidget<SimpleButton>("Load",
		sf::Vector2i{ 410, 520 },
		sf::Vector2u{ 100, 100 },
		[=]()
	{
		FileDialog dialog;
		dialog.run();
		if (auto file = dialog.chosenFile();
			file.has_value())
		{
			canvas->loadImage(file.value());
		}
	});
}

void StandaloneApplication::handle(const sf::Event& event)
{}
