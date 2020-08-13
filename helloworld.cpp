/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-13 23:04:54
 */ 


#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
void Foo(char param[20]) {
    printf("%d\n", sizeof(param));
    printf("%d\n", strlen(param));
}

 string solve(string str) {
        // write code here
        string ans;
        for(auto c : str) {
            cout << ans << endl;
            if(ans.size() == 0 || ans[ans.size()-1] != c) ans.push_back(c);
            else {
                if(c == '1') {
                    ans.pop_back();
                } else if(c == '0') {
                    ans.pop_back();
                    if(ans.size() && ans[ans.size()-1] == '1') ans.pop_back();
                    else ans.push_back('1');
                }
            }
        }
        cout << "here" << endl;
        return ans;
    }

int main(int argc, const char * argv[]) {
    cout << solve("11011100") << endl;
    system("pause");
}