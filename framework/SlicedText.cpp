#include "pch.h"
#include "SlicedText.h"


SlicedText::SlicedText(const std::string& text)
{
	std::vector<std::string> words;
	std::stringstream stream(text);
	while(!stream.eof())
	{
		std::string word;
		stream >> word;
		words.push_back(word);
	}
}
