#pragma once



class SlicedText
{
public:
	explicit SlicedText(const std::string& text);

	sf::Text& operator[](int index);
	const sf::Text& operator[](int index)const;
private:
	

	std::vector<sf::Text> lines_;
};

