#pragma once
#include "framework/include/App/WindowApplication.h"


class ErrorMessage final :
    public WindowApplication
{
public:
	static constexpr unsigned DEFAULT_WINDOW_WIDTH = 400;
	static constexpr unsigned DEFAULT_WINDOW_HEIGHT = 300;

	static constexpr int DEFAULT_OFFSET = 10;

	static constexpr unsigned DEFAULT_TEXT_BOX_HEIGHT = 200;

	static constexpr float DEFAULT_OK_BUTTON = 1. / 4;

	explicit ErrorMessage(const std::string& name,
		const std::string& message);
protected:

	void handle(const sf::Event& event) override;
};

