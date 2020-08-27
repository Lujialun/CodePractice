#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x,h;
    while(cin>>n>>m>>x){
        priority_queue<int, vector<int>, greater<int>> q;
        while(n--){
            cin >> h;
            q.push(h);
        }
        while(m--){
            int temp = q.top()+x;
            q.pop();
            q.push(temp);
        }
        cout << q.top() << endl;
    }
    system("pause");
    return 0;
}