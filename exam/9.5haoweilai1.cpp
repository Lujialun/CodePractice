/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-05 13:02:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-05 14:11:02
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
#define vl vector<int>
using namespace std;

int main()
{
    string a, b;
    while(cin>>a>>b){

        bool ch[26];
        cl(ch, false);
        for(auto i:a){
            ch[i - 'a'] = true;
        }
        int f = false;
        for(auto i:b){
            if(!ch[i-'a']){
                cout << "false" << endl;
                f = true;
                break;
            }
        }
        if(!f){
             cout << "true" << endl;
        }


        // if(a.find(b)!=a.npos){
        //     cout << "true" << endl;
        // }else{
        //     cout << "false" << endl;
        // }
    }
    system("pause");
    return 0;
}
