/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-19 15:24:42
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-23 21:21:52
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;
vector<string> res;

void str(string &s, int i, int j){
    if(i>j) return;
    while(s[i]!='{'&&i<j){
        string a;
        if(s[i]=='"')
        {
            while(s[++i]!='"')
            {
                a.push_back(s[i]);
            }
            if(!a.empty()){
                res.push_back(a);
            }
        }
        i++;
    }

    vector<string> b;
    while(s[j]!='}'&&i<j){
        string a;
        if(s[j]=='"')
        {
            while(s[--j]!='"')
            {
                a.push_back(s[j]);
            }
            if(!a.empty()){
                reverse(a.begin(), a.end());
                b.push_back(a);
            }
        }
        j--;
    }
    str(s, i+1, j-1);
    for (auto it:b){
        res.push_back(it);
    }
}
int main()
{
    string s;
    while(getline(cin,s)){
        res.clear();
        cout << "\"";
        if(s.size()<5)
        {
            cout << "" << endl;
            continue;
        }
        // vector<string> tmp;
        // for (int i = 0; i < s.size(); i++){
        //     string a;
        //     if(s[i]=='"')
        //     {
        //         while(s[++i]!='"')
        //         {

        //             a.push_back(s[i]);
        //         }
        //         if(!a.empty()){
        //             tmp.push_back(a);
        //         }
        //     }
        // }
        str(s, 1, s.size() - 2);
        if(res.empty())
        {
            cout << "\"" << endl;
            continue;
        }
        for (int i = 0; i < res.size() - 1; i++)
        {
            cout << res[i] << '\\' << 'n';
        }
        cout << res[res.size() - 1];
        cout << "\"" << endl;
    }

    system("pause");
    return 0;
}