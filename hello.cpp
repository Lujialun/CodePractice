/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-22 11:13:52
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-07 17:06:49
 */
#include <iostream>
#include <string.h>
#include<stdio.h>
#include <unistd.h>
#include <thread>
using namespace std;

/***将字符串转成int***/
int char2int(const char* str) {
    const char* p = str;
    bool neg = false;
    int res = 0;
    if (*str == '-' || *str == '+') {
        str++;
    }

    while (*str != 0) {
        if (*str < '0' || *str > '9') {
            break;
        }
        res = res * 10 + *str - '0';
        str++;
    }

    if (*p == '-') {
        res = -res;
    }
    return res;
}

/***将int转成字符串***/
void int2char(int v, char* s) {
    int t = v < 0 ? -v : v;
    int i = 0;
    char buf[10] = "";
    while (t) {
        buf[i++] = t % 10 + '0';
        t = t / 10;
    }
    int len = v < 0 ? i+1 : i;
    for (int j = 0; j < i; j++) {
        s[j + len - i] = buf[i - j - 1];
    }
    s[len] = 0;
    if (len - i > 0) {
        s[0] = '-';
    }
    return;
}

void strRer(char *s) {
    char *p = s;
    while(*p!='\0'){
        p++;
    }
    while(p!=s){
        p--;
        cout << *p;
    }
    cout << endl;
}



string to_String(int n)
{
    int m = n;
    char s[20];
    char ss[20];
    int i=0,j=0;
    if (n < 0)// 处理负数
    {
        m = 0 - m;
        j = 1;
        ss[0] = '-';
    }
    while (m>0)
    {
        s[i++] = m % 10 + '0';
        m /= 10;
    }
    s[i] = '\0';
    i = i - 1;
    while (i >= 0)
    {
        ss[j++] = s[i--];
    }
    ss[j] = '\0';
    return ss;
}

void print(){
    static int a = 1;
    a++;
    cout << a << endl;
}

 
// class A  //大小为4
// {
// public:
// 	int a;
// };
// class B :virtual public A  //大小为16，变量a,b共8字节，虚基类表指针8
// {
// public:
// 	int b;
// };
// class C :virtual public A //与B一样16
// {
// public:
// 	int c;
// };
// class D :public B, public C //40,变量a,b,c,d共16，B的虚基类指针8，C的虚基类指针8
// {
// public:
// 	int d;
// };
 
 class A {//8
public:
    //int a;
    void print(){
        cout << 1 << endl;
    }
 //   virtual ~A(){}

};

class B:public A{//16
    int a;

    //  virtual void myfunB(){}
    void print(){
        cout << "2" << endl;
    }
};

void hello()
{
    std::cout<<"Hello Concurrent World\n";
}

int main()
{
    A *a = new B();
    a->print();
    system("pause");
	return 0;
}