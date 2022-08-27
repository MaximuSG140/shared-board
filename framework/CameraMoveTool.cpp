#include "pch.h"
#include "CameraMoveTool.h"

#include "Canvas.h"

CameraMoveTool::CameraMoveTool(Canvas& owner)
	:owner_(owner)
{}

void CameraMoveTool::hold(const sf::Vector2i position)
{
	if(previous_mouse_position_.has_value())
	{
		owner_.moveView(previous_mouse_position_.value() - position);
	}
	previous_mouse_position_ = position;
}

void CameraMoveTool::unHold()
{
	previous_mouse_position_ = std::nullopt;
}

void CameraMoveTool::click(sf::Vector2i position)
{}
