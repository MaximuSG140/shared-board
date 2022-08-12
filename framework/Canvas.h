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

    void selectPencil(int thickness,
        const sf::Color& color = sf::Color::Black);
    void selectBrush(int thickness,
        const sf::Color& color = sf::Color::Black);
    void unSelectAllTools();
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

    inline auto static pencil_action = [&,
        previous_x = 0,
        previous_y = 0,
        first = true]
        (const sf::Vector2i position)mutable
    {
        if (!first)
        {
            redactor_.drawSegment({ previous_x, previous_y },
                position,
                &ImageRedactor::drawPoint,
                thickness,
                color);
            first = false;
        }
        previous_x = position.x;
        previous_y = position.y;
    };
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

