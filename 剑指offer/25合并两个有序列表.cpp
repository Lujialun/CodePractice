/*
 * @Descripttion: 剑指 Offer 25. 合并两个排序的链表 https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-01 15:10:08
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-01 15:25:31
 */ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* ans=new ListNode();
        ListNode* res=ans;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                ans->next=l1;
                l1=l1->next;
            }else{
                ans->next=l2;
                l2=l2->next;
            }
            ans=ans->next;
        }
        if(l1==NULL) ans->next=l2;
        if(l2==NULL) ans->next=l1;
        return res->next;
    }
};