#include "pch.h"
#include "Geometry.h"

double CalculateEuclideanDistance(const sf::Vector2i first,
                                  const sf::Vector2i second)
{
	return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}
