/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-19 14:12:18
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-19 17:43:34
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;


bool checkValidString(string s) {
        // write code here
        int n = s.size();
        stack<int> s1, s2;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if(s[i]=='('){
                s1.push(i);
            }else if(s[i]==')'){
                if(!s1.empty()){
                    s1.pop();
                }else{
                    if((!s2.empty())){
                        s2.pop();
                    }else{
                        return false;
                    }
                }
            }else if(s[i]=='*'){
                s2.push(i);
            }
        }
        int left, right;
        while(!s1.empty()&&!s2.empty()){
            left = s1.top(), right = s2.top();
            if(left<right){
                s1.pop();
            }
            s2.pop();
        }
        return !s1.empty() ? 0 : 1;
}


// int calEncodeNumber(int length) {
//         // write code here
//         vector<long long > f(length+1);
//         f[1]=1,f[2]=2;
//         for(int i=3; i<=length; i++){
//             if(i&1){
//                 f[i]=f[i-1]*2;
                
//             }else{
//                 f[i]=f[i-1]+f[i-1]/2;
//             }
//            // f[i]=f[i]%1000000369;
//         }
//         return f[length]%1000000369;
//     }


int calEncodeNumber(int length) {// https://www.nowcoder.com/questionTerminal/0a5b316cfe9d4c4ba89c6c57a1ee516e
    constexpr auto MOD = 1000000369;
    constexpr auto MAX = 2000001;
    size_t ans = 1;
    vector<bool> visited(MAX);
    for (size_t i = 0; i < MAX; ++i) visited[i] = false;
    for (int i = 2; i <= length; ++i)
    {
        size_t count = 0;
        if (visited[i]) continue;
        for (int j = 2 * i; j <= length; j += i)
        {
            visited[j] = true;
        }
        for (size_t j = i; j <= length; j *= i) count++;
        ans = ans * (count + 1) % MOD;
    }
    return ans;
}

int main()
{

    cout << calEncodeNumber(6) << endl;

    system("pause");
    return 0;
}