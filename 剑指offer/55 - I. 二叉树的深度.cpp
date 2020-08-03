/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 18:43:23
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 18:51:06
 */ 
   //**
 //* Definition for a binary tree node.
 #include<bits\stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
// */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int k=0;
        while(!q.empty()){
            int s=q.size();
            k++;
            while(s--){
                if(q.front()->left!=NULL) q.push(q.front()->left);
                if(q.front()->right!=NULL) q.push(q.front())->right);
                q.pop();
             }
        }
        return k;
    }
};