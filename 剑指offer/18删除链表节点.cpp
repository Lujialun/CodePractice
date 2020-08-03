/*
 * @Descripttion: https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 16:33:34
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 16:33:45
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val) return head->next;
        ListNode* p=head;
        while(head->next!=NULL){
            if(head->next->val==val){
                head->next=head->next->next;
                return p;
            }
            head=head->next;
        }
        return p;
    }
};