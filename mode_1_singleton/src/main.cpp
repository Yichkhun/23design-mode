#include "stdafx.h"
#include "singleton.h"

class CMYClass
{
public:
	//.
	CMYClass(){
	};
	//.
	~CMYClass(){
	};

public:
	//. cout
	void trace_log()
	{
		std::cout<<"singleton obj"<<std::endl;
	}

private:
	int 				m_iitem;
};


int main()
{
	typedef CSingleton<CMYClass>	CSingletonClass;
	CSingletonClass::instance().trace_log();

	return 1;
}
