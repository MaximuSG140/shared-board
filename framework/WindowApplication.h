#pragma once
#include "pch.h"
#include "Application.h"
#include "Widget.h"

class WindowApplication :
    public Application
{
public:
    template<typename... T>
    explicit WindowApplication(T&&... window_parameters);
    void run() final;
    void setWindowSize(sf::Vector2f size);
    sf::Vector2f windowSize()const;
	template<typename WidgetType, typename... ConstructorArgs>
    void addWidget(ConstructorArgs&&... widget_parameters);
protected:
    virtual void handle(const sf::Event& event) = 0;
private:
    sf::RenderWindow main_window_;
    std::vector<std::unique_ptr<Widget>> widgets_;
};

template <typename... T>
WindowApplication::WindowApplication(T&&... window_parameters)
	: main_window_(std::forward<T>(window_parameters)...)
{}

