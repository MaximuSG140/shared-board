#include "pch.h"
#include "FileExplorer.h"

#include "DirectoryElement.h"

FileExplorer::FileExplorer(const std::string& name,
                           const sf::Vector2i position,
                           const sf::Vector2u size,
                           std::filesystem::path start_directory)
		:RectangleWidget("Explorer " + name,
			position,
			size),
	current_directory_(std::move(start_directory))
{
	loadElements();
}

std::filesystem::path FileExplorer::chosenFile() const
{
	return chosen_file_;
}

void FileExplorer::loadElements()
{
	namespace fs = std::filesystem;
	directory_elements_.clear();
	directory_elements_.push_back(std::make_unique<DirectoryElement>(".."));
	directory_elements_.back()->setSize({ size().x,
			ELEMENT_HEIGHT });

	fs::directory_iterator directory_files(current_directory_);
	for (const auto& file : directory_files)
	{
		auto element = FACTORY.getElement(file);
		element->setSize({ size().x,
			ELEMENT_HEIGHT });
		directory_elements_.push_back(std::move(element));
	}
}

bool FileExplorer::containsCursor(const sf::Vector2i cursor_point) const
{
	return RectangleWidget::containsCursor(cursor_point);
}

void FileExplorer::scroll(const int ticks)
{
	first_displayed_element_number_ -= ticks;
}

void FileExplorer::onClick(const sf::Vector2i click_position)
{
	namespace fs = std::filesystem;
	auto relative_position = click_position - position();
	int number_on_display = relative_position.y / ELEMENT_HEIGHT;
	int chosen_file_number = number_on_display + first_displayed_element_number_;
	if(chosen_file_number >= directory_elements_.size())
	{
		return;
	}
	auto chosen_file_path = current_directory_ / directory_elements_[chosen_file_number]->fileName();
	fs::directory_entry chosen_file_info(chosen_file_path);
	if(chosen_file_info.is_directory())
	{
		current_directory_ = chosen_file_path;
		loadElements();
	}
	else
	{
		chosen_file_ = chosen_file_path;
	}
}

void FileExplorer::draw(sf::RenderTarget& target,
                        const sf::RenderStates states) const
{
	auto body_size = size();
	auto body_position = position();
	sf::RectangleShape body({static_cast<float>(body_size.x),
		static_cast<float>(body_size.y)});
	body.setPosition({ static_cast<float>(body_position.x),
		static_cast<float>(body_position.y) });
	body.setFillColor(BODY_COLOR);
	body.setOutlineThickness(OUTLINE_THICKNESS);
	body.setOutlineColor(OUTLINE_COLOR);
	target.draw(body, states);
	int elements_fit = body_size.y / ELEMENT_HEIGHT;
	for(int i = 0; i < std::min<int>(elements_fit, 
		directory_elements_.size() - first_displayed_element_number_); ++i)
	{
		directory_elements_[first_displayed_element_number_ + i]->
			setPosition(body_position + sf::Vector2i{ 0, static_cast<int>(i * ELEMENT_HEIGHT) });
		directory_elements_[first_displayed_element_number_ + i]->
			setSize({body_size.x, ELEMENT_HEIGHT});
		target.draw(*directory_elements_[first_displayed_element_number_ + i],
			states);
	}
	RectangleWidget::draw(target, states);
}
