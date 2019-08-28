#pragma once
#include "strategy.h"


class CContext
{
public:
	CContext(IStrategy * apStrategy);
	~CContext();

public:
	void go_home();

private:
	IStrategy*		m_pStrategy;
};
