#pragma once
#include "pch.h"

#include "ICanvasTool.h"
#include "IMouseClickable.h"
#include "IMouseHoldable.h"
#include "RectangleWidget.h"

#include "drawing/ImageRedactor.h"

class Canvas final :
    public RectangleWidget, public IMouseClickable, public IMouseHoldable
{
public:
    constexpr static int OUTLINE_THICKNESS = 3;

    explicit Canvas(const std::string& name,
        sf::Vector2i position,
        sf::Vector2u size);
    explicit Canvas(sf::Vector2i position,
        sf::Vector2u size);

    void selectPencil(int thickness,
        const sf::Color& color = sf::Color::Black);
    void selectBrush(int thickness,
        const sf::Color& color = sf::Color::Black);
    void selectViewer();

    void doubleScale();
    void lowerScale();

    void moveView(sf::Vector2i delta);

	[[nodiscard]] bool containsCursor(sf::Vector2i cursor_point) const override;

    void loadImage(const std::filesystem::path& path_to_image) const;
    void saveImage(const std::filesystem::path& path_to_image);

    ImageRedactor& redactor();
    const ImageRedactor& redactor()const;
protected:
    void draw(sf::RenderTarget& target,
        sf::RenderStates states) const override;
    void onClick(sf::Vector2i mouse_position) override;
    void onHold(sf::Vector2i mouse_position) override;
    void onHoldEnded() override;
private:
    ImageRedactor redactor_;
    std::unique_ptr<ICanvasTool> tool_;
    sf::Vector2i camera_position_;
    float scale_modifier_ = 1;
};
