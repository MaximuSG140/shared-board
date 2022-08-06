#pragma once
#include "Widget.h"


class ClickableWidget :
    public Widget
{
public:
    explicit ClickableWidget(const std::string& name,
        sf::Vector2i position,
        sf::Vector2u size);
    explicit ClickableWidget(sf::Vector2i position,
        sf::Vector2u size);

    void startClick(sf::Vector2i mouse_position);
    void endClick(sf::Vector2i mouse_position);
protected:
    virtual void onClick()const = 0;
private:
    bool click_started_ = false;
};

