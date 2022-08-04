#pragma once
#include "pch.h"
#include "Application.h"
class WindowApplication :
    public Application
{
public:
    template<typename... T>
    explicit WindowApplication(T&&... window_parameters);
    void run() final;
protected:
    virtual void handle(const sf::Event& event) = 0;
private:
    sf::RenderWindow main_window_;
};

template <typename ... T>
WindowApplication::WindowApplication(T&&... window_parameters)
	:main_window_(std::forward<T>(window_parameters)...)
{}

