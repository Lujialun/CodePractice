/*
 * @Descripttion:  https://leetcode-cn.com/problems/same-tree/submissions/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-07 10:38:31
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-07 11:07:16
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {//BFS
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        queue<TreeNode*> s1,s2;
        s1.push(p),s2.push(q);
        while(!s1.empty()&&!s2.empty()){
            if(s1.front()->val!=s2.front()->val){         
                return false;
            }
            if(s1.front()->left!=NULL&&s2.front()->left!=NULL){
                s2.push(s2.front()->left);
                s1.push(s1.front()->left);
            }else if(s1.front()->left!=NULL||s2.front()->left!=NULL)
                return false;
            if(s1.front()->right!=NULL&&s2.front()->right!=NULL){
                s2.push(s2.front()->right);
                s1.push(s1.front()->right);
            }else if(s1.front()->right!=NULL||s2.front()->right!=NULL)
                return false;
            s1.pop(),s2.pop();
        }
          if(!s1.empty()||!s2.empty()) return false;
          return true;
    }
};


class Solution {//DFS
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};