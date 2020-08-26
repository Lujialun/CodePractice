/*
 * @Descripttion: https://leetcode-cn.com/problems/print-foobar-alternately/
 * @version:  https://www.cnblogs.com/haippy/p/3252041.html
 * @Author: Lucas
 * @Date: 2020-08-27 01:07:47
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-27 01:11:14
 */

#include<semaphore.h>
class FooBar {
private:
    int n;
    sem_t foo_first;
    sem_t bar_second;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&foo_first,0,0);
        sem_init(&bar_second,0,1);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&bar_second);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(&foo_first);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&foo_first);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_post(&bar_second);
        }
    }
};