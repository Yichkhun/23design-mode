#include "stdafx.h"
#include "produce_consumer.h"



int main()
{

	produce_consumer * ptr = new produce_consumer;
	//open res
	ptr->produce_consumer_open(5);

	for(int i = 0; i < 100; i++)
	{
		task * _task = new task;
		_task->m_item = i;
		
		ptr->produce_consumer_add_task(_task);
	}

	sleep(1000);

	ptr->produce_consumer_close();

	return 1;
}

