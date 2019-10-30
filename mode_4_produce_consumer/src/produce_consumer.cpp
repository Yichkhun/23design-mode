#include "produce_consumer.h"
#include "stdafx.h"

bool produce_consumer::m_stop = false;

produce_consumer::produce_consumer()
{
	m_thread_count = 5;
}

produce_consumer::~produce_consumer()
{
}

bool produce_consumer::produce_consumer_add_task(task * _task)
{
	//check param
	if(_task == nullptr){
		printf("add produce task failed: invaild param");
		return false;
	}

	//lock
	pthread_mutex_lock(&m_thread_mutex);
	//add queue	
	m_task_queue.push(_task);

	printf("add task to queue item=[%d]\n", _task->m_item);

	//set condation signal
	pthread_cond_signal(&m_thread_cond);
	//unlock
	pthread_mutex_unlock(&m_thread_mutex);

	return true;
}

bool produce_consumer::produce_consumer_open(int _thread_count)
{
	if(_thread_count > 5) {
		m_thread_count = _thread_count;		
	}
	
	//init mutex and cond
	pthread_mutex_init(&m_thread_mutex, NULL);
	pthread_cond_init(&m_thread_cond, NULL);

	//new some pthread_ts
	m_pthread = new pthread_t[m_thread_count];

	//create threads
	for(int i = 0; i < m_thread_count; i++) {
		pthread_create(&m_pthread[i], NULL, thread_func, this);
	}

	return true;
}

void produce_consumer::produce_consumer_close()
{
	m_stop = true;
	//you can add pthread_join(&m_pthread[i], NULL); wait every thread run complete

	//free resource
	free(m_pthread);
	pthread_mutex_destroy(&m_thread_mutex);
	pthread_cond_destroy(&m_thread_cond);

}

void* produce_consumer::thread_func(void * _param)
{
	//get task then deal
	
	produce_consumer * _this = (produce_consumer*)_param;

	while(!m_stop)
	{
		_this->produce_consumer_work_func();
	}
}

void produce_consumer::produce_consumer_deal_task(task * _task)
{
	//this is a demo, you can do your task
	printf("item = [%d]\n", _task->m_item);
}

void produce_consumer::produce_consumer_work_func()
{
	task * _deal_task = NULL;

	//lock
	pthread_mutex_lock(&m_thread_mutex);				

	if(!m_task_queue.empty()) {
		//get task
		_deal_task = m_task_queue.front();
		m_task_queue.pop();
	}else{
		printf("produce_consumer condition wait\n");
		//deal spurious wakeup  - other singal affect this wait
		while(m_task_queue.empty()) {
			pthread_cond_wait(&m_thread_cond, &m_thread_mutex);
			//if program recv stop  break this while
			if(m_stop){
				break;
			}
		}
	}

	//unlock
	pthread_mutex_unlock(&m_thread_mutex);

	if(_deal_task != NULL) {
		//do task
		produce_consumer_deal_task(_deal_task);		
	}
}

























