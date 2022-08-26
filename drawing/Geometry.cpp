#include "pch.h"
#include "Geometry.h"



double ConvertToRadians(const double degrees)
{
	return degrees * PI_VALUE / 180;
}

double ConvertToDegrees(const double radians)
{
	return radians / PI_VALUE * 180;
}

double CalculateEuclideanDistance(const sf::Vector2i first,
                                  const sf::Vector2i second)
{
	return sqrt(pow(first.x - second.x,
		2) + pow(first.y - second.y,
			2));
}

double CalculateLength(const sf::Vector2i vector)
{
	return CalculateEuclideanDistance({ 0, 0 },
		vector);
}

double CalculateDotProduct(const sf::Vector2i first,
                           const sf::Vector2i second)
{
	return first.x * second.x + first.y * second.y;
}

double CalculateAngle(const sf::Vector2i first,
                      const sf::Vector2i second)
{
	auto dot_product = CalculateDotProduct(first,
		second);
	auto first_length = CalculateLength(first);
	auto second_length = CalculateLength(second);
	return acos(dot_product / first_length / second_length);
}
