#include "pch.h"
#include "FileDialog.h"

#include "FileExplorer.h"
#include "SimpleButton.h"

FileDialog::FileDialog()
	:WindowApplication(sf::VideoMode(WINDOW_WIDTH,
			WINDOW_HEIGHT),
		"Choose file",
		sf::Style::Titlebar | sf::Style::Close)
{
	auto explorer = addWidget<FileExplorer>("Explorer",
		sf::Vector2i{ EXPLORER_LEFT,
			EXPLORER_TOP },
		sf::Vector2u{ EXPLORER_WIDTH,
			EXPLORER_HEIGHT });

	addWidget<SimpleButton>("Ok",
		sf::Vector2i{ OK_BUTTON_LEFT,
				OK_BUTTON_TOP },
		sf::Vector2u{ OK_BUTTON_WIDTH,
			OK_BUTTON_HEIGHT },
		[=]()
	{
		chosen_file_ = explorer->chosenFile();
		close();
	});
	addWidget<SimpleButton>("Cancel",
		sf::Vector2i{ CANCEL_BUTTON_LEFT,
			CANCEL_BUTTON_TOP },
		sf::Vector2u{ CANCEL_BUTTON_WIDTH,
			CANCEL_BUTTON_HEIGHT },
		[=]()
	{
		close();
	});

}

std::optional<std::filesystem::path> FileDialog::chosenFile() const
{
	return chosen_file_;
}

void FileDialog::handle(const sf::Event& event)
{}
