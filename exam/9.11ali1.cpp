/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-11 08:46:52
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-11 09:47:16
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
int nn[15],n,m,res=0,len;
string word;
string sen;
void get_next(){
    int j = 0, k = -1;
    nn[0] = -1;
    while(j<len){
        if(k==-1||sen[j]==sen[k]){
            j++, k++;
            if(sen[j]!=sen[k]){
                nn[j] = k;
            }else{
                nn[j] = nn[k];
            }
        }else{
            k = nn[k];
        }
    }
}

void kmp(int pos){
    int i = pos, j = 0;
    while(i<n&&j<len){
        if(j==-1||word[i]==sen[j]){
            i++, j++;
        }else{
            j = nn[j];
        }
        if(j>=len){
           
            res++;
            j = nn[j];
        }
    }
}
int main()
{
    cin >> n >> m;
    
    cin >> word;
    
  
    while(m--){
        cin >> sen;
        len = sen.size();
        get_next();
        kmp(0);
    }
    cout << res << endl;
    system("pause");
}