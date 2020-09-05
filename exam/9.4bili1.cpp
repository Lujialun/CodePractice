/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-04 18:33:59
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-04 19:32:49
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


int GetMaxConsecutiveOnes(vector<int>& arr, int k) {
        if(arr.empty()){
            return 0;
        }
        int i = 0, j = 0;
        int ans = 0, cnt = 0;
        while(j<arr.size()){
            if(0==arr[j]){
                cnt++;
            }
            while(cnt>k){
                if(0==arr[i++]){
                    cnt--;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
}
//[1,1,1,0,0,0,1,1,1,1,0],2
int main()
{
    vector<int> a = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << GetMaxConsecutiveOnes(a, 2) << endl;
    system("pause");
    return 0;
}