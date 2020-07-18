/*
 * @Descripttion:  交错字符串 https://leetcode-cn.com/problems/interleaving-string/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-18 09:56:47
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-18 17:04:43
 */ 
#include <bits/stdc++.h>
using namespace std;

// bool isInterleave(string s1, string s2, string s3) {//空间还可优化成O(n)
//     int a = s1.size(), b = s2.size(), c = s3.size();
//     if(a+b!=c)
//         return false;
//     vector<vector<int>> dp(a+1, vector<int>(b+1,0));
//     dp[0][0] = 1;
//     int p = 0;
//     for (int i = 0; i <= a; i++){
//         for (int j = 0; j <= b; j++){
//             p = i + j - 1;
//             if(i>0){
//                 dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
//             }
//             if(j>0){
//                 dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
//             }
//         }
//     }

//         return dp[a][b];
// }

bool isInterleave(string s1, string s2, string s3) {//空间还可优化成O(n)
    int a = s1.size(), b = s2.size(), c = s3.size();
    if(a+b!=c)
        return false;
    vector<int> dp(b+1, 0);
    dp[0] = 1;
    int p = 0;
    for (int i = 0; i <= a; i++){
        for (int j = 0; j <= b; j++){
            p = i + j - 1;
            if(i>0){
                dp[j] &= (s1[i - 1] == s3[p]);
            }
            if(j>0){
                dp[j] |= (dp[j - 1] && s2[j - 1] == s3[p]);
            }
        }
    }

        return dp[b];
}
//  bool dfs(string &s1, string &s2, string &s3, int k,int i,int j, vector<vector<int> > &dp)
// {
//     if(k>=s3.size()||dp[s1.size()-1][s2.size()-1]||dp[i][j])
//         return true;
//     if(s1[i]==s3[k]){
//          if(dfs(s1, s2, s3, k + 1, i==s1.size()-1?i:i+1, j, dp))
//             dp[i][j] = 1;
//     }
//     if(dp[s1.size()-1][s2.size()-1])
//         return true;
//     if(s2[j]==s3[k]){
//         if(dfs(s1, s2, s3, k + 1, i, j==s2.size()-1?j:j+1, dp))
//             dp[i][j] = 1;
//     }
//      dp[i][j] = 0;
//         return false;
// }
// bool isInterleave(string s1, string s2, string s3) {
//     if(s1.empty()&&s2.empty()&&s3.empty())
//         return true;
//     if(s1.empty()||s2.empty()){
//         return s1==s3||s2==s3;
//     }
//     int a = s1.size(), b = s2.size(), c = s3.size();
//     if(a+b!=c) return false;
//     vector<vector<int>> dp(a, vector<int>(b,0));
   
//     return  (bool)dfs(s1, s2, s3, 0, 0, 0, dp);
// }

int main()
{
    cout << isInterleave("cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc","abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb","abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb") << endl;
    system("pause");
}