#include "stdafx.h"
#include "strategy.h"
#include "context.h"
#include "by_bus.h"
#include "take_a_walk.h"


int main()
{
	IStrategy * _pbybus = new CByBus;
	IStrategy * _pbywalk = new CTakeWalk;

	CContext * _pbus = new CContext(_pbybus);
	_pbus->go_home();
	delete _pbus;

	CContext * _pwalk = new CContext(_pbywalk);
	_pwalk->go_home();
	delete _pwalk;

	return 1;
}

