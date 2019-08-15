#include "stdafx.h"

class CCriticalSection
{
public:
	CCriticalSection()
	{
		pthread_mutexattr_t attr;
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
		pthread_mutex_init(&m_omutex, &attr);
	}

	~CCriticalSection()
	{
		pthread_mutex_destroy(&m_omutex);
	}

public:
	void lock()
	{
		pthread_mutex_lock(&m_omutex);
	}

	void unlock()
	{
		pthread_mutex_unlock(&m_omutex);
	}

private:
	pthread_mutex_t  					m_omutex;
};


class CAutoLock
{
public:
	CAutoLock(CCriticalSection & _aosection)
	{
		m_psection = & _aosection;
		m_psection->lock();
	}

	~CAutoLock()
	{
		m_psection->unlock();
	}

private:
	CCriticalSection*				m_psection;
};
