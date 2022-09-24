#pragma once

class ICanvasTool
{
public:
	virtual void hold(sf::Vector2i position) = 0;
	virtual void unHold() = 0;
	virtual void click(sf::Vector2i position) = 0;
	virtual ~ICanvasTool() = default;
};

