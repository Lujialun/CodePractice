/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-09 10:35:05
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-09 11:41:58
 */
#include<bits/stdc++.h>
using namespace std;
string makeGood(string s) {
    int n=s.size();
    if (n<2) return s;
    list<char> l;
    string res;
    for(auto i:s){
        
        l.push_back(i);
    }
   
    int cnt=0;
    while(1){ 
        auto it=l.begin();
         bool end=false;
        for(int i=0; i<n-1; i++){ 
             auto temp=it;
             auto p=it;
             char a=*it;
            if (*it<='z'&&*it>='a'&&*(++it)<='Z'&&*(it)>='A'&&(toupper(a)==*it)) {
                l.erase(temp);
                auto t=it;
                it++;
                l.erase(t);
                n--;
                end=true;
                break;
            }
            
            if (*p<='Z'&&*p>='A'&&*(++it)<='z'&&*(it)>='a'&&(tolower(a)==*it)) {
                l.erase(temp);
                auto t=it;
                it++;
                l.erase(t);
                n--;
                end=true;
                break;
            }
        }
       //  l.push_back(*(l.begin()));
      //   l.erase(l.begin());
        if (!end) break;
       // n=n-cnt;
       // cnt=0;
    }
    for (auto i=l.begin(); i!=l.end(); i++) {
        res.push_back(*i);
    }
    
    return res;
}

int main() {
   string a = "leEeetcode";
    cout << makeGood(a) << endl;
    system("pause");
    return 0;
}