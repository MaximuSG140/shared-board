#include "pch.h"
#include "Widget/Canvas/Tools/CameraMoveTool.h"

#include "Widget/Canvas/Canvas.h"

CameraMoveTool::CameraMoveTool(Canvas& owner)
	:owner_(owner)
{}

void CameraMoveTool::hold(const sf::Vector2i position)
{
	if(previous_mouse_position_.has_value())
	{
		owner_.moveView(previous_mouse_position_.value() - owner_.computeImagePosition(position));
	}
	previous_mouse_position_ = owner_.computeImagePosition(position);
}

void CameraMoveTool::unHold()
{
	previous_mouse_position_ = std::nullopt;
}

void CameraMoveTool::click(sf::Vector2i position)
{}
