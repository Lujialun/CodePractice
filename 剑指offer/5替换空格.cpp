/*
 * @Descripttion: https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/solution/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 16:04:57
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 16:05:09
 */ 
class Solution {
public:
    string replaceSpace(string s) {
        string a;
        
        for(auto i:s){
            if(i!=' '){
                a.push_back(i);
            }else{
                a.push_back('%');
                a.push_back('2');
                a.push_back('0');
            }
        }
        return a;
    }
};