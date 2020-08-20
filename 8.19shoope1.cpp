/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-19 15:24:42
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-19 16:31:43
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s)){
        cout << "\"";
        if(s.size()<5)
        {
            cout << "" << endl;
            continue;
        }
        string tmp;
        for (int i = 0; i < s.size(); i++){
            if(s[i]=='"')
            {
                while(s[++i]!='"')
                {

                    tmp.push_back(s[i]);
                }
            }

        }
        if(tmp.empty())
        {
            cout << "\"" << endl;
            continue;
        }
        for (int i = 0; i < tmp.size() - 1; i++)
        {
            cout << tmp[i] << '\\' << 'n';
        }
        cout << tmp[tmp.size() - 1];
        cout << "\"" << endl;
    }

    system("pause");
    return 0;
}