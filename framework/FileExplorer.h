#pragma once
#include "DirectoryElementFactory.h"
#include "IFileExplorerElement.h"
#include "RectangleWidget.h"
#include "IMouseClickable.h"
#include "IScrollable.h"


class FileExplorer final :
    public RectangleWidget, public IMouseClickable, public IScrollable
{
public:
    static constexpr unsigned ELEMENT_HEIGHT = 50;
    inline static const sf::Color BODY_COLOR = { 230,
	    230,
	    230 };
    inline static const sf::Color OUTLINE_COLOR = { 225,
	    225,
	    225 };
    static constexpr int OUTLINE_THICKNESS = 3;

    explicit FileExplorer(const std::string& name,
                          sf::Vector2i position,
                          sf::Vector2u size,
                          std::filesystem::path start_directory = std::filesystem::current_path());
    std::filesystem::path chosenFile()const;

    [[nodiscard]] bool containsCursor(sf::Vector2i cursor_point) const override;
    void scroll(int ticks) override;
protected:
    void onClick(sf::Vector2i click_position) override;
	void draw(sf::RenderTarget& target,
        sf::RenderStates states) const override;
private:
    void loadElements();

    std::filesystem::path current_directory_;
    std::filesystem::path chosen_file_;
    inline constexpr static DirectoryElementFactory FACTORY{};
    std::vector<std::unique_ptr<IFileExplorerElement>> directory_elements_;
    int first_displayed_element_number_ = 0;
};

