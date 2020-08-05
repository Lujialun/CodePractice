/*
 * @Descripttion: https://leetcode-cn.com/problems/house-robber/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-05 14:24:53
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-05 14:24:57
 */
class Solution {
public:
    int rob(vector<int>& nums) {//转移方程：f[i]=max(f[i-1],f[i-2]+v);
        if(nums.empty()) return 0;
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
      //  vector<int> f(n,0);
        //f[0]=nums[0],f[1]=max(f[0],nums[1]),f[2]=max(f[1],f[0]+nums[2]);
        nums[1]=max(nums[0],nums[1]),nums[2]=max(nums[1],nums[0]+nums[2]);
        for(int i=3; i<n; i++){
            nums[i]=max(nums[i-1],nums[i-2]+nums[i]);
        }
        return nums[n-1];
    }
};