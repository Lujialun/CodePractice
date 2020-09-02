/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-01 18:25:46
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-01 20:04:21
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
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        vv a(n, vector<int>(n, 0));
        for (int i = 0; i < (n - 1) / 2; i++){
            for (int j = n / 2; j < n - 1-i; j++){
                a[i][j] = 1;
            }
        }

        for (int i = 0; i < n / 2; i++){
            for (int j = i+1; j < n/2; j++){
                a[i][j] = 2;
            }
        }

        for (int i = 1; i < n / 2; i++){
            for (int j = 0; j < i; j++){
                a[i][j] = 3;
            }
        }

        for (int i = n/2; i < n -1; i++){
            for (int j = 0; j <n/2; j++){
                a[i][j] = 4;
            }
        }

        for (int i = n-1; i > n/2; i--){
            for (int j = n-i; j <n/2; j++){
                a[i][j] = 5;
            }
        }
        
        for (int i = n/2; i < n -1; i++){
            for (int j = n/2; j <n; j++){
                a[i][j] = 7;
            }
        }

        for (int i = n-1; i > n/2; i--){
            for (int j = n/2; j <i; j++){
                a[i][j] = 6;
            }
        }

   
        
        for (int i = 1; i < n / 2; i++){
            for (int j = n-1; j > n-i-1; j--){
                a[i][j] = 8;
            }
        }
        for (int i = 0; i < n; i++)
        {
            a[i][i] = 0;
            a[i][n - i - 1] = 0;
        }
        if(n%2==1){
            for (int i = 0; i < n; i++)
            {
                a[i][n/2] = 0;
                a[n/2][i] = 0;
            }
        }
         
        for(auto v:a){
            for(auto i:v){
                cout << i << " ";
            }
            cout << endl;
        }
        
    }
    system("pause");
    return 0;
}