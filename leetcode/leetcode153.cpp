/*
 * @Descripttion: 寻找旋转排序数组中的最小值 https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-22 00:51:43
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-22 01:28:21
 */ 

#include <bits/stdc++.h>
using namespace std;

 int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while(left<right){
            int m=left+(right-left)/2;
            if(nums[right]>nums[m]){
                left=m+1;
            }else{
                right=m;
            }
        }
       
        return nums[left];
    }

int main()
{
    vector<int> a = {4,5,6,7,0,1,2};
    cout << findMin(a) << endl;
    system("pause");
}