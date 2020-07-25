/*
 * @Descripttion: 410. 分割数组的最大值 https://leetcode-cn.com/problems/split-array-largest-sum/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-25 20:37:24
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-25 22:03:58
 */ 
#include <bits\stdc++.h>
using namespace std;

int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    vector<long long> sub(n+1, 0);
    for (int i = 0; i < n; i++){
        sub[i+1] = sub[i] + nums[i];//存储第1个到第n个前缀和
    }
    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LONG_LONG_MAX));
    f[0][0] = 0;//考虑 j=1，k=0的情况
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= min(m,i); j++){//m不能超过i
            for (int k = 0; k < i; k++){
                f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
            }
        }
    }
    return f[n][m];
}

class Solution {
public:
    bool check(vector<int>& nums, int x, int m) {
        long long sum = 0;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > x) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int i = 0; i < nums.size(); i++) {//和在left与right之间
            right += nums[i];
            if (left < nums[i]) {
                left = nums[i];
            }
        }
        while (left < right) {
            long long mid = (left + right) >> 1;
            if (check(nums, mid, m)) {//大于x就分段，段数大于m说明此和不是最小的
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

