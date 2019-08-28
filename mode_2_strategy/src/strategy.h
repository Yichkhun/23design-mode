#pragma once

class IStrategy
{
public:
	IStrategy()
	{};
	~IStrategy()
	{}

public:
	virtual void back_home() = 0;
};
