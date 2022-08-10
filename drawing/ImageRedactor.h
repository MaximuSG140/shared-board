#pragma once
#include "pch.h"


class ImageRedactor
{
public:
	ImageRedactor() = default;
	explicit ImageRedactor(int width,
		int height);

	void loadImage(const std::string& file_name);
	void loadImage(std::unique_ptr<sf::Image> image);

	sf::Image getImageCopy()const;
	std::unique_ptr<sf::Image> acquireImage();

	void drawPoint(sf::Vector2i position,
		const sf::Color& color = sf::Color::Black);
	void drawPoint(sf::Vector2i position,
		unsigned thickness,
		const sf::Color& color = sf::Color::Black);

	void drawSegment(sf::Vector2i start,
		sf::Vector2i end,
		const sf::Color& color = sf::Color::Black);
	void drawSegment(sf::Vector2i start,
		sf::Vector2i end,
		unsigned thickness,
		const sf::Color& color = sf::Color::Black);
	
private:
	std::unique_ptr<sf::Image> image_;
};

