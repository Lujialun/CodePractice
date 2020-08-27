#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,dis[20][20];
int t;
int dp[20][100000];
/*
s表示已经经过的城市的集合，v表示现在正处在的城市。
定义dp[s][v]为从v出发访问所有剩余的城市，再返回起点所需要的最短的路径。
mp[i][j] 表示 i 到 j 的最短路。 
*/
void floyd(){//球最短路
    for(register int k=0;k<n;++k)
        for(register int i=0;i<n;++i)
            for(register int j=0;j<n;++j)
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
}
int main(){
    // cin>>t;
    // for(register int k=1;k<=t;++k){
    //     cin>>n>>m;
    //     memset(dis,0x3f,sizeof(dis));
    //     memset(dp,0x3f,sizeof(dp));
    //     for(register int i = 1;i<=m;i++) {
    //         int a,b,c;
    //         scanf("%d %d %d",&a,&b,&c); a--;b--;
    //         dis[a][b]=min(dis[a][b],c);
    //         dis[b][a]=dis[a][b];
    //     }
    cin>>
        /*
        dp初始值为无穷大，一开始自己总是想不通为什么是(1<<n)-1，
        后面突然想到，在状压中， 我们把二进制中的0位也用来表示一个城市，
        故所有城市都在集合中要表示为(1<<n)-1 
        */
        for(int i=0;i<n;i++) dis[i][i]=0;
        floyd();
        dp[0][(1<<n)-1]=0;
        for(register int s=(1<<n)-2;s>=0;--s) 
            for(register int i=0;i<n;++i)
                for(register int j=0;j<n;++j)
                    if(!(s>>j & 1)) {//如果当前城市j还没有经过,我们从i走向j
                        dp[i][s]=min(dp[i][s],dp[j][s|(1<<j)]+dis[i][j]);
                        /*这个dp方程表示现在要从i走向j,而dp[j][s|(1<<j)]表示到城市j,所剩下的还未走的城市
                        dp[i][s]是到城市i所剩下的还未走的城市到原点的距离,然后加上i->j这条边的权值
                        注意这里是从终点往起点推
                        */
                    }
        cout<<dp[0][0]<<endl;
    }
}