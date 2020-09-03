/*
 * @Descripttion: https://leetcode-cn.com/problems/n-queens/solution/gen-ju-di-46-ti-quan-pai-lie-de-hui-su-suan-fa-si-/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-03 21:50:42
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-03 22:08:00
 */
class Solution {
public:
    void dfs(int row, int n, vector<vector<string>>& res, vector<string> a, vector<int> col, vector<int> dg, vector<int> adg){
        if(row == n){ //符合条件，直接存进数组
            res.push_back(a);
            return ;
        }
        for(int i = 0; i < n; i++){
            if(!col[i] && !dg[row - i + n] && !adg[row + i]){//说明该位置合法
            //这里注意一下，因为行与列的差值可能为负，所以dg下标要加一个n
                col[i] = dg[row - i + n] = adg[row + i] = 1; //将该位置的列，正对角线，反对角线的值都置1
                a[row][i] = 'Q'; //设置Q
                dfs(row + 1, n, res, a, col, dg, adg); //深度优先搜索
                col[i] = dg[row - i + n] = adg[row + i] = 0; //重置，以便下次查找该行合适位置
                a[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res; //存储最终结果
        vector<string> a(n, string(n, '.')); //临时结果
        vector<int> col(n, 0);  //存储已有的列值
        vector<int> dg(2 * n, 0); //存储已有的正对角线的值
        vector<int> adg(2 * n, 0); //存储已有的反对角线的值
        dfs(0, n, res, a, col, dg, adg); //深度优先搜索回溯
        return res;
    }
};


class Solution {
public:
    static const int M = 20;
    int row[M], col[M], dg[M], udg[M];
    vector<string> a;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        a.resize(n, string(n, '.'));
        dfs(0, n);
        return res;    
    }

    void dfs(int u, int n) {
        if (u == n) {
            res.push_back(a);
        }
        for (int i = 0; i < n; i ++) {
            if (!row[i] && !col[i] && !dg[u - i + n] && !udg[i + u]) {
                a[u][i] = 'Q';
                row[i] = col[i] = dg[u - i + n] = udg[i + u] = 1;
                dfs(u + 1, n);
                a[u][i] = '.';
                row[i] = col[i] = dg[u - i + n] = udg[i + u] = 0;
            }
        }
    }
};

