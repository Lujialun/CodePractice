/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-24 23:41:40
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-24 23:41:44
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head;
        ListNode* q=new ListNode(0);
        q->next=head;
        int cnt=0;
        while(p!=NULL){
            p=p->next;
            if(cnt!=n) cnt++;
            else{
                q=q->next;
            }
        }
        if(q->next==head) return head->next;
        q->next=q->next->next;
        return head;
    }
};