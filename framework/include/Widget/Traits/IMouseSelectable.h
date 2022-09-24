#pragma once
#include "IMouseAccessible.h"


class IMouseSelectable
	:public virtual IMouseAccessible
{
public:
	void interact(sf::Vector2i mouse_position);
	[[nodiscard]] virtual bool selected()const = 0;
protected:
	virtual void onSelect() = 0;
	virtual void onUnSelect() = 0;
};

