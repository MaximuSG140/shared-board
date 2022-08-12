#pragma once
#include "IMouseClickable.h"
#include "IMouseHoldable.h"
#include "RectangleWidget.h"

#include "drawing/ImageRedactor.h"

class Canvas final :
    public RectangleWidget, IMouseClickable, IMouseHoldable
{
public:
    explicit Canvas(const std::string& name,
        sf::Vector2i position,
        sf::Vector2u size);
    explicit Canvas(sf::Vector2i position,
        sf::Vector2u size);

    template<typename F>
    void setHoldAction(F&& function);

    template<typename F>
    void setHoldEndedAction(F&& function);

    template<typename F>
    void setClickAction(F&& function);
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void onClick(sf::Vector2i mouse_position) override;
    void onHold(sf::Vector2i mouse_position) override;
    void onHoldEnded() override;
private:
    ImageRedactor redactor_;
    std::function<void(sf::Vector2i)> hold_action_ = [](sf::Vector2i){};
    std::function<void()> hold_ended_action_ = []() {};
    std::function<void(sf::Vector2i)> click_action_ = [](sf::Vector2i) {};
};

template <typename F>
void Canvas::setHoldAction(F&& function)
{
    hold_action_ = std::forward<F>(function);
}

template <typename F>
void Canvas::setHoldEndedAction(F&& function)
{
    hold_ended_action_ = std::forward<F>(function);
}

template <typename F>
void Canvas::setClickAction(F&& function)
{
    click_action_ = std::forward<F>(function);
}

