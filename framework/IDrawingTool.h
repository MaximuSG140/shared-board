#pragma once
#include "drawing/ImageRedactor.h"

class IDrawingTool
{
public:
	virtual void hold(ImageRedactor& redactor, sf::Vector2i position) = 0;
	virtual void unHold(ImageRedactor& redactor) = 0;
	virtual void click(ImageRedactor& redactor, sf::Vector2i position) = 0;
	virtual ~IDrawingTool() = default;
};

