#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 vector<int> FindNumbersWithSum(vector<int> array,int sum) {
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

     int cur=left;
     for(int i=0; i<=left&&i<cur; i++){
        if(array[i]+array[cur]>sum){
            //cout<<array[i]<<"here"<<array[cur]<<endl;
            cur--;
            i=-1;
        }else if(array[i]+array[cur]<sum){
            continue;
        }else{

            res.push_back(array[i]);
            res.push_back(array[cur]);
            return res;
        }
     }
     return res;


}
 void FindNumsAppearOnce(vector<int> data,int* num1,int* num2) {
        unordered_set<int> res;
        for(int i=0; i<data.size(); i++){
            auto it=res.find(data[i]);
            if(it!=res.end()) res.erase(it);
            else res.insert(data[i]);
        }
        int a=*(res.begin());
        int b=*(++res.begin());
    //    cout<<a<<" "<<b<<endl;
        *num1=*res.begin();
        *num2=*(res.begin()+1);
    }
 int main()
 {
    vector<int> a = {2,4,3,6,3,2,5,5};
    int *c,*b;
    FindNumsAppearOnce(a,c,b);

    cout<<*c<<" "<<*b<<endl;

    system("pause");
 }
