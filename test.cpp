/*
 * @Descripttion: test
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-12 16:49:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-16 17:19:01
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

long long numbers(int a, int b, int c, int d, int p) {
        // write code here
        long long left = (b / p) - (a - 1) / p;
        long long right = (d / p) - (c - 1) / p;
        return (b - a + 1) * right + (d - c + 1) * left - left * right;
    }

int CalulateMethodCount(int num_money) {
    
    return (1<<(num_money-1))+1;
}


int main() {
    string cur;
    stack<string> del;
    vector<string> save;
    while (cin >> cur) {
        if (cur == "undo") {//撤销
            if (save.empty()) continue;//无字符串可以撤销
            cur = save.back();
            save.pop_back();
            del.push(cur);
        }
        else if (cur == "redo") {//恢复
            if (del.empty()) continue;//无撤销的字符串可以恢复
            cur = del.top();//此时del不应该为空
            del.pop();
            save.push_back(cur);
        }
        else {
            save.push_back(cur);
            while (not del.empty()) del.pop();//一个是如果前一个不是撤销则恢复“空气”
        }
    }
    for (int i = 0; i < save.size(); ++i) {
        cout << save[i] << " ";
    }
 
    return 0;
}