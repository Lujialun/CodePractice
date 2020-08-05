/*
 * @Descripttion: https://leetcode-cn.com/problems/house-robber-iii/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-05 10:51:19
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-05 15:35:17
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
// class Solution { //myway
// public:
//    int dfs(TreeNode* root,bool f){
//     if(root==NULL)
//         return 0;
//     int p1, p2,p3,p4;
    
//     p1 = dfs(root->left, 0) + dfs(root->right, 0);
//     if(f) return p1;
//     if(index.find(root)!=index.end()) return index[root];
//     p2 = dfs(root->left, 1)+dfs(root->right, 1)+root->val;
//     p1=p1 > p2 ? p1 : p2;
//     index[root]=p1;
//     return p1;

// }
// int rob(TreeNode* root) {
//     if(root==NULL)
//         return 0;
    
//     int a =root->val+ dfs(root->left, 1)+dfs(root->right, 1);
//     int b =dfs(root->left, 0)+dfs(root->right, 0);
//     return a>b?a:b;
// }

//     unordered_map<TreeNode*,int> index;
// };

struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution {
public:
    SubtreeStatus dfs(TreeNode* o) {
        if (!o) {
            return {0, 0};
        }
        auto l = dfs(o->left);
        auto r = dfs(o->right);
        int selected = o->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode* o) {
        auto rootStatus = dfs(o);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/house-robber-iii/solution/da-jia-jie-she-iii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。