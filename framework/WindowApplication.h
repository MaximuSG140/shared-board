#pragma once
#include "pch.h"
#include "Application.h"
#include "ClickableWidget.h"
#include "Widget.h"

class WindowApplication :
    public Application
{
public:
    template<typename... T>
    explicit WindowApplication(T&&... window_parameters);

    void run() final;

    void setWindowSize(sf::Vector2u size);
    sf::Vector2u windowSize()const;

	template<typename WidgetType, typename... ConstructorArgs>
	WidgetType* addWidget(ConstructorArgs&&... widget_parameters);
protected:
    virtual void handle(const sf::Event& event) = 0;
    void render();
private:
    sf::RenderWindow main_window_;
    std::vector<std::unique_ptr<Widget>> widgets_;
    std::vector<ClickableWidget*> clickable_widgets_;
};

template <typename... T>
WindowApplication::WindowApplication(T&&... window_parameters)
	: main_window_(std::forward<T>(window_parameters)...)
{}

template <typename WidgetType, typename... ConstructorArgs>
WidgetType* WindowApplication::addWidget(ConstructorArgs&&... widget_parameters)
{
    static_assert(std::is_base_of_v<Widget, WidgetType> &&
        "New widget should be derived from class Widget");
    widgets_.push_back(std::make_unique<WidgetType>(std::forward<ConstructorArgs>(widget_parameters)...));
    auto new_widget = widgets_.back().get();
    if constexpr (std::is_base_of_v<ClickableWidget, WidgetType>)
    {
        clickable_widgets_.push_back(static_cast<ClickableWidget*>(new_widget));
    }

    return static_cast<WidgetType*>(new_widget);
}

