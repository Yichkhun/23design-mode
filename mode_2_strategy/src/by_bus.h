#pragma once
#include "strategy.h"

class CByBus : public IStrategy
{
public:
	CByBus();
	~CByBus();

public:
	virtual void back_home();
};
