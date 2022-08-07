#pragma once
#include "IMouseAccessible.h"


class IMouseClickable
    :public IMouseAccessible
{
public:
    void startClick(sf::Vector2i mouse_position);
    void endClick(sf::Vector2i mouse_position);
protected:
    virtual void onClick() = 0;
private:
    bool click_started_ = false;
};

