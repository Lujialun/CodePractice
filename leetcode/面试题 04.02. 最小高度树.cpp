/*
 * @Descripttion:  https://leetcode-cn.com/problems/minimum-height-tree-lcci/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-27 11:11:18
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-27 11:13:56
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        return merge(nums,0,nums.size()-1);
    }
    TreeNode* merge(vector<int>& n, int i, int j){
        if(i>j) return NULL;
        int m=i+(j-i)/2;
        TreeNode* root=new TreeNode(n[m]);
        root->left=merge(n,i,m-1);
        root->right=merge(n,m+1,j);
        return root;
    }
};