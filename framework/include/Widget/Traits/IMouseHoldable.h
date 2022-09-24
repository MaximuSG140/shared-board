#pragma once
#include "framework/include/pch.h"
#include "framework/include/Widget/Traits/IMouseAccessible.h"

class IMouseHoldable
    : public IMouseAccessible
{
public:
    void startHolding(sf::Vector2i mouse_position);
    void proceedHolding(sf::Vector2i mouse_position);
    void endHolding(sf::Vector2i mouse_position);
protected:
    virtual void onHold(sf::Vector2i mouse_position) = 0;
    virtual void onHoldEnded() = 0;
private:
    bool holding_ = false;
};

