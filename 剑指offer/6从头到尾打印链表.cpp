/*
 * @Descripttion:  https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 17:17:01
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 17:17:15
 */ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(head==NULL) return {};
        stack<int> s;
        while(head!=NULL){
            s.push(head->val);
            head=head->next;
        }
        vector<int> r;
        while(!s.empty()){
            r.push_back(s.top());
            s.pop();
        }
        return r;
    }
};