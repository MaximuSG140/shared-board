#pragma once
#include "pch.h"
#include "IMouseAccessible.h"

class IMouseHoldable
    : public IMouseAccessible
{
public:
    void proceedHolding(sf::Vector2i mouse_position);
protected:
    virtual void onHold() = 0;
    virtual void onHoldEnded() = 0;
};

