/*
 * @Descripttion: https://leetcode-cn.com/problems/print-in-order/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-27 00:02:55
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-27 00:47:05
 */
#include<semaphore.h>
class Foo {
private:
    sem_t first_done;
    sem_t second_done;
public:
    Foo() {
        sem_init(&first_done,0,0);
        sem_init(&second_done,0,0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first_done);
    }

    void second(function<void()> printSecond) {
        sem_wait(&first_done);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&second_done);
    }

    void third(function<void()> printThird) {
        sem_wait(&second_done);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

class Foo {
private:
	mutex m_mutex;
	condition_variable m_next;
	bool m_flag1;
	bool m_flag2;
public:
	Foo() {
		m_flag1 = false;
		m_flag2 = false;
	}
	void first(function<void()> printFirst) {
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		m_flag1 = true;//修改flag表示first已经打印完成
		m_next.notify_all();//唤醒所有在wait的线程
	}
	void second(function<void()> printSecond) {
		unique_lock<mutex> locker(m_mutex);	//锁住
		m_next.wait(locker, [this] {return this->m_flag1; });//此时会先判断条件，不满足则释放锁，并进入等待队列当收到唤醒时，会去获取锁并锁住，然后判断条件往下执行，不满足则放弃锁
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		m_flag2 = true;//修改flag表示second已经打印完成
		m_next.notify_all();//唤醒所有wait的线程
	} // 当离开这个作用域的时候，互斥锁会被析构，同时unlock互斥锁
    // 因此这个函数内部的可以认为是临界区
	void third(function<void()> printThird) {
		unique_lock<mutex> locker(m_mutex);
		m_next.wait(locker, [this] {return this->m_flag2; });
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};







