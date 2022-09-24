#include "pch.h"
#include "Resource/TextureOwner.h"

#include "logger/log.h"

TextureOwner::TextureOwner(const std::string& texture_file_name)
{
	if(!item_.loadFromFile(texture_file_name))
	{
		std::abort();
	}
	Logger::log(Logger::LogLevel::INFO, "Texture loaded from " + texture_file_name);
}

const sf::Texture& TextureOwner::get() const
{
	return item_;
}
