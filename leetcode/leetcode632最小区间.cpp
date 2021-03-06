/*
 * @Descripttion: https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/ 参考题23
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-01 17:28:47
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-01 23:17:17
 */ 
#include <bits/stdc++.h>
using namespace std;
//给定 kk 个列表，需要找到最小区间，使得每个列表都至少有一个数在该区间中。该问题可以转化为，从 kk 个列表中各取一个数，使得这 kk 个数中的最大值与最小值的差最小。
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int rangeLeft = 0, rangeRight = INT_MAX;//初始区间
        int size = nums.size();
        vector<int> next(size);//记录每一行长度的数组，因为每一行都要包含一个值所以一个访问完就要break
        
        auto cmp = [&](const int& u, const int& v) {//比较方式，达到插入索引实际比较的是数组中的值 ，最小堆
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);//计算出第一个中最大值
        }

        while (true) {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }
            if (next[row] == nums[row].size() - 1) {
                break;
            }
            ++next[row];
            maxValue = max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }

        return {rangeLeft, rangeRight};
    }
};

