#pragma once
#include "FileExplorer.h"
#include "SimpleButton.h"
#include "WindowApplication.h"
class FileDialog final :
    public WindowApplication
{
public:
	static constexpr int WINDOW_HEIGHT = 600;
	static constexpr int WINDOW_WIDTH = 800;

	static constexpr float EXPLORER_PROPORTION_HEIGHT = 0.8f;
	static constexpr float EXPLORER_PROPORTION_WIDTH = 0.97f;
	static constexpr unsigned EXPLORER_WIDTH = WINDOW_WIDTH * EXPLORER_PROPORTION_WIDTH;
	static constexpr unsigned EXPLORER_HEIGHT = WINDOW_HEIGHT * EXPLORER_PROPORTION_HEIGHT;

	static constexpr unsigned OK_BUTTON_WIDTH = 100;
	static constexpr unsigned OK_BUTTON_HEIGHT = 50;

	static constexpr unsigned CANCEL_BUTTON_WIDTH = 100;
	static constexpr unsigned CANCEL_BUTTON_HEIGHT = 50;

	static constexpr int BUTTON_OFFSET = 5;

	static constexpr int EXPLORER_TOP = 0;
	static constexpr int EXPLORER_LEFT = static_cast<int>(WINDOW_WIDTH) / 2 - 
		static_cast<int>(EXPLORER_WIDTH) / 2;

	static constexpr int OK_BUTTON_TOP = EXPLORER_TOP + EXPLORER_HEIGHT +
		FileExplorer::OUTLINE_THICKNESS + SimpleButton::OUTLINE_THICKNESS;
	static constexpr int OK_BUTTON_LEFT = WINDOW_WIDTH / 2;

	static constexpr int CANCEL_BUTTON_TOP = EXPLORER_TOP + EXPLORER_HEIGHT +
		FileExplorer::OUTLINE_THICKNESS + SimpleButton::OUTLINE_THICKNESS;
	static constexpr int CANCEL_BUTTON_LEFT = OK_BUTTON_LEFT + OK_BUTTON_WIDTH + BUTTON_OFFSET;

	explicit FileDialog();

	std::optional<std::filesystem::path> chosenFile()const;
protected:
	void handle(const sf::Event& event) override;
private:
	std::optional<std::filesystem::path> chosen_file_ = std::nullopt;
};

