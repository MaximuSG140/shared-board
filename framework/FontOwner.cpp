#include "pch.h"
#include "FontOwner.h"

#include "logger/log.h"

FontOwner::FontOwner(const std::string& font_source)
{
	Logger::log(Logger::LogLevel::INFO, "Loading default font...");
	if(!item_.loadFromFile(font_source))
	{
		std::abort();
	}
	Logger::log(Logger::LogLevel::INFO,
		"Default font loaded");
}

const sf::Font& FontOwner::get() const
{
	return item_;
}
