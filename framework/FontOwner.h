#pragma once

class FontOwner
{
public:
	explicit FontOwner(const std::string& font_source);
	const sf::Font& get()const;
private:
	sf::Font item_;
};

