#pragma once
#include "framework/include/Widget/Traits/IMouseAccessible.h"


class IMouseClickable
    : public IMouseAccessible
{
public:
    void startClick(sf::Vector2i mouse_position);
    void endClick(sf::Vector2i mouse_position);
protected:
    virtual void onClick(sf::Vector2i position) = 0;
private:
    bool click_started_ = false;
};

