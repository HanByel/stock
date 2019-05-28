#if !defined(__STHREAD_HPP__)
#define __STHREAD_HPP__

#include <process.h>
#include <windows.h>
#include <stdio.h>


class sThread{
public:
	void thread_example();
	sThread();
	~sThread();
};


#endif // __STHREAD_HPP__