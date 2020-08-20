/*
 * @Descripttion: 5. 最长回文子串  https://leetcode-cn.com/problems/longest-palindromic-substring/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-19 11:34:37
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-19 14:11:28
 */
#include <bits\stdc++.h>
using namespace std;

string longestPalindrome(string s) {//中心扩散
    int n = s.size();
    int Max = 0;
    int L,R;
    for (int i = 0; i < 2 * n - 1; i++){
        int l = i / 2, r = i / 2 + i % 2, cnt = 0;
        while (l >= 0 && r < n&&s[l]==s[r])
        {
            if(l!=r) cnt++;
            cnt++;
            l--;
            r++;
        }
        cout << cnt << endl;
        if(Max<cnt){
            Max = cnt;
            L = l+1;
            R = r-1;
        }
    }
    cout << L << " " << R << endl;
    return s.substr(L,R-L+1);
}

int main() {
    cout << longestPalindrome("cbbd") << endl;
    system("pause");
}