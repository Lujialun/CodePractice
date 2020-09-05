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

vector<int> SpiralMatrix(vector<vector<int> >& matrix) {
    if(matrix.empty())
        return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans(m * n);
    int i = 0, j = n - 1, k = 0, p = m - 1, q = -1,t;
    while(q<m*n-1){
        for (t = i; t <= j && ++q < m * n; t++){
            ans[q] = matrix[k][t];
        }
        k++;

        for (t = k; t <= p && ++q < m * n; t++){
            ans[q] = matrix[t][j];
        }
        j--;

        for (t = j; t >= i && ++q < m * n; t--){
            ans[q] = matrix[p][t];
        }
        p--;

        for (t = p; t >= k && ++q < m * n; t--){
            ans[q] = matrix[t][i];
        }
        i++;
    }
    return ans;
}

int main()
{
    
    system("pause");
    return 0;
}