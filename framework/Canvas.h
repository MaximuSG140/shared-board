#pragma once
#include "IMouseClickable.h"
#include "IMouseHoldable.h"
#include "Widget.h"


class Canvas final :
    public Widget, IMouseClickable, IMouseHoldable
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

	[[nodiscard]] bool containsCursor(sf::Vector2i cursor_point) const override;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void onClick() override;
    void onHold() override;
    void onHoldEnded() override;
private:
    sf::Image canvas_image_;
    std::function<void(sf::Vector2i)> hold_action_;
    std::function<void(sf::Vector2i)> hold_ended_action_;
    std::function<void(sf::Vector2i)> click_action_;
};

template <typename F>
void Canvas::setHoldAction(F&& function)
{
    hold_action_ = std::forward<F>(function);
}

