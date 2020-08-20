/*
 * @Descripttion: 109. 有序链表转换二叉搜索树 https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-18 15:37:01
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-18 16:14:23
 */
#include <bits\stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



//   TreeNode *merge(vector<ListNode *> &Node, int l, int r) {
//     int n = r-l+1;
//     TreeNode *root = new TreeNode(Node[n/2+l]->val);
//     if(n>1)
//     {
//         root->left = merge(Node,l,n/2-1+l);
//     }

//     if(n>2){
//         root->right = merge(Node,n/2+1+l,r);
//     }
//     return root;
// }

// TreeNode* sortedListToBST(ListNode* head) {
//     if(head==NULL)
//         return NULL;
//     vector<ListNode *> Node;
//     while(head)
//     {
//         Node.push_back(head);
//         head = head->next;
//     }
//     return merge(Node,0,Node.size()-1);
// }


class Solution {
public:
    ListNode* getMedian(ListNode* left, ListNode* right) {
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    TreeNode* buildTree(ListNode* left, ListNode* right) {
        if (left == right) {
            return nullptr;
        }
        ListNode* mid = getMedian(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(left, mid);
        root->right = buildTree(mid->next, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/solution/you-xu-lian-biao-zhuan-huan-er-cha-sou-suo-shu-1-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。