#pragma once
#include "drawing/ImageRedactor.h"

class ICanvasTool
{
public:
	virtual void hold(ImageRedactor& redactor,
		sf::Vector2i position) = 0;
	virtual void unHold(ImageRedactor& redactor) = 0;
	virtual void click(ImageRedactor& redactor,
		sf::Vector2i position) = 0;
	virtual ~ICanvasTool() = default;
};

