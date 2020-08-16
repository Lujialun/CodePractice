/*
 * @Descripttion:  20. 有效的括号https://leetcode-cn.com/problems/valid-parentheses/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-14 09:44:51
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-14 19:00:33
 */

class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(auto i:str){
            if(i=='('||i=='['||i=='{'){
                s.push(i);
            }else if(s.empty()){
                return false;
            }else if(i==')'){
                if(s.top()!='(') return false;
                s.pop();
            }else if(i==']'){
                if(s.top()!='[') return false;
                s.pop();
            }else if(i=='}'){
                if(s.top()!='{') return false;
                s.pop();
            }
        }
        return s.empty()?true:false;
    }
};