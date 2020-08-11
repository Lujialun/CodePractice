/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-10 18:59:09
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-10 20:15:35
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
struct pl
{
    int l;
    int price;
}box[2001];

int main()
{
    int N, T, k, m;
    while(cin>>N>>T){ 
        m=0;
        vector<int> v(N);
        vector<int> l(N);
        vector<int> c(N);
        for(int i=0; i<N; i++){ 
            cin>>v[i]>>l[i]>>c[i];
        }
        for(int i=0; i<N; i++){ 
            k=1;
            while(c[i]-k>0){ 
                c[i] -= k;
                box[++m].price=k*v[i];
                box[m].l=k*l[i];
                k*=2;
            }
            box[++m].price=v[i]*c[i];
            box[m].l=l[i]*c[i];
        }
        vector<int> f(T+1);
        for(int i=1; i<=m; i++){ 
            for(int j=T; j>=box[i].price; j--){ 
                f[j]=max(f[j], f[j-box[i].price]+box[i].l);
            }
        }
        cout<<f[T]<<endl;
    }
  //  system("pause");
    return 0;
}
