/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-14 09:43:30
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-22 11:13:43
 */
#include "iostream"
#include "thread"
#include "vector"
#include "string"
#include "mutex"
#include "windows.h"
using namespace std;
 
int ticket = 100;
mutex g_mutex;
 
void thread1()
{
	while (true)
	{
		g_mutex.lock();
		if (ticket > 0)
		{
			//Sleep(10);
			--ticket;
			cout << "1机卖出一张票:" << ticket << endl;
			g_mutex.unlock();
			Sleep(100);
		}
		else
		{
			g_mutex.unlock();
			break;
		}
	}
//	g_mutex.unlock();
}
 
void thread2()
{
	//lock_guard<mutex> lg(g_mutex);
	while (true)
	{
		g_mutex.lock();
		if (ticket > 0)
		{
		//	Sleep(10);
			--ticket;
			cout << "2机卖出一张票:" << ticket << endl;
			g_mutex.unlock();
			Sleep(100);
		}
		else
		{
			g_mutex.unlock();
			break;
		}
	}
}
 


int main() {
	thread t2(thread2);
	thread t1(thread1);
	
	t1.join();
	t2.join();
    system("pause");
    return 0;

	while(1) {
    	pthread_mutex_lock();
    	pthread_cond_wait();
    	//取元素；
    	pthread_mutex_unlock();
	}
 

	
}