#pragma once
#include "pch.h"

class ImageRedactor
{
public:
	constexpr static int MAXIMAL_ALPHA_VALUE = std::numeric_limits<decltype(sf::Color::a)>::max();

	ImageRedactor();
	explicit ImageRedactor(int width,
		int height);

	void loadImage(const std::string& file_name) const;
	void loadImage(std::unique_ptr<sf::Image> image);

	sf::Image getImageCopy()const;
	std::unique_ptr<sf::Image> acquireImage();

	void drawPoint(sf::Vector2i position,
	               const sf::Color& color = sf::Color::Black);
	void drawPoint(sf::Vector2i position,
	               int thickness,
	               const sf::Color& color = sf::Color::Black);
	void drawSmoothPoint(sf::Vector2i position,
		int thickness,
		const sf::Color& color = sf::Color::Black);

	template<typename DrawPointT>
	void drawSegment(sf::Vector2i first,
	                 sf::Vector2i second,
	                 const DrawPointT& draw_point);
	void drawSegment(sf::Vector2i first,
	                 sf::Vector2i second,
	                 void (ImageRedactor::*draw_point)(sf::Vector2i,
	                                                   int,
	                                                   const sf::Color&),
	                 int thickness,
	                 const sf::Color& color);
	
private:
	template<typename DrawPointT>
	void drawVerticalSegment(sf::Vector2i start,
	                         sf::Vector2i end,
	                         const DrawPointT& draw_point);
	bool isValidPoint(sf::Vector2i point)const;
	void drawSmoothPixel(int x,
	                     int y,
	                     const sf::Color& color);

	std::unique_ptr<sf::Image> image_;
};

