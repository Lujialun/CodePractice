/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-22 11:13:52
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-23 19:16:13
 */
#include <iostream>
#include <string.h>
#include<stdio.h>
#include <unistd.h>
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
int main()
{
    int i;
    for (i = 0; i < 2; i++){
        
       cout<<
        printf("-\n");
    }

        //  strRer("abcdefg");
        system("pause");
}