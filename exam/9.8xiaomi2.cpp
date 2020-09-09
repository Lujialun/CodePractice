/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-08 18:42:46
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-08 19:08:11
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
int n, m;
bool dfs(vector<vector<char>>& dic,int y, int x, string &word, int i){
    if(i==word.size()){
        return true;
    }
    if(x<0||y<0||y==n||x==m){
        return false;
    }
    if(word[i]!=dic[y][x]){
        return false;
    }
    dic[y][x] = '*';
    bool res = dfs(dic, y - 1, x, word, i + 1) || dfs(dic, y, x - 1, word, i + 1) || dfs(dic, y + 1, x, word, i + 1) || dfs(dic, y, x + 1, word, i + 1);
    dic[y][x] = word[i];
    return res;
}

int main(){

    
    string word;
  //  n = dic.size(), m = dic[0].size();
//   cin >> n >> m;
    n = 3, m = 4;
    vector<vector<char>> dic(n,vector<char>(m));
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cin >> dic[i][j];
    //     }
    // }
    dic[0][0] = 'A', dic[0][1] = 'B', dic[0][2] = 'C', dic[0][3] = 'E';
    dic[1][0] = 'S', dic[1][1] = 'F', dic[1][2] = 'C', dic[1][3] = 'S';
    dic[2][0] = 'A', dic[2][1] = 'D', dic[2][2] = 'E', dic[2][3] = 'E';
    
    while(cin >> word){

    
    int f = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(dfs(dic,i,j,word,0)){
                cout << "true" << endl;
                f = 1;
            }
        }
    }
    if(!f){
        cout << "false" << endl;
    }
    }
    system("pause");
}