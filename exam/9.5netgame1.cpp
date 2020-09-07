/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-05 13:02:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-05 16:01:26
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

int main()
{
    int N, M,k;
    cin >> N >> M;
    vi price(N+1);
    for (int i = 1; i <= N; i++){
        cin>>price[i];
    }
    stack<int> good[N+1];
    
    string hand, move;
    string l = "left", r = "right",ke="keep",t="take",re="return";
   
    while(M--){
        int bag = 0, lt=0, rt=0,num;
        cin >> k;
        while(k--){
            cin >> hand >> move;
            if(move!="keep"){
                cin >> num;
            }
            
            if(move==ke){
                
                if(hand==l){
                    bag += lt;
                  //  cout << lt << endl;
                    lt = 0;
                }
                else{
                    bag += rt;
                  //  cout << rt << endl;
                    rt = 0;
                }
                    
            }else if(move==t){
                if(good[num].empty()){
                    if(hand==l)
                        lt = price[num];
                    else
                        rt = price[num];
                }else{
                    if(hand==l)
                        lt = good[num].top();
                    else
                        rt = good[num].top();
                   // cout << rt << endl;
                    good[num].pop();
                }
            }else if(move==re){
                int tmp;
                if(hand==l){
                    tmp = lt;
                    lt = 0;
                }else{
                    tmp = rt;
                    rt = 0;
                }
                good[num].push(tmp);
            }

        }
      //  cout << lt << " " << rt << endl;
        bag += lt + rt;
        cout << bag << endl;
    }
    system("pause");
    return 0;
}


/*
5 1
1 2 3 4 5
10
left take 1
left keep
left take 2
left keep
left take 3
left keep
left take 4
left keep
left take 5
left keep


5 3
1 2 3 4 5
5
left take 1
right take 2
left return 3
right keep
right take 4
6
left take 5
right take 1
left return 2
right return 3
left take 5
left return 4
10
left take 1
left keep
left take 2
left keep
left take 3
left keep
left take 4
left keep
left take 5
left keep
*/