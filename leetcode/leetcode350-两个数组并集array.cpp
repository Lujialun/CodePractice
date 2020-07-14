/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-13 11:58:47
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-13 14:48:54
 */ 
#include<bits/stdc++.h>
using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if(nums1.empty()||nums2.empty())
         return res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int j = 0, i = 0;
    while(i<nums1.size()&&j<nums2.size()){
        if(nums1[i]>nums2[j]){
            j++;
        }else if(nums1[i]<nums2[j]){
            i++;
        }else{
            res.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    vector<int> a = {5, 3, 4};
    vector<int> b = {1, 2, 4,5};
    vector<int> c = intersect(a, b);
    for(auto i:c)
        cout << i << endl;
    system("pause");
    return 0;
}