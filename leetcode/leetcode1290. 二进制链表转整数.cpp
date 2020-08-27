/*
 * @Descripttion: https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-27 10:47:29
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-27 10:47:43
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
    int getDecimalValue(ListNode* head) {
        if(head==NULL) return 0;
        unsigned int res=0;
        while(head!=NULL){
            res=res<<1;
            res+=head->val;
            head=head->next;
        }
        return res;
    }
};  