/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-10 18:59:37
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-11 00:51:03
 * 
 * 
 * 4
we
ssdf
sderf
sd
3
dfc
sss
sder
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
int N, M;
bool dfs(vector<string> &a, int i,int j, string &w, int k){
    if (k==w.size()) return true;
    if (i<0||i>=N||j<0||j>=a[i].size()||a[i][j]==0||a[i][j]!=w[k]) {
        return false;
    } 
    char t=a[i][j];
     cout <<i<<" "<<j<<" "<<a[i][j] << " " << w[k] << endl;
    a[i][j]=0;
   
    bool f=dfs(a, i+1, j, w, k+1)||dfs(a, i-1, j, w, k+1)||dfs(a, i, j+1, w, k+1)||dfs(a, i, j-1, w, k+1);
    cout <<f<< w[k] << endl;
   if (f) return true;
    a[i][j]=t;
}
int main()
{
   
    while(cin>>N){ 
        vector<string> alpha(N);
        vector<string> temp(N);
        for(int i=0; i<N; i++){ 
            cin>>alpha[i];
        }
        temp=alpha;
        cin>>M;
        vector<string> word(M);
        for(int i=0; i<M; i++){ 
            cin>>word[i];
        }
      //  vector<string> res;
        bool a=0;
        for(int i=0; i<M; i++){ 
            for(int j=0; j<N; j++){ 
                for(int k=0; k<alpha[j].size(); k++){ 
                  
                    if(alpha[j][k]==word[i][0]&&dfs(alpha,j,k,word[i],0)){ 
                      //  res.push_back(word[i]);
                        cout<<word[i]<<endl;
                        a=1;
                        break;
                    }
                    alpha=temp;
                    if (a) break;
                }
               
                if (a) break;
                
            }
            a=0;
           
        }
    }
    system("pause");
    return 0;
}
