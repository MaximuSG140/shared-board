#include "StandaloneApplication.h"

#include "framework/BasicEdit.h"
#include "framework/Canvas.h"
#include "framework/FileDialog.h"
#include "framework/FileExplorer.h"
#include "framework/Label.h"
#include "framework/SimpleButton.h"

StandaloneApplication::StandaloneApplication()
	: WindowApplication(sf::VideoMode(DEFAULT_WINDOW_WIDTH,
		DEFAULT_WINDOW_HEIGHT),
		"Drawer")	
{
	auto drawing_canvas = addWidget<Canvas>("Main",
	                                        sf::Vector2i{ 10, 10 },
	                                        sf::Vector2u{ 900, 500 });
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
	auto pencil_size_edit = addWidget<BasicEdit>("Size",
	                                  sf::Vector2i{920, 560},
	                                  sf::Vector2u{300, 75});

	addWidget<Label>("ChoseSizeLabel",
		sf::Vector2i{ 720, 560 },
		sf::Vector2u{ 200, 75 },
		"Enter pencil size");

	addWidget<SimpleButton>("Pencil",
		sf::Vector2i{ 920, 10 },
		sf::Vector2u{ 100, 100 },
		[=]()
		{
			drawing_canvas->selectPencil(std::stoi(pencil_size_edit->text()));
		});
	addWidget<SimpleButton>("Brush",
		sf::Vector2i{ 920, 120 },
		sf::Vector2u{ 100, 100 },
		[=]()
		{
			drawing_canvas->selectBrush(std::stoi(pencil_size_edit->text()));
		});

}

void StandaloneApplication::handle(const sf::Event& event)
{}