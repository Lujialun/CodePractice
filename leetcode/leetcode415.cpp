/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-03 19:47:08
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-03 20:06:55
 */
#include <bits/stdc++.h>
using namespace std;
// string addStrings(string num1, string num2) {
//         string res;
//         stack<char> s;
//         // int n=num1.size()>num2.size()?num1.size():num2.size();
//         int flag=0;
//         while(!num1.empty()||!num2.empty()){
//             int temp;
//             if(!num1.empty()&&!num2.empty()){
//                 temp=num1.back()-'0'+num2.back()-'0'+flag;
//                 num1.pop_back();
//                 num2.pop_back();
//                 s.push(temp%10+'0');
//                 flag=temp/10;
//             }else if(!num1.empty()){
//                 temp=num1.back()-'0'+flag;
//                 num1.pop_back();
//                 s.push(temp%10+'0');
//                 flag=temp/10;
//             }else if(!num2.empty()){
//                 temp=num2.back()-'0'+flag;
//                 num2.pop_back();
//                 s.push(temp%10+'0');
//                 flag=temp/10;
//             }else{
//                 break;
//             }
//         }
//         if(flag) s.push(flag+'0');
//         while(!s.empty()){
//             res.push_back(s.top());
//             cout << s.top() << endl;
//             s.pop();
//         }
//         return res;
//     }

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main()
{
    addStrings("0", "0");
    system("pause");
}