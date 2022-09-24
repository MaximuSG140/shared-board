#pragma once
#include "pch.h"


class SlicedText final
	: public sf::Drawable
{
public:
	enum class TextAlignment
	{
		LEFT,
		CENTER,
		RIGHT,
	};

	explicit SlicedText(const std::string& text);
protected:
	void draw(sf::RenderTarget& target,
		sf::RenderStates states) const override;
private:
	std::vector<std::vector<std::string>> paragraphs_;
	unsigned letter_size_ = 30;
	TextAlignment align_;
};

