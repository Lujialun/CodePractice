/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-04 18:34:26
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-04 19:54:56
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


int GetFragment(string str) {
    if(str.size()<2)
        return str.size();
    unsigned int sum=0, cnt=0;
    int i = 0, j = 1;
    while(j<str.size()){
        if(str[i]==str[j]){
            j++;
        }else{
            cnt++;
            sum += j - i;
            i = j++;
        }
    }
    cnt++;
    sum += j - i;
    return sum / cnt;
}


int main()
{
    cout << GetFragment("aaabbaaac") << endl;
    system("pause");
    return 0;
}