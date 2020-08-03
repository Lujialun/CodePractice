/*
 * @Descripttion: https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 17:35:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 17:40:53
 */ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {//愚蠢的方法
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1=headA;
        ListNode* p2=headB;
        int a=0,b=0;
        while(p1!=NULL){
            a++;
            p1=p1->next;
        }
        p1=headA;
        while(p2!=NULL){
            b++;
            p2=p2->next;
        }
        p2=headB;
        int k=abs(a-b);
        if(a>b){
            while(k--){
                p1=p1->next;
            }
        }else{
             while(k--){
                p2=p2->next;
            }
        }
        while(true){
                if(p1==p2) return p1;
                p1=p1->next;
                p2=p2->next;
        }
        return NULL;
    }
};

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {//L1+c L2+c  L1+L2+C
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        
        while (node1 != node2) {
            node1 = node1 != NULL ? node1->next : headB;
            node2 = node2 != NULL ? node2->next : headA;
        }
        return node1;
    }
};