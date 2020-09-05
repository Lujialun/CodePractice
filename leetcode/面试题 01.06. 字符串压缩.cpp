/*
 * @Descripttion:  https://leetcode-cn.com/problems/compress-string-lcci/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-04 13:06:17
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-04 13:06:30
 */
class Solution {
public:
    string compressString(string S) {
        if(S.size()<2) return S;
        int i=0,j=1;
        string res;
        while(j<S.size()){
            if(S[i]==S[j]){
                j++;
            }else{
                res+=S[i]+to_string(j-i);
                i=j;
                j++;
            }
        }
        res+=S[i]+to_string(j-i);
        return res.size()>=S.size()?S:res;
    }
};