#include "sThread.hpp"

sThread::sThread(){

}

sThread::~sThread(){

}

unsigned long __stdcall ThreadFunc1(void* data) {	//terminated example
    int cnt = 0;
    while (1) {
        int id = GetCurrentThreadId();
        printf("id=%d, ThreadFunc1:%d \n", id, cnt++);
        Sleep(1000);
    }
    return 0;
}
 
unsigned long __stdcall ThreadFunc2(void* data) {	//criterion function
    int cnt = 0;
    while (1) {
        int id = GetCurrentThreadId();
        printf("id=%d, ThreadFunc2:%d \n", id, cnt++);
        Sleep(1000);
    }
    return 0;
}
  
unsigned long __stdcall ThreadFunc3(void* data) {	//pointer example
    int* cnt;
	cnt = (int*)data;
    while (1) {
        int id = GetCurrentThreadId();
		*cnt += 1;
        printf("id=%d, ThreadFunc3:%d \n", id, cnt);
        Sleep(1000);
    }
    return 0;
}

void sThread::thread_example(){	
	void *thread[3];
	int main_value=0;
	int *pmain_value=&main_value;
	
    thread[0] = CreateThread(NULL, 0, ThreadFunc1, NULL, 0, NULL);
    thread[1] = CreateThread(NULL, 0, ThreadFunc2, NULL, 0, NULL);
	thread[2] = CreateThread(NULL, 0, ThreadFunc3, (void *)pmain_value, 0, NULL);

//    WaitForSingleObject(thread[0], INFINITE);
//    WaitForSingleObject(thread[1], INFINITE);
	
	int cnt = 0;
	while(1){
		if(cnt==5){
			TerminateThread(thread[0],0);
			printf("terminated %d \n",cnt);
		}
		cnt++;
		printf("main_value %d\n",*pmain_value);
		Sleep(1000);
	}

}
