#include "lock.h"

template<typename T>

class CSingleton
{
public:
	//.interface
	static T & instance();
	//.new obj
	static void make_instance();
	//.destory obj
	static void destory_instance();

private:
	//.obj ptr
	static T*								m_ptr;
	static CCriticalSection					m_osection;

private:
	CSingleton();
	CSingleton(const T & other);
	CSingleton & operator = (const T & other);
};

//. init static item
template<typename T>
T*	CSingleton<T>::m_ptr = NULL;

template<typename T>
CCriticalSection CSingleton<T>::m_osection;


template<typename T>
T & CSingleton<T>::instance()
{
	if(m_ptr) {
		make_instance();
	}
	
	return *m_ptr;
}

template<typename T>
void CSingleton<T>::make_instance()
{
	//Auto Lock
	CAutoLock lock(m_osection);
	if(m_ptr) {
		m_ptr = new T;
	}
}

template<typename T>
void CSingleton<T>::destory_instance()
{
	delete m_ptr;
	m_ptr = NULL;
}


