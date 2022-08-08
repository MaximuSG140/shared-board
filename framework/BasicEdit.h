#pragma once
#include "IKeyboardListener.h"
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

	void handleKeyPress(const sf::Event::KeyEvent& event) override;
    [[nodiscard]] bool selected() const override;
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void onSelect() override;
    void onUnSelect() override;
public:
    inline static const sf::Color OUTLINE_COLOR{ 220, 220, 220 };
    inline static const sf::Color SELECTED_OUTLINE_COLOR{ 200, 200, 200 };
    inline static const sf::Color BODY_COLOR{240, 240, 240};
    inline static const sf::Color TEXT_COLOR{0, 0, 0};
    constexpr static int OUTLINE_THICKNESS = 3;
private:
    [[nodiscard]] unsigned calculateLetterSize()const;
    [[nodiscard]] sf::Vector2i calculateTextPosition()const;

    std::string text_;
    bool editing_ = false;
};

