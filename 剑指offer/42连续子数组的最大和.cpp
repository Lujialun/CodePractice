/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-13 17:19:40
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-13 17:31:39
 */ 
#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int res = nums[0], temp = nums[0];
    for (int i = 1; i < nums.size(); i++){
        temp = max(nums[i], temp + nums[i]);
        res = max(res, temp);
    }
    return res;
}