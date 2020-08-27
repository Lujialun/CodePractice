/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-26 18:52:40
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-26 21:29:09
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unistd.h>
using namespace std;

bool func(vector<int>& arr, const string& s, int i,int& j){
    int n;
    for (; j < s.size(); ++j){
        if(s[j]=='[')
            i = j + 1;
        else if(s[j]==','){
            n = stoi(s.substr(i, j - i));
            if(n<1||n>100){
                cout << 0 << endl;
                return false;
            }
            arr.push_back(n);
            i = j + 1;
        }else if(s[j]==']'){
            n = stoi(s.substr(i, j - i));
            
            if(n<1||n>100){
                cout << 0 << endl;
                return false;
            }
            arr.push_back(n);
            return true;
        }else if('0'>s[j]||s[j]>'9'){
            return false;
        }
    }
    return true;
}

int main()
{

  //  vector<int> x, ys;
    string s;
    cin >> s;
    
    system("pause");
    return 0;
}