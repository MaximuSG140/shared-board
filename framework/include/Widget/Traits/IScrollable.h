#pragma once
class IScrollable
{
public:
	virtual ~IScrollable() = default;
	virtual void scroll(int ticks) = 0;
};

