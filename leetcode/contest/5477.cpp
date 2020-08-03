/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 10:52:56
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 14:16:03
 */ 
#include <bits/stdc++.h>
using namespace std;
//[[1,0,0,0,0,0],[0,0,0,1,0,0],[0,0,0,1,0,0],[0,1,0,0,0,0],[0,0,1,0,0,0],[0,0,0,0,0,1]]
// int swap_(vector<vector<int>>& g, int i){
//     for (int p = 0; p<g[0].size(); p++){
//        swap(g[i][p], g[i + 1][p]);
//     }
// }
// int minSwaps(vector<vector<int>>& grid) {
//     int cnt=0;
//     int m = grid.size(), n = grid[0].size();
//     for(int i=n-1; i>=1; i--){
//         int cnt_1 = 0;
//         for (int j = 0; j<m; j++){
//             if(grid[j][i]==1)
//                 cnt_1++;
//             if(cnt_1>)
//         }
            
        
//     }
//     return cnt;
// }

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); //网格规模
        vector<int> a; //记录每一行后缀0个数的数组
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = n - 1; j >= 0; j--)
            {
                if(grid[i][j] == 0) count++; //数每一行的后缀0
                else break;
            }
            a.push_back(count); 
        }
        int count = 0; //交换次数
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] >= n - i - 1) continue;//满足条件，该行直接跳过
            else{//不满足条件
                int j = i; //用新参数遍历找满足条件的后缀0
                for(; j < n; j++)
                {
                    if(a[j] >= n - i - 1) break;
                }
                if(j == n) return -1; //找不到，直接返回-1
                for(; j > i; j--) //找到了最先满足条件的后缀0个数 
                {
                    swap(a[j], a[j - 1]); //每一行交换上去
                    count++; //记录交换次数
                }
            }
        }
        return count;
    }
};

作者：spacex-1
链接：https://leetcode-cn.com/problems/minimum-swaps-to-arrange-a-binary-grid/solution/c-tan-xin-hou-zhui-0-by-spacex-1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。