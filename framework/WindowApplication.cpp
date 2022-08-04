#include "pch.h"
#include "WindowApplication.h"

void WindowApplication::run()
{
	sf::Event received_event{};
	while (main_window_.pollEvent(received_event))
	{
		handle(received_event);
	}
}
