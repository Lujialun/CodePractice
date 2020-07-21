/*
 * @Descripttion: 95. 不同的二叉搜索树 II https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-21 23:10:06
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-21 23:12:11
 */ 
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> generateTrees(int start, int end)
{
    if(start>end)
        return {nullptr};
    vector<TreeNode *> allTrees;
    for (int i = start; i <= end;i++){
        vector<TreeNode *> left = generateTrees(start, i - 1);
        vector<TreeNode *> right = generateTrees(i + 1, end);
        for(auto& l:left){
            for(auto& r:right){
                TreeNode* tmp=new TreeNode(i);
                tmp->left = l;
                tmp->right = r;
                allTrees.emplace_back(tmp);
            }
        }
    }
    return allTrees;
}
vector<TreeNode*> generateTrees(int n) {
    if(n<1)
        return {};
    return generateTrees(1, n);
}