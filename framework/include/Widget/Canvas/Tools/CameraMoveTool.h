#pragma once
#include "ICanvasTool.h"
class Canvas;

class CameraMoveTool final :
    public ICanvasTool
{
public:
	explicit CameraMoveTool(Canvas& owner);

	void hold(sf::Vector2i position) override;
	void unHold() override;
	void click(
		sf::Vector2i position) override;
private:
	Canvas& owner_;
	std::optional<sf::Vector2i> previous_mouse_position_;
};

