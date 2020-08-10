/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-10 17:25:52
 */ 


#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
void Foo(char param[20]) {
    printf("%d\n", sizeof(param));
    printf("%d\n", strlen(param));
}
 
int main(int argc, const char * argv[]) {
    char str1[] = "Hello\0dji";
    char str2[] = { 'H','e','l','l','o','\0','d','j','i' };
    printf("%d\n", sizeof(str1));
    printf("%d\n", sizeof(str2));
    Foo(str1);
    system("pause");
}