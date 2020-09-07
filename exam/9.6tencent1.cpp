/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-06 19:55:53
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-06 20:14:00
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

// struct ListNode{
//     int value;
//     ListNode * next;
//    ListNode():value(0),next(NULL){}
//    ListNode(int x):value(x),next(NULL){}
// };


int main()
{
    // ListNode *h1=new ListNode();
    // ListNode *h2=new ListNode();
    int n, m;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    vi b(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    vi res;
    int i = 0,j = 0;
    while(i<n&&j<m){
        if(a[i]==b[j]){
            res.pb(a[i]);
            i++, j++;
        }else if(a[i]>b[j]){
            i++;
        }else{
            j++;
        }
    }
    for(auto i:res){
        cout << i <<" ";
    }
    cout << endl;
    system("pause");
    return 0;
}
