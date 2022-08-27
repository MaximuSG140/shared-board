#pragma once
#include "pch.h"

constexpr auto PI_VALUE = 3.14159265358979323846;

double ConvertToRadians(double degrees);
double ConvertToDegrees(double radians);

double CalculateEuclideanDistance(sf::Vector2i first,
	sf::Vector2i second);

double CalculateLength(sf::Vector2i vector);

double CalculateDotProduct(sf::Vector2i first,
	sf::Vector2i second);

double CalculateAngle(sf::Vector2i first,
	sf::Vector2i second);