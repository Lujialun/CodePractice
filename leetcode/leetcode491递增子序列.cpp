/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-25 17:02:46
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-25 17:05:25
 */
#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> temp; 
    vector<vector<int>> ans;

    void dfs(int cur, int last, vector<int>& nums) {//从下面的例子理解
        if (cur == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
                for(auto i:temp){
                    cout<<i<<" ";
                }
                cout<<endl;
            }
            return;
        }
        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last) {//关键地方 有重复的地方只选第二个不选第一个
            dfs(cur + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return ans;
    }
};


/*

[4, 6, 7, 7]

4 6 7 7 
4 6 7 
4 6 
4 7 7 
4 7 
6 7 7 
6 7 
7 7 

*/