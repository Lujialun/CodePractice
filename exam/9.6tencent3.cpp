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

// struct TrieNode{
//     bool  isEnd;
//     TrieNode* branch[256];
//     //int times;
//     //string s;
//     pair<int,string> show ;
//     TrieNode():isEnd(false ){
//         show.first=0;
//         for(int i=0;i<256; i++){
//              branch[i]=nullptr;
//         }
//     }
// };
struct comp{
        bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first>b.first) return true;
            if(a.first<b.first) return false;
            if(a.second>=b.second) return false;
            return true;
        }
};

struct comp1{
        bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first>b.first) return false;
            if(a.first<b.first) return true;
            if(a.second>=b.second) return false;
            return true;
        }
};

vector<int> ans;
vector<string> topKFrequent(vector<string> &words, int k)
{
    vector<string> res;
    unordered_map<string, int> dic;
    comp com;
    for (auto i : words)
    {
        dic[i]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> p;
    for (auto it : dic)
    {
        pair<int, string> tmp{it.second, it.first};
        if (p.size() < k)
        {
            p.push(tmp);
        }
        else if (com(tmp, p.top()))
        {
            p.push(tmp);
            p.pop();
        }
    }
    while (k--)
    {
        ans.pb(p.top().first);
        res.pb(p.top().second);
        p.pop();
    }
    reverse(ans.begin(), ans.end());
    reverse(res.begin(), res.end());
    return res;
}

vector<string> lowKFrequent(vector<string> &words, int k)
{
    vector<string> res;
    unordered_map<string, int> dic;
    comp1 com;
    for (auto i : words)
    {
        dic[i]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, comp1> p;
    for (auto it : dic)
    {
        pair<int, string> tmp{it.second, it.first};
        if (p.size() < k)
        {
            p.push(tmp);
        }
        else if (com(tmp, p.top()))
        {
            p.push(tmp);
            p.pop();
        }
    }
    while (k--)
    {
        ans.pb(p.top().first);
        res.pb(p.top().second);
        p.pop();
    }
    reverse(ans.begin(), ans.end());
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int N,t;
    cin >> N>>t;
    vector<string> word;
    while(N--){
        string s;
        cin >> s;
        word.pb(s);
    }
    vector<string> res;
    res = topKFrequent(word, t);
    //cout << t << endl;
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " " << ans[i] << endl;
    }
    ans.clear();
    res = lowKFrequent(word, t);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " " << ans[i] << endl;
    }
    system("pause");
    return 0;
}
