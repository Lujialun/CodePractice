/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-26 18:52:52
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-26 19:59:44
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;

void Move(unsigned int & n, vector<char> &a){
    static char bits[32];
    int i;
    for (i = 0; i < 32; ++i){
        if(n&1) bits[32 - i - 1] = 1;
        else bits[32 - i - 1] = 0;
        n >>= 1;
    }
    for (int i = 0; i < 16; ++i)
        swap(bits[i * 2], bits[i * 2 + 1]);
    for (i = 0; i < 32; ++i){
        if(bits[i]==1)  a.push_back(1);
        else    a.push_back(0);
    }
}

int main()
{

    vector<char> a;
    unsigned int n;
    while(cin>>n){
        Move(n, a);
    }
    a.insert(a.begin(),a.back());
    a.pop_back();
    a.insert(a.begin(), a.back());
    a.pop_back();
    bool flag = true;
    unsigned p = 0, res = 0;
    for(auto i:a){
        ++p;
        if(1==i){
            res += 1;
        }
        if(32==p){
            if(flag){
                flag = false;
                cout << res;
            }else cout << " " << res;
            p = res = 0;
        }else   res *= 2;
    }
    // unsigned int n;
    // vector<unsigned int> a;
    // cin >> n;
    // a.push_back(n);
    // while(cin.get()!='\n'){
    //     a.push_back(n);
    // }


   
   // system("pause");
    return 0;
}