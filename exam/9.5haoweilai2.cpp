/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-05 13:02:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-05 14:54:50
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#define fir first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define ui unsigned int
#define cl(a, b) memset(a, b, sizeof(a))
#define quickio(a) ios::sync_with_stdio(a)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vv vector<vector<int>>
#define vi vector<int>
using namespace std;

void QuickSort(vector<int> &a, int left,int right)
{
    if(left>=right) return;
    int i=left;
    int j=right;
    int base=a[left],temp;  
    while(i<j){
        while(j>i&&a[j]>=base) j--; 
        while(i<j&&a[i]<=base) i++; 
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[left]=a[i];
    a[i]=base;
    QuickSort(a,left,i);
    QuickSort(a,i+1,right);

}

int main()
{
    vi a;
    char ch;
    while(cin>>ch){
        if(ch!='#'){
            a.push_back(ch - '0');
        }else
            break;
    }
    // for(auto i:a){
    //     cout << i << " ";
    // }
    stack<int> s;
    s.push(0), s.push(a.size() - 1);
    int r, l, base;
    while(!s.empty()){
        r = s.top();
        s.pop();
        l = s.top();
        s.pop();
        base = a[l];
        int num = l;
        while(l<r){
            while(l<r&&a[r]>=base)
                r--;
            while(l<r&&a[l]<=base)
                l++;
            int temp=a[l];
            a[l]=a[r];
            a[r]=temp;
        }
        a[num] = a[l];
        a[l] = base;
        if(num<l-1){
            s.push(num);
            s.push(l - 1);
        }
        if(l+1<r){
            s.push(l + 1);
            s.push(r);
        }
    }
    //sort(a.begin(), a.end());
    QuickSort(a, 0, a.size());
    for(auto i:a){
        cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

