/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-19 22:13:20
 */ 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class test
{
public:
    test() {
        print();
    }
    ~test() {
        print();
    }
    virtual void print() {
        cout << " father hello world" << endl;
    }
};

class Son : public test
{
public:
    Son() {
        print();
    }
    ~Son() {
        print();
    }
    virtual void print() {
        cout << " son hello world" << endl;
    }
};

void strRemove(char* str) {
    char *p = str;
    while(*str!='\0')
    {
        if(*str!=' ')
        {
            *p = *str;
            p++;
        }
        str++;
    }
    *p = '\0';
}

void stackoverflow() {
    stackoverflow();
}
int num = 99;
class A{
public:
    A();
private:
    int n;
    int &r;
};
A::A(): n(0), r(num){}



#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;

int main(){
    int n,res,ans;
    while(cin>>n){
        ans = 1;
        int kid = 0;
        int cnt = 3;
        while(n>3){
            int cnt = 3;
            n = n - 3;
            while(cnt--){
                
            }
        }
        
    }
    return 0;
}