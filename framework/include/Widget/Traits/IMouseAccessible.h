#pragma once
#include "framework/include/pch.h"


class IMouseAccessible
{
public:
	[[nodiscard]] virtual bool containsCursor(sf::Vector2i cursor_point)const = 0;
	virtual ~IMouseAccessible() = default;
};

