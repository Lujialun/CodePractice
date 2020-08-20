/*
 * @Descripttion: 测试类的大小
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-22 15:11:20
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-17 16:42:46
 */ 

#include<bits/stdc++.h>

using namespace std;

/*
空类大小为1
int 4 double 8 char 1 short 2 long long 8 遵守内存对齐
string 32 vector 24 map 48 不遵守内存对齐
虚函数 8 遵守内存对齐,但跟普通类型不一样，也许是因为虚函数指针存放点不一样

*/
class ClassSize{

    //int a;
    static  char n;
    //double c;
  
    virtual void fun1(){};
    double f;
};

int main()
{
    ClassSize a;
    cout << sizeof(a) << endl;
    system("pause");
}