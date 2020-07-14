/*
 * @Descripttion: 523. 连续的子数组和 https://leetcode-cn.com/problems/continuous-subarray-sum/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-13 17:30:54
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-13 21:53:17
 */ 
#include<bits/stdc++.h>
using namespace std;


bool checkSubarraySum1(vector<int>& nums, int k) {//前缀和
    if(nums.empty())
        return false;
    vector<int> pre_sum(nums.size());
    pre_sum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++){
        pre_sum[i] += nums[i];
    }
    for (int start = 0; start < nums.size()-1; start++){
        for (int end = start + 1; end < nums.size(); end++){
            int sum = pre_sum[end]-pre_sum[start]+nums[start];
            if((sum==k)||(k != 0 && sum % k == 0))
                return true;
            
        }
    }
    return false;
}

bool checkSubarraySum2(vector<int>& nums, int k) {//hash表
     if(nums.empty())
        return false;
     unordered_map<int,int> hash;
     int sum = 0;
     for (int i = 0; i < nums.size(); i++){
         sum += nums[i];
         int temp = k == 0 ? sum : sum % k;
         if(hash.find(temp)!=hash.end()){
             if(i-hash[temp]>1)
                 return false;
             continue;
         }
         hash[temp] = i;
     }
     return false;
}

int main()
{
    
    system("pause");
    return 0;
}