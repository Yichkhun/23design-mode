#pragma once

#include "common.h"
#include <queue>
#include <pthread.h>

class produce_consumer
{
public:
	produce_consumer();
	~produce_consumer();

public:
	//add new task to task queue
	bool produce_consumer_add_task(task * _task);
	//open 
	bool produce_consumer_open(int	_thread_count);
	//close
	void produce_consumer_close();
	//thread func
	static void* thread_func(void *_param);

private:
	//thread work func	
	void produce_consumer_work_func();
	//deal task
	void produce_consumer_deal_task(task * _task);

private:
	std::queue<task *>						m_task_queue;
	pthread_mutex_t							m_thread_mutex;
	pthread_cond_t							m_thread_cond;
	int										m_thread_count;
	pthread_t*								m_pthread;

public:
	static	bool							m_stop;
};

