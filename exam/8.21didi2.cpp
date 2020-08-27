/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-21 18:27:44
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-21 20:33:11
 */
#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main()
{
    long long n;
    vector<long long> f(101);
    f[1] = 1,f[2] = 1;
    for (int i = 3; i <= 100; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    while (cin >> n)
    {
        vector<vector<long long >> res(n, vector<long long>(n));
        vector<vector<bool>> st(n, vector<bool>(n, false));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int cnt = n * n;
        int x = 0, y = 0, d = 0;
        for (int i = 1; i <= n * n; i++){
            res[x][y] = f[cnt--];
            st[x][y] = true;

            int tx = x + dx[d];
            int ty = y + dy[d];

            if (tx < 0||tx>=n||ty<0||ty>=n||st[tx][ty]){
                d = (d + 1) % 4;
                tx = x + dx[d], ty = y + dy[d];
            }
            x = tx, y = ty;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    //system("pause");
    return 0;
}
