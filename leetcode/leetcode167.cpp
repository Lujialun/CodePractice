/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-20 14:25:33
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-20 16:02:00
 */ 
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    if(numbers.size()<2)
        return res;
    int i = 0, j = numbers.size() - 1;
    // while(i<j){
    //     int m = i + (j - i) / 2;
    //     if(numbers[m]<target){
    //         i = m+1;
    //     }else{
    //         j = m;
    //     }
    //           //cout << i << " " << j << endl;
    // }


    // j = (i+1)>=numbers.size()-1?numbers.size()-1:(++i);
    // i = 0;
    j = lower_bound(numbers.begin(), numbers.end(), target) -numbers.begin();
    j = (j == numbers.size()) ? --j : j;
    while(i<j){
        int tmp = numbers[i] + numbers[j];
        if(tmp==target){
            res.push_back(i+1);
            res.push_back(j+1);
            break;
        }else if(tmp>target){
            j--;
        }else{
            i++;
        }
    }
    return res;
}

int main()
{
    vector<int> a = {-1,1,2,3,4,5};
   vector<int> b = twoSum(a, 2);
//  cout << b[0] << " " << b[1] << endl;
    system("pause");
    return 0;
}