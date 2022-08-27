#pragma once
#include "pch.h"

#include "Geometry.h"

class ImageRedactor
{
public:
	constexpr static int MAXIMAL_ALPHA_VALUE = std::numeric_limits<decltype(sf::Color::a)>::max();

	ImageRedactor();
	explicit ImageRedactor(int width,
		int height);

	void loadImage(const std::string& file_name) const;
	void loadImage(std::unique_ptr<sf::Image> image);

	[[nodiscard]] sf::Image getImageCopy()const;
	sf::Image& image();
	[[nodiscard]] const sf::Image& image() const;
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
	void drawNearVerticalSegment(sf::Vector2i start,
	                         sf::Vector2i end,
	                         const DrawPointT& draw_point);
	template<typename DrawPointT>
	void drawNearHorizontalSegment(sf::Vector2i start,
		sf::Vector2i end,
		const DrawPointT& draw_point);


	[[nodiscard]] bool isValidPoint(sf::Vector2i point)const;
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

	auto direction = second - first;
	auto angle_from_horizon = CalculateAngle(direction,
		{ 1, 0 });

	if(angle_from_horizon > PI_VALUE / 4 &&
		angle_from_horizon < PI_VALUE * 3 / 4)
	{
		drawNearVerticalSegment(first,
			second,
			draw_point);
	}
	else
	{
		drawNearHorizontalSegment(first,
			second,
			draw_point);
	}

	
}

template<typename DrawPointT>
void ImageRedactor::drawNearVerticalSegment(sf::Vector2i start,
	sf::Vector2i end,
	const DrawPointT& draw_point)
{
	if (start.y > end.y)
	{
		std::swap(start,
			end);
	}
	auto horizontal_shift = end.x - start.x;
	auto shift_per_pixel = static_cast<float>(horizontal_shift) / static_cast<float>(end.y - start.y);
	for (int y = start.y; y <= end.y; ++y)
	{
		draw_point(static_cast<int>(static_cast<float>(start.x) + 0.5f +
				static_cast<float>(y - start.y) * shift_per_pixel),
			y);
	}
}

template <typename DrawPointT>
void ImageRedactor::drawNearHorizontalSegment(sf::Vector2i start,
	sf::Vector2i end,
	const DrawPointT& draw_point)
{
	if (start.x > end.x)
	{
		std::swap(start,
			end);
	}
	auto vertical_shift = end.y - start.y;
	auto shift_per_pixel = static_cast<float>(vertical_shift) / static_cast<float>(end.x - start.x);
	for (int x = start.x; x <= end.x; ++x)
	{
		draw_point(x,
			static_cast<int>(static_cast<float>(start.y) + 0.5f + 
				static_cast<float>(x - start.x) * shift_per_pixel));
	}
}
