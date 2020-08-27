#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        vector<int> tree(n);
        for (int i = 0; i < n; i++){
            cin >> tree[i];
        }
        vector<vector<int>> a;
       
        a.push_back({tree[0]});
        int cnt = 2;
        for (int i = 1; i < n; i++){
            vector<int> tmp;
            int c = 0;
            while(c<cnt&&i<n){
                tmp.push_back(tree[i]);
                c++;
                i++;
            }
            i--;
            cnt *= 2;
            a.push_back(tmp);
        }
        // for (int i = 0; i < a.size(); i++){
        //     for (int j = 0; j < a[i].size(); j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
            vector<int> res;
        for (int i = 0; i < a.size(); i++){
            res.push_back(a[i][0]);
         //   cout << a[i][0] << endl;
        }
        int k = a.size();
        for (int i = 1; i < a[k-1].size(); i++){
            res.push_back(a[k-1][i]);
        //     cout << a[k-1][i] << endl;
        }
        for (int i = a[k-1].size(); i < a[k-2].size()-1; i++){
            res.push_back(a[k-2][i]);
        }
    //    cout << k - 2 << endl;
        for (int i = k - 2; i > 0; i--){
            res.push_back(a[i][a[i].size() - 1]);
        }

        for (int i = 0; i < res.size()-1; i++){
            cout << res[i]<<" ";
        }
        cout <<res[res.size()-1]<<endl;
    }
 //   system("pause");
    return 0;
}