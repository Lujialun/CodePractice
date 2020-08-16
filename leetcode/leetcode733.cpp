/*
 * @Descripttion:  https://leetcode-cn.com/problems/flood-fill/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-16 11:30:47
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-16 14:42:13
 */
#include<bits\stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>> &image, int i, int j, int c,int v) {
    if (i < 0 || i >= image.size() || j < 0||j>=image[0].size()||image[i][j]!=v)
        return;
    image[i][j] = c;
    dfs(image, i + 1, j, c, v);
    dfs(image, i - 1, j, c, v);
    dfs(image, i, j+1, c, v);
    dfs(image, i, j-1, c, v);
    
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if(image[sr][sc]==newColor) return image;
    dfs(image, sr, sc, newColor, image[sr][sc]);
    return image;
}
};