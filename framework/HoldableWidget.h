#pragma once
#include "pch.h"
#include "Widget.h"
class HoldableWidget :
    public Widget
{
public:
    explicit HoldableWidget(const std::string& widget_name,
        sf::Vector2i position,
        sf::Vector2u size);
    explicit HoldableWidget(sf::Vector2i position,
        sf::Vector2u size);

    void proceedHolding(sf::Vector2i mouse_position);
protected:
    virtual void onHold() = 0;
};

