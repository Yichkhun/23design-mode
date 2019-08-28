#include "context.h"
#include "stdafx.h"

CContext::CContext(IStrategy * apStrategy)
{
	m_pStrategy = apStrategy;
}

CContext::~CContext()
{

}

void CContext::go_home()
{
	m_pStrategy->back_home();
}
