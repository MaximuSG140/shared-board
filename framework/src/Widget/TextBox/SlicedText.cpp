#include "pch.h"
#include "framework/include/Widget/TextBox/SlicedText.h"


SlicedText::SlicedText(const std::string& text)
{
	std::vector<std::string> words;
	std::stringstream text_stream(text);
	while(!text_stream.eof())
	{
		std::string line;
		std::getline(text_stream,
			line);
		std::stringstream line_stream(line);
		while(!line_stream.eof())
		{
			std::string word;
			line_stream >> word;
			words.push_back(word);
		}
		paragraphs_.push_back(std::move(words));
		words.clear();
	}
}
