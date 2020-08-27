/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-24 09:55:30
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-24 11:38:05
 */
/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-24 09:55:30
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-24 11:14:44
 */
#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include <numeric>
using namespace std;

// int Max_avr(vector<int> &a, int l, int r){
//     int k, sum = 0;
//     if(l==r){
//         return a[l] >= 0 ? a[l] : 0;
//     }else{
//         int center = (l + r) / 2;
//         int lsum = Max_avr(a, l, center);
//         int rsum = Max_avr(a, c, center);
//     }
// }

// long long Max_Avr(vector<long long>& a, int k){
//     long long Sum1 = accumulate(a.begin(), a.begin()+k, 0);
//     long long sum = Sum1, res = Sum1 / k;
//     for (int i = k; i < a.size(); ++i){
//         Sum1 += a[i];
//         sum = Sum1;
//         if(sum>res*(i+1))
//             res = sum / (i + 1);
//         for (int j = 0; j <= i - k; ++j){
//             sum -= a[j];
//             if(sum>res*(i-j))
//                 res = sum / (i - j);
//         }
//     }
//     return res;
// }

long long Max_Avr(vector<long long>& a, int k){
    int n = a.size();
    vector<long long> sums(n + 1, 0);
    long long left = *min_element(a.begin(), a.end());
    long long right = *max_element(a.begin(), a.end());
    while(left<right-1){
        long long minSum = 0, mid = left + (right - left) / 2;
        bool check = false;
        for (int i = 1; i <= n; ++i){
            sums[i] = sums[i - 1] + a[i - 1] - mid;
            if(i>=k){
                minSum = min(minSum, sums[i - k]);
            }
            if(i>=k&&sums[i]>minSum){
                    check = true;
                    break;
            }

        }
        if(check)
                left = mid;
        else
                right = mid;
      //      cout << left<<" "<<mid<< " "<<right << endl;
    }
    return left+1;
}
int main()
{
    int n;
    while(cin>>n){
        vector<long long > a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << Max_Avr(a, 1) << endl;
    }
    //system("pause");
    return 0;
}