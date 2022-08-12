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

template <typename DrawPointT>
void ImageRedactor::drawSegment(sf::Vector2i first,
	sf::Vector2i second,
	const DrawPointT& draw_point)
{
	if (!isValidPoint(first) || !isValidPoint(second))
	{
		throw std::out_of_range("Attempt to draw pixel out of image bounds");
	}
	if (first.x == second.x)
	{
		drawVerticalSegment(first,
			second,
			draw_point);
		return;
	}
	if (first.x > second.x)
	{
		std::swap(first, second);
	}
	auto vertical_shift = second.y - first.y;
	auto shift_per_pixel = vertical_shift / static_cast<float>(second.x - first.x);
	for (int x = first.x; x <= second.x; ++x)
	{
		draw_point(x,
			static_cast<int>(first.y + 0.5f + (x - first.x) * shift_per_pixel));
	}
}

template<typename DrawPointT>
void ImageRedactor::drawVerticalSegment(const sf::Vector2i start,
	const sf::Vector2i end,
	const DrawPointT& draw_point)
{
	assert(start.x == end.x && "Segment should be vertical");
	auto upper_point = std::min(start.y, end.y);
	auto lower_point = std::max(start.y, end.y);
	auto x_coordinate = start.x;
	for (int i = upper_point; i <= lower_point; ++i)
	{
		draw_point(x_coordinate, i);
	}
}
