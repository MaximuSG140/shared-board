#pragma once
class TextureOwner
{
public:
	explicit TextureOwner(const std::string& texture_file_name);
	const sf::Texture& get() const;
private:
	sf::Texture item_;
};

