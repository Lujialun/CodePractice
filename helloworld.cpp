#include <bits/stdc++.h>
using namespace std;

    bool judge(vector<vector<char>>& board, string &word, vector<vector<bool>> &f)
    {
        return true;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> f;
        f.resize(board.size());
        for (int i = 0; i < board.size(); i++){
            f[i].resize(board[0].size());
        }

            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; i < board[i].size(); j++)
                {
                    if (board[i][j] == word[0])
                    {
                    }
                }
            }
    }

int main()
{
    vector<int> a = {10,1,10,10,10};
  //  cout << minNumberInRotateArray(a) << endl;
    system("pause");
}