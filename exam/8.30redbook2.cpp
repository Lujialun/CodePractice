/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-30 18:54:48
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-30 21:01:49
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


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void splitMsg(string s,vector < string > &res) {
    if(s.size()<1024){
        
        return;
    }
    // int i = s.find_first_of('.');
    
    // res.push_back(s.substr(0, i+1));
    // splitMsg(s.substr(i+2, s.size() - 1),res);
}
/******************************结束写代码******************************/


int main() {

    string s,tmp;
    
    char ch;
    int cnt = 0;
    int j = 100000;
    while(ch=cin.get()){
        //cout << s.size() << endl;
        j--;
        if(j==0)
            break;

        if((ch=='\n'||ch=='.')&&!s.empty()) {
            vector < string > res;
            res.push_back(s);
            for(int res_i=0; res_i < res.size(); res_i++) {
            // cout << res.size()<<res_i << endl;
     	    cout <<res[res_i] << endl;;
            s.clear();
         }
        }
        else
            s.push_back(ch);
        //cout << res.size() << endl;
        
        
    }
    // cout << res.size() << endl;
    // for(int res_i=0; res_i < res.size(); res_i++) {
    //         cout << res.size()<<res_i << endl;
    // 	    cout <<"msg"<<res_i+1<<":"<< res[res_i] << endl;;
    // }
    // cout << res[1] << endl;
    system("pause");
    return 0;

}
