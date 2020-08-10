/*
 * @Descripttion: 696. 计数二进制子串 696. 计数二进制子串
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-10 22:59:34
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-10 23:45:15
 */
#include<bits/stdc++.h>
using namespace std;

// int countBinarySubstrings(string s) {
//     vector<int> counts;
//     int cnt = 1;
//     for (int i = 0; i<s.size()-1; i++){
//         if(s[i]==s[i+1])
//             cnt++;
//         else{
//             counts.push_back(cnt);
//             cnt = 1;
//         }
//     }
//     counts.push_back(cnt);
//     int res = 0;
//     for (int i = 0; i < counts.size()-1; i++){
//         cout << counts[i] << endl;
//         res += min(counts[i], counts[i + 1]);
//     }
//     return res;
// }

int countBinarySubstrings(string s) {
    int prev=0;
    int next = 1;
    int res = 0;
    for (int i = 0; i<s.size()-1; i++){
        if(s[i]==s[i+1])
            next++;
        else if(prev==0){
            prev = next;
            next = 1;
        }else{
            res += min(prev, next);
            prev = next;
            next = 1;
        }
    }
    res += min(prev, next);
    return res;
}

int main()
{
    cout << countBinarySubstrings("10101") << endl;
    system("pause");
}