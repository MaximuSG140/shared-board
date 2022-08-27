#include "pch.h"
#include "ImageRedactor.h"
#include "Geometry.h"

ImageRedactor::ImageRedactor()
	: image_(std::make_unique<sf::Image>())
{}

ImageRedactor::ImageRedactor(const int width,
                             const int height)
	: image_(std::make_unique<sf::Image>())
{
	image_->create(width,
		height,
		sf::Color::White);
}

void ImageRedactor::loadImage(const std::string& file_name) const
{
	image_->loadFromFile(file_name);
}

void ImageRedactor::loadImage(std::unique_ptr<sf::Image> image)
{
	image_.swap(image);
}

sf::Image ImageRedactor::getImageCopy() const
{
	return *image_;
}

sf::Image& ImageRedactor::image()
{
	return *image_;
}

const sf::Image& ImageRedactor::image() const
{
	return *image_;
}

std::unique_ptr<sf::Image> ImageRedactor::acquireImage()
{
	auto default_image = std::make_unique<sf::Image>();
	default_image.swap(image_);
	return default_image;
}

void ImageRedactor::drawPoint(const sf::Vector2i position,
                              const sf::Color& color)
{
	if(!isValidPoint(position))
	{
		throw std::out_of_range("Attempt to draw pixel out of image bounds");
	}
	image_->setPixel(position.x,
		position.y,
		color);
}

void ImageRedactor::drawPoint(const sf::Vector2i position,
                              const int thickness,
                              const sf::Color& color)
{
	if (!isValidPoint(position))
	{
		throw std::out_of_range("Attempt to draw pixel out of image bounds");
	}
	auto image_size = image_->getSize();
	auto left_bound = std::max(position.x - thickness,
		0);
	auto right_bound = std::min(position.x + thickness,
		static_cast<int>(image_size.x));
	auto upper_bound = std::max(position.y - thickness,
		0);
	auto bottom_bound = std::min(position.y + thickness,
		static_cast<int>(image_size.y));
	for(int x = left_bound; x < right_bound; ++x)
	{
		for(int y = upper_bound; y < bottom_bound; ++y)
		{
			if(CalculateEuclideanDistance(position, {x, y}) < thickness)
			{
				image_->setPixel(x, y, color);
			}
		}
	}
}

void ImageRedactor::drawSmoothPoint(const sf::Vector2i position,
                                    const int thickness,
                                    const sf::Color& color)
{
	if(!isValidPoint(position))
	{
		throw std::out_of_range("Attempt to draw pixel out of image bounds");
	}
	auto image_size = image_->getSize();
	auto left_bound = std::max(position.x - thickness,
		0);
	auto right_bound = std::min(position.x + thickness,
		static_cast<int>(image_size.x));
	auto upper_bound = std::max(position.y - thickness,
		0);
	auto bottom_bound = std::min(position.y + thickness,
		static_cast<int>(image_size.y));
	for (int x = left_bound; x < right_bound; ++x)
	{
		for (int y = upper_bound; y < bottom_bound; ++y)
		{
			if (auto distance = CalculateEuclideanDistance(position,
			                                               { x, y });
				distance < thickness)
			{
				auto muted_color = color;
				muted_color.a = static_cast<sf::Uint8>(color.a * (1 - distance / thickness));
				image_->setPixel(x,
					y,
					muted_color);
			}
		}
	}
}

void ImageRedactor::drawSegment(const sf::Vector2i first,
                                const sf::Vector2i second,
                                void (ImageRedactor::* draw_point)(sf::Vector2i,
                                                                   int,
                                                                   const sf::Color&),
                                const int thickness,
                                const sf::Color& color)
{
	drawSegment(first,
		second,
		[=](const int x, 
			const int y)
	{
		(this->*draw_point)({x, y},
			thickness,
			color);
	});
}

bool ImageRedactor::isValidPoint(const sf::Vector2i point) const
{
	auto image_size = image_->getSize();
	return static_cast<unsigned>(point.x) < image_size.x ||
		static_cast<unsigned>(point.y) < image_size.y;
}

void ImageRedactor::drawSmoothPixel(const int x,
                                    const int y,
                                    const sf::Color& color)
{
	auto current_color = image_->getPixel(x,
		y);

	sf::Color result_color;
	result_color.a = static_cast<sf::Uint8>(static_cast<int>(current_color.a) + color.a - 
		static_cast<int>(current_color.a) * color.a / MAXIMAL_ALPHA_VALUE);
	auto calculate_color_component = [=](auto new_component,
		auto old_component)->auto
	{
		return static_cast<sf::Uint8>((static_cast<int>(old_component) * current_color.a -
			static_cast<int>(new_component) * result_color.a * current_color.a / MAXIMAL_ALPHA_VALUE +
			static_cast<int>(new_component) * result_color.a) / MAXIMAL_ALPHA_VALUE);
	};
	result_color.r = calculate_color_component(color.r,
		current_color.r);
	result_color.g = calculate_color_component(color.g,
		current_color.g);
	result_color.b = calculate_color_component(color.b,
		current_color.b);
	image_->setPixel(x,
		y,
		result_color);
}


