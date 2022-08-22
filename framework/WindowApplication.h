#pragma once
#include "pch.h"
#include "Application.h"
#include "IKeyboardListener.h"
#include "IMouseClickable.h"
#include "IMouseHoldable.h"
#include "IMouseSelectable.h"
#include "IScrollable.h"
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

    void close();

	template<typename WidgetType, typename... ConstructorArgs>
	WidgetType* addWidget(ConstructorArgs&&... widget_parameters);
protected:
    virtual void handle(const sf::Event& event) = 0;
    void render();
private:
    void baseHandle(const sf::Event& event);

    sf::RenderWindow main_window_;

    sf::Vector2u cached_window_size_;

    std::vector<std::unique_ptr<Widget>> widgets_;
    std::vector<IMouseClickable*> clickable_widgets_;
    std::vector<IMouseHoldable*> holdable_widgets_;
    std::vector<IMouseSelectable*> selectable_widgets_;
    std::vector<IKeyboardListener*> keyboard_widgets_;
    std::vector<IScrollable*> scrollable_widgets_;
};

template <typename... T>
WindowApplication::WindowApplication(T&&... window_parameters)
	: main_window_(std::forward<T>(window_parameters)...),
	cached_window_size_(main_window_.getSize())
{}

template <typename WidgetType, typename... ConstructorArgs>
WidgetType* WindowApplication::addWidget(ConstructorArgs&&... widget_parameters)
{
    static_assert(std::is_base_of_v<Widget, WidgetType> &&
        "New widget should be derived from class Widget");
    widgets_.push_back(std::make_unique<WidgetType>(std::forward<ConstructorArgs>(widget_parameters)...));
    auto new_widget = static_cast<WidgetType*>(widgets_.back().get());
    if constexpr (std::is_base_of_v<IMouseClickable, WidgetType>)
    {
        clickable_widgets_.push_back(static_cast<IMouseClickable*>(new_widget));
    }
    if constexpr (std::is_base_of_v<IMouseHoldable, WidgetType>)
    {
        holdable_widgets_.push_back(static_cast<IMouseHoldable*>(new_widget));
    }
    if constexpr (std::is_base_of_v<IMouseSelectable, WidgetType>)
    {
        selectable_widgets_.push_back(static_cast<IMouseSelectable*>(new_widget));
    }
    if constexpr (std::is_base_of_v<IKeyboardListener, WidgetType>)
    {
        keyboard_widgets_.push_back(static_cast<IKeyboardListener*>(new_widget));
    }
    if constexpr (std::is_base_of_v<IScrollable, WidgetType>)
    {
        scrollable_widgets_.push_back(static_cast<IScrollable*>(new_widget));
    }

    return static_cast<WidgetType*>(new_widget);
}

