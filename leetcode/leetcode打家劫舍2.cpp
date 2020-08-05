/*
 * @Descripttion: https://leetcode-cn.com/problems/house-robber-ii/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-05 14:36:18
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-05 18:48:19
 */
class Solution {
public:
    int rob(vector<int>& nums) {//遍历两遍，分两种情况讨论，也可遍历一编，开两个数组即可
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[1],nums[0]);
        int n=nums.size();
        vector<int> f(n,0);
        f[0]=nums[0],f[1]=max(f[0],nums[1]);
        for(int i=2; i<n-1; i++){
            f[i]=max(f[i-1],f[i-2]+nums[i]);
        }
        int a=f[n-2];
        f[0]=0,f[1]=nums[1];
        for(int i=2; i<n; i++){
            f[i]=max(f[i-1],f[i-2]+nums[i]);
        }
        return a>f[n-1]?a:f[n-1];
    }
};