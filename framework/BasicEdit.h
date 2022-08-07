#pragma once
#include "IKeyboardListener.h"
#include "IMouseClickable.h"
#include "IMouseSelectable.h"


class BasicEdit :
    public Widget, IMouseSelectable, IKeyboardListener
{
public:
    explicit BasicEdit(const std::string& name,
        sf::Vector2i position,
        sf::Vector2u size);

    explicit BasicEdit(sf::Vector2i position,
        sf::Vector2u size);

    void setText(std::string new_text);
    [[nodiscard]] std::string text()const;

    [[nodiscard]] bool containsCursor(sf::Vector2i point_coordinates) const override;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    inline static const sf::Color OUTLINE_COLOR{ 220, 220, 220 };
    inline static const sf::Color BODY_COLOR{240, 240, 240};
    constexpr static int OUTLINE_THICKNESS = 3;
private:
    std::string text_;
    bool editing_;
};

