/*
 * @Descripttion:  https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-31 12:03:21
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-31 12:03:45
 */ 

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL?true:judge(root->left,root->right);
    }

    bool judge(TreeNode* l, TreeNode* r){
        if(l==NULL&&r==NULL) return true;
        if(l==NULL||r==NULL||l->val!=r->val) return false;
        return judge(l->left,r->right)&&judge(l->right,r->left);
    }
};
