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
	auto drawing_canvas = addWidget<Canvas>("Main",
		sf::Vector2i{ 10, 10 },
		sf::Vector2u{ 900, 500 });

	addWidget<SimpleButton>("Pencil",
		sf::Vector2i{ 920, 10 },
		sf::Vector2u{ 100, 100 },
		[=]()
	{
		drawing_canvas->selectPencil(10);
	});
	addWidget<SimpleButton>("Brush",
		sf::Vector2i{ 920, 120 },
		sf::Vector2u{ 100, 100 },
		[=]()
	{
		drawing_canvas->selectBrush(10);
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
			drawing_canvas->loadImage(file.value());
		}
	});

	addWidget<SimpleButton>("Zoom",
		sf::Vector2i{ 920, 230 },
		sf::Vector2u{ 100, 100 },
		[=]()
		{
			drawing_canvas->doubleScale();
		});

	addWidget<SimpleButton>("Shrink",
		sf::Vector2i{ 920, 340 },
		sf::Vector2u{ 100, 100 },
		[=]()
		{
			drawing_canvas->lowerScale();
		});

	addWidget<SimpleButton>("Move",
		sf::Vector2i{ 920, 450 },
		sf::Vector2u{ 100, 100 },
		[=]()
		{
			drawing_canvas->selectViewer();
		});
}

void StandaloneApplication::handle(const sf::Event& event)
{
	
}
