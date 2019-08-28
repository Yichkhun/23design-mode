#pragma once
#include "strategy.h"

class CTakeWalk : public IStrategy
{
public:
	CTakeWalk();
	~CTakeWalk();

public:
	virtual void back_home();
};
