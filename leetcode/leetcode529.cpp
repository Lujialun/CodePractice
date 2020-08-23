/*
 * @Descripttion:  529. 扫雷游戏 https://leetcode-cn.com/problems/minesweeper/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-20 10:20:17
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-20 13:44:52
 */

#include <bits\stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, int i, int j) {
    if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]=='B'){
        return;
    }
    if(board[i][j]=='M'){
        board[i][j]='X';
        return;
    }
    int cnt = 0;
    if(i>0&&j>0&&board[i-1][j-1]=='M')
        cnt++;
    if(i>0&&board[i-1][j]=='M')
        cnt++;
    if(i>0&&j<board[0].size()-1&&board[i-1][j+1]=='M')
        cnt++;
    if(j>0&&board[i][j-1]=='M')
        cnt++;
    if(j<board[0].size()-1&&board[i][j+1]=='M')
        cnt++;
    if(i<board.size()-1&&j>0&&board[i+1][j-1]=='M')
        cnt++;
    if(i<board.size()-1&&board[i+1][j]=='M')
        cnt++;
    if(i<board.size()-1&&j<board[0].size()-1&&board[i+1][j+1]=='M')
        cnt++;

    if (cnt > 0){
        board[i][j] = cnt + '0';
        return;
    }

    board[i][j] = 'B';
    dfs(board, i - 1, j - 1);
    dfs(board, i - 1, j);
    dfs(board, i - 1, j + 1);
    dfs(board, i, j - 1);
    dfs(board, i, j + 1);
    dfs(board, i + 1, j - 1);
    dfs(board, i + 1, j);
    dfs(board, i + 1, j + 1);
}
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    dfs(board, click[0], click[1]);
    return board;
}

int main() {

}


// [
//     ["E","E","E","E","E","E","E","E"],
//     ["E","E","E","E","E","E","E","M"],
//     ["E","E","M","E","E","E","E","E"],
//     ["M","E","E","E","E","E","E","E"],
//     ["E","E","E","E","E","E","E","E"],
//     ["E","E","E","E","E","E","E","E"],
//     ["E","E","E","E","E","E","E","E"],
//     ["E","E","M","M","E","E","E","E"]]
// [0,0]

// [
//     ["B","B","B","B","B","B","1","E"],
//     ["B","1","1","1","B","B","1","M"],
//     ["1","2","M","1","B","B","1","1"],
//     ["M","2","1","1","B","B","B","B"],
//     ["1","1","B","B","B","B","B","B"],
//     ["B","B","B","B","B","B","B","B"],
//     ["B","1","2","2","1","B","B","B"],
//     ["B","1","M","M","1","B","B","B"]]