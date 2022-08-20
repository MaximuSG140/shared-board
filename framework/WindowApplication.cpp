#include "pch.h"
#include "WindowApplication.h"

#include "logger/log.h"

void WindowApplication::run()
{
	Logger::log(Logger::LogLevel::INFO,
		"Window application started");
	main_window_.clear(sf::Color::White);
	render();
	sf::Event received_event{};
	while(main_window_.isOpen())
	{
		main_window_.waitEvent(received_event);
		Logger::log(Logger::LogLevel::DEBUG,
			"Event dispatched");
		baseHandle(received_event);
		Logger::log(Logger::LogLevel::DEBUG,
			"Polling next event");
	}
	Logger::log(Logger::LogLevel::INFO,
		"Application exited");
}

void WindowApplication::setWindowSize(const sf::Vector2u size)
{
	main_window_.setSize(size);
}

sf::Vector2u WindowApplication::windowSize() const
{
	return main_window_.getSize();
}

void WindowApplication::render()
{
	Logger::log(Logger::LogLevel::INFO,
		"Rendering changed widgets");
	main_window_.clear(sf::Color::White);
	for(const auto& widget : widgets_)
	{
		//if(!widget->valid())
		{
			Logger::log(Logger::LogLevel::DEBUG,
			"Rendering " + widget->name());
			main_window_.draw(*widget);
		}
	}
	main_window_.display();
}

void WindowApplication::baseHandle(const sf::Event& event)
{
	switch(event.type)
	{
	case sf::Event::MouseWheelScrolled:
		Logger::log(Logger::LogLevel::DEBUG,
			"Handling 'MouseWheelScrolled' event");
		for(auto widget : scrollable_widgets_)
		{
			widget->scroll(event.mouseWheel.delta);
		}
	case sf::Event::KeyPressed:
		Logger::log(Logger::LogLevel::DEBUG,
			"Handling 'KeyPressed' event");
		for(auto widget : keyboard_widgets_)
		{
			widget->handleKeyPress(event.key);
		}
	case sf::Event::Closed:
		Logger::log(Logger::LogLevel::DEBUG,
			"Handling 'Closed' event");
		main_window_.close();
		break;
	case sf::Event::Resized:
		{
			Logger::log(Logger::LogLevel::DEBUG,
			"Handling 'Resized' event");
			auto old_size = main_window_.getSize();
			sf::Vector2u new_size{ event.size.width,
				event.size.height };
			main_window_.setSize({ event.size.width,
				event.size.height });
			sf::Vector2f proportions{ static_cast<float>(new_size.x) / old_size.x,
				static_cast<float>(new_size.y) / old_size.y };
			for (const auto& widget : widgets_)
			{
				widget->scale(proportions);
			}
			break;
		}
	case sf::Event::MouseButtonPressed:
		Logger::log(Logger::LogLevel::DEBUG,
			"Handling 'MouseButtonPressed' event");
		for(auto widget : clickable_widgets_)
		{
			widget->startClick({ event.mouseButton.x,
				event.mouseButton.y });
		}
		for(auto widget : selectable_widgets_)
		{
			widget->interact({ event.mouseButton.x,
				event.mouseButton.y });
		}
		for (auto widget : holdable_widgets_)
		{
			widget->startHolding({ event.mouseButton.x,
				event.mouseButton.y });
		}
		break;
	case sf::Event::MouseButtonReleased:
		Logger::log(Logger::LogLevel::DEBUG,
			"Handling 'MouseButtonReleased' event");
		for (auto widget : clickable_widgets_)
		{
			widget->endClick({ event.mouseButton.x,
				event.mouseButton.y });
		}
		for(auto widget : holdable_widgets_)
		{
			widget->endHolding({event.mouseButton.x,
				event.mouseButton.y});
		}
		break;
	case sf::Event::MouseMoved:
		Logger::log(Logger::LogLevel::DEBUG,
			"Handling 'MouseMoved' event");
		for(auto widget : holdable_widgets_)
		{
			widget->proceedHolding({ event.mouseMove.x,
				event.mouseMove.y });
		}
		break;
	default:
		return;
	}
	handle(event);
	render();
}
