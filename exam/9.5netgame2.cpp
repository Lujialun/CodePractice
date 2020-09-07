/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-05 13:02:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-05 17:29:26
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

int t,p,q,w,h;
int i, j, a, b,sum;
void act_make_c( vector<pair<int, int>> &a,int i,int j){
    a.push_back(make_pair(i, j));
    a.push_back(make_pair(i, p+j-1));
    a.push_back(make_pair(i+q-1, p+j-1));
    a.push_back(make_pair(i+q-1, j));
}

bool judge(vector<pair<int, int>> &a){
    for (int i = 0; i < 4; i++){
        if(a[i].first>0&&a[i].first<=h&&a[i].second>0&&a[i].second<=w){
            return true;
        }
    }
    return false;
}

int draw( vector<string> &act, vector<string> &ss,  vector<string> se, vector<pair<int, int>> &a_c){

   // cout << a_c[0].first << " " << a_c[0].second << endl;
    for (int u = 0; u < act.size(); u++){
      
        for (int t = 0; t < act[0].size(); t++){
              cout << "ee" << endl;
            int ii = u + a_c[0].first, jj = t + a_c[0].second;
            //cout << ii << " " << h << " "<< jj << " " << w << endl;
            if(ii>0&&ii<=h&&jj>0&&jj<=w){
                se[ii][jj] = act[u][t];
             //   cout << " sss" << endl;
            }
        }
    }
    int cnt = 0;
    for (int u = 1; u < ss.size(); u++){
        for (int t = 1; t < ss[0].size(); t++){
            if(ss[u][t]!=se[u][t])
                cnt++;
        }
    }
    ss = se;
    for (int i = 0; i < 4; i++)
    {
        a_c[i].first =a_c[i].first+a;
        a_c[i].second =a_c[i].second + b;
    }
  //  cout << cnt << endl;
    return cnt;
}
int main()
{
    cin >> t;
    while(t--){
        cin >> w >> h;
        vector<string> screen(h+1);
        char ch;
        for (int i = 1; i <=h; i++)
        {
            screen[i].pb(0);
            for (int j = 0; j < w; j++){
                std::cin >> ch;
                screen[i].pb(ch);
            }
        }
        vector<string> em=screen;
        std::cin >> p >> q;
        vector<string> act(q);
        for (int i = 0; i < q; i++)
        {
            for (int j = 0; j < p; j++){
                std::cin >> ch;
                screen[i].pb(ch);
            }
        }
       // cout << act.size() << endl;
        std::cin >> i >> j >> a >> b;
       vector<pair<int, int>> act_c;
       act_make_c(act_c,i,j);
        sum = 0;
        while(judge(act_c)){
          //  cout << "here" << endl;
            sum += draw(act, screen,em,act_c);
        }
        cout << sum << endl;
    }
    system("pause");
    return 0;
}


/*
1
4 4
....
....
....
....
3 3
.O.
/|\
./\
0 0 1 1
*/