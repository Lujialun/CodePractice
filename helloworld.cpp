/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-14 19:29:44
 */ 



#include<iostream>


#include<vector>


#include<algorithm>

using namespace std;

int main() {
    int N,d;
    cin >> N >> d;
    int n = N * N;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[0]==a[n-1])
    {
        cout << 0 << endl;
        return 0;
    }
    int ans=0;
    for (int i = 0; i < n-1; i++)
    {
        if((a[n-1]-a[i])%d==0)
        {
            ans += (a[n - 1] - a[i]) / d;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}