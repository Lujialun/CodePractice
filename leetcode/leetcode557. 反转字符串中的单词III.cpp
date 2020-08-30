/*
 * @Descripttion: https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-30 11:14:26
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-30 11:14:39
 */
class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        while(i<s.size()){
            int left=i;
            while(i<s.size()&&s[i]!=' '){
                i++;
            }
            int right=i-1;
            while(left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            if(i<s.size()&&s[i]==' '){
                i++;
            }
        }
        return s;
    }
};