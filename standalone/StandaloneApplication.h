#pragma once
#include "framework/Canvas.h"
#include "framework/WindowApplication.h"

class StandaloneApplication final
	: public WindowApplication
{
public:
	constexpr static int DEFAULT_WINDOW_WIDTH = 1280;
	constexpr static int DEFAULT_WINDOW_HEIGHT = 840;
	constexpr static int DEFAULT_TOP_TOOL_PANE_HEIGHT = 120;
	constexpr static int DEFAULT_BOTTOM_LOOT_PANE_HEIGHT = 120;

	StandaloneApplication();

	void handle(const sf::Event& event) override;
};

