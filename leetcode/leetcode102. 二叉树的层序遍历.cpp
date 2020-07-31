/*
 * @Descripttion: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-30 17:08:08
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-30 17:08:23
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> tmp;
            while(s--){
                tmp.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};