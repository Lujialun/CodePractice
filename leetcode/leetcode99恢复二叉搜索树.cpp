/*
 * @Descripttion: https://leetcode-cn.com/problems/recover-binary-search-tree/submissions/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-08 11:39:03
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-08 14:29:29
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
class Solution {
public:
    void recoverTree(TreeNode* root) {//my
        vector<TreeNode*> in;
        int p=-1,q=-1;
        dfs(root,in);
        if(in.size()<3){
            swap(in[0]->val,in[1]->val);
            return;
        }
        for(int i=0; i<in.size()-1; i++){
            if(in[i]->val>in[i+1]->val&&q==-1){
                q=i;
            } 
            if(in[i]->val>in[i+1]->val) p=i+1;
        }
        if(q==-1&&p==-1) return;
        swap(in[q]->val,in[p]->val);
    }

    void dfs(TreeNode* r,vector<TreeNode*> &in){
        if(r==NULL) return;
        dfs(r->left,in);
        in.push_back(r);
        dfs(r->right,in);
    }
};

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
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* prev=NULL;
        TreeNode* x=NULL;
        TreeNode* y=NULL;
        while(root!=NULL||!s.empty()){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();
             if (prev != nullptr && root->val < prev->val) {
                y = root;
                if (x == nullptr) {
                    x = prev;
                }
                else break;
            }
            prev = root;
            s.pop();
            root=root->right;
        }
        swap(x->val,y->val);
    }
};

class Solution {
public:
    void recoverTree(TreeNode* root) {//莫里斯遍历
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};

