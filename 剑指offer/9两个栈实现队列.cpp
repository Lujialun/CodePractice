/*
 * @Descripttion: https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 14:23:44
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 14:23:55
 */ 
class CQueue {
public:
    stack<int> sin;
    stack<int> sout;
    CQueue() {

    }
    
    void appendTail(int value) {
        sin.push(value);
    }
    
    int deleteHead() {
        if(sin.empty()&&sout.empty()) return -1;
        if(!sout.empty()){
            int t=sout.top();
            sout.pop();
            return t;
        }
        while(!sin.empty()){
            sout.push(sin.top());
            sin.pop();
        }
        int t=sout.top();
            sout.pop();
            return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */