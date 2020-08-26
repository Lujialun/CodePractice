/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-15 16:35:00
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-15 17:38:23
 */
#include<bits\stdc++.h>
using namespace std;

void strRemove(char *str){
    char *p = str;
    while(*str){
        if(*str!=' '){
            *p = *str;
            p++;
        }
        str++;
    }
    *p = '\0';
    // int i = 0, j = 0;
    // int cnt = 0;
    // bool f = false;
    // while(str[j]!='\0'){
    //     if(str[j]==' '){
    //         if(cnt==0)
    //             i = j;
    //         j++;
    //         cnt++;   
    //     }
    //     // else if(str[i]!=' '){
    //     //     i++;
    //     //     j = i;
    //     else if(cnt>0){
    //         str[i] = str[j];
    //         i++;
    //         cnt--;
    //         j++;
    //     }
    // }
    // str[i] = '\0';
}

int main()
{
    char str[] = {'a', ' ', ' ', ' ', 'b', ' ', ' ', '\0'};
    char str1[] = "  aa aa bb   ";
    char str2[] = "aaaaaaaaaaaa";
    char str3[] = "aaa aaa aa    ";
    char str4[] = "           ";
    strRemove(str);
    strRemove(str1);
    strRemove(str2);
    strRemove(str3);
    strRemove(str4);
    cout <<"["<< str <<"]"<< endl;
    cout <<"["<< str1 <<"]"<< endl;
    cout <<"["<< str2 <<"]"<< endl;
    cout <<"["<< str3 <<"]"<< endl;
    cout <<"["<< str4 <<"]"<< endl;
    system("pause");
}