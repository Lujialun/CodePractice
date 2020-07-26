/* 
 * @Descripttion:  矩阵中的最长递增路径 https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-26 09:50:30
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-26 16:51:07
 */ 
#include <bits/stdc++.h>
using namespace std;
static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, columns;

int dfs(vector<vector<int>> &matrix,int r, int c,vector<vector<int>> &memo){
    if(memo[r][c]!=0)
        return memo[r][c];
    ++memo[r][c];
   for (int i = 0; i < 4; ++i) {
            int newRow = r + dirs[i][0], newColumn = c + dirs[i][1];
            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[r][c]) {
                memo[r][c] = max(memo[r][c], dfs(matrix, newRow, newColumn, memo) + 1);
            }
        }
        return memo[r][c];
}


class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, columns;

    int longestIncreasingPath(vector< vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        rows = matrix.size();
        columns = matrix[0].size();
        auto outdegrees = vector< vector<int> > (rows, vector <int> (columns));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int newRow = i + dirs[k][0], newColumn = j + dirs[k][1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[i][j]) {
                        ++outdegrees[i][j];
                    }
                }
            }
        }
        queue < pair<int, int> > q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (outdegrees[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int size = q.size();
            for (int i = 0; i < size; ++i) {//代表一层
                auto cell = q.front(); q.pop();
                int row = cell.first, column = cell.second;
                for (int k = 0; k < 4; ++k) {
                    int newRow = row + dirs[k][0], newColumn = column + dirs[k][1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] < matrix[row][column]) {
                        --outdegrees[newRow][newColumn];
                        if (outdegrees[newRow][newColumn] == 0) {
                            q.push({newRow, newColumn});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/solution/ju-zhen-zhong-de-zui-chang-di-zeng-lu-jing-by-le-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int longestIncreasingPath(vector<vector<int>>& matrix) {//还可拓扑排序
    if(matrix.empty())
        return 0;
    rows = matrix.size();
    columns = matrix[0].size();
    vector<vector<int>> mem(rows, vector<int> (columns,0));
    int res = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            res = max(res, dfs(matrix,i,j,mem));
        }
    }
    return res;
}