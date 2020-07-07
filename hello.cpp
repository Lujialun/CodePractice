#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 void FindNumbersWithSum(vector<int> array,int sum) {
     vector<int> res;
     int left = 0, right = array.size()-1;
     while(left<right){
         int m = (left + right) / 2;
         if(array[m]>sum){
             right = m;
         }else if(array[m]<sum){
             left = m + 1;
         }else{
             left = m;
             break;
         }
     }
     cout << left << " " << right << endl;
}
 int main()
 {
    vector<int> a = {2, 4, 6, 8, 10};
    FindNumbersWithSum(a, 10);
    system("pause");
 }