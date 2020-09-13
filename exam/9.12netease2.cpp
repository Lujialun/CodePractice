/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-12 15:50:17
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-12 16:41:54
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

vector<string> res;
void dfs(vector<vector<string>> &a, string ans, int level){
   
    if(level==a.size()){
      //  cout << ans << endl;
        ans.pop_back();
        res.push_back(ans);
        return;
    }
    
    for (int i = 0; i < a[level].size(); i++){
        string tmp = ans;
        ans += a[level][i] + "-";
        dfs(a, ans, level + 1);
        ans = tmp;
    }
} 

int main()
{
    int n;
    vector<vector<string>> a;
    cin >> n;
    while(n--){
        string t1,t2;
        vector<string> tmp;
        getline(cin,t1);
        if(t1==""){
            n++;
            continue;
        }
       // cout << t1 << endl;
        for(auto i:t1){
            if(i!=' '){
                t2.pb(i);
            }else{
         //       cout << t2 << endl;
                tmp.pb(t2);
                t2.clear();
            }
        }
       //  cout << t2 << endl;
        tmp.pb(t2);
        //  cout << "hh" << iendl;
        a.pb(tmp);
        
    }
    // for (int i = 0; i < a.size(); i++){
    //     for (int j = 0; j < a[i].size(); j++){
    //         cout << a[i][j] << endl;
    //     }
    // }
        string q = "";
    dfs(a, q, 0);
    int m = a[0].size();
    vector<string> ans;
    for (int i = 0; i < res.size()/m;i++)
    {
        for (int j = i; j < m; j++){
            ans.pb(res[j + res.size()/m*j]);
        }
            
    }
    for (auto i : ans)
    {
        cout << i << endl;
    }


    system("pause");
    return 0;
}