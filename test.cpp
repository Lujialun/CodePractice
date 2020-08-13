/*
 * @Descripttion: test
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-12 16:49:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-12 17:09:56
 */

#include<bits\stdc++.h>
using namespace std;

bool isPalindrome(int x){
    bool f=false;
    if(x<0){
        return false;
    }else{
        int y=x;
        int res = 0;
        while(x!=0){
            int temp=x%10;
            x /= 10;
            res = res * 10 + temp;
        }
        f = res == y;
    }
    return f;
}

bool f[26];
void stringFilt(const char *input, int inputlen, char *output){
    int i = 0;
    if(input==NULL||inputlen<=1){
        return;
    }
    const char *p=input;
    while(*p!='\0'){
        if(f[*p-'a']){
            p++;
        }else{
            output[i++] = *p;
            f[*p - 'a'] = 1;
        }
    }
    output[i] = '\0';
}

int main(){

    // cout << isPalindrome(101) << endl;
    // cout << isPalindrome(1011) << endl;
    // cout << isPalindrome(-101) << endl;
    memset(f, 0, sizeof(f));
    char input[] = "happppppy";
    char *output = new char[strlen(input) + 1];
    stringFilt(input, strlen(input), output);
    cout<<output<<endl;
    delete output;
    system("pause");
}
