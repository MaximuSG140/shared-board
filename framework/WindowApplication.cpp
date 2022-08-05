#include "pch.h"
#include "WindowApplication.h"

#include "logger/log.h"

void WindowApplication::run()
{
	Logger::log(Logger::LogLevel::INFO, "Window application started");
	sf::Event received_event{};
	while (main_window_.pollEvent(received_event))
	{
		Logger::log(Logger::LogLevel::DEBUG, "Event dispatched");
		handle(received_event);
		Logger::log(Logger::LogLevel::DEBUG, "Polling next event");
	}
	Logger::log(Logger::LogLevel::INFO, "Application exited");
}
