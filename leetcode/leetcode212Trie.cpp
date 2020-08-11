/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-11 12:23:41
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-11 16:08:32
 */
#include<bits\stdc++.h>
using namespace std;
// class Solution {
// public:
//     int M,N;
//     vector<string> findWords(vector<vector<char>>& alpha, vector<string>& word) {
//         N=alpha.size();
//         M=word.size();
//         vector<vector<char>> temp(N);
//         vector<string> res;
//       //  vector<string> res;
//         bool a=0;
//         for(int i=0; i<M; i++){ 
//             for(int j=0; j<N; j++){ 
//                 for(int k=0; k<alpha[j].size(); k++){ 
                  
//                     if(alpha[j][k]==word[i][0]&&dfs(alpha,j,k,word[i],0)){ 
//                       //  res.push_back(word[i]);
//                         res.push_back(word[i]);
//                         a=1;
//                         break;
//                     }
//                     if (a) break;
//                 }
//                 if (a) break;
                
//             }
//             a=0;
           
//         }
//         sort(res.begin(),res.end());
//         return res;
//     }

//     bool dfs(vector<vector<char>>&a, int i,int j, string &w, int k){
//     if (k==w.size()) return true;
//     if (i<0||i>=N||j<0||j>=a[i].size()||a[i][j]==0||a[i][j]!=w[k]) {
//         return false;
//     } 
//     char t=a[i][j];
//     a[i][j]=0;
   
//     bool f=dfs(a, i+1, j, w, k+1)||dfs(a, i-1, j, w, k+1)||dfs(a, i, j+1, w, k+1)||dfs(a, i, j-1, w, k+1);
//     a[i][j]=t;
//     if (f) return true;
//     return false;
// }
// };

class TrieNode{
    
public:
    bool is_word;
    string str;
    vector<TrieNode*> ne;
    
    TrieNode(){
        is_word = false;
        ne = vector<TrieNode*>(26, nullptr);
    }
};



class Solution {
public:
    
    TrieNode* root;
    int n, m;
    vector<string> ans;
    vector<vector<char>> data;
    unordered_set<string> tmp;
    vector<vector<bool>> vis;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    void add(string& word) {
        TrieNode* cur = root;
        for (auto c : word) {
            if (cur -> ne[c - 'a'] == nullptr) cur -> ne[c - 'a'] = new TrieNode();
            cur = cur -> ne[c - 'a'];
        }
        cur -> is_word = true;
        cur -> str = word;
    }
    
    void dfs(int x, int y, TrieNode* cur) {
        if (cur -> is_word) {
            if (!tmp.count(cur -> str)) {
                ans.push_back(cur -> str);
                tmp.insert(cur -> str);
            }
        }
        for (int i = 0; i < 4; i ++) {
                int xx = dx[i] + x, yy = dy[i] + y;
                if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy]) continue;
                if (cur -> ne[data[xx][yy] - 'a']) {
                    vis[xx][yy] = true;
                    dfs(xx, yy, cur -> ne[data[xx][yy] - 'a']);
                    vis[xx][yy] = false;
                }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        data = board;
        ans = vector<string>();
        for (auto x : words) add(x);
        n = board.size();
        if (n == 0) return {};
        m = board[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (root -> ne[board[i][j] - 'a']) {
                    vis[i][j] = true;
                    dfs(i, j, root -> ne[board[i][j] - 'a']);
                    vis[i][j] = false;
                }
            }
        }
        return ans;
    }
};

// 作者：acw_wangdh15
// 链接：https://leetcode-cn.com/problems/word-search-ii/solution/trie-hui-su-by-acw_wangdh15-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。