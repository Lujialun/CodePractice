/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-10 18:57:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-10 19:41:06
 */
#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int main()
{
    int N, A, X;
    while(cin>>N>>A>>X){ 
        vector<int> bug(N);
        for(int i=0; i<N; i++){ 
            cin>>bug[i];
        }
        int sum=0;
        for(auto i:bug){ 
            sum+=i;
        }
        if((X*60*A+(8-X)*60)>=sum){ 
            if(sum<=X*60*A){
                if(sum/A*A<sum){ 
                    cout<<sum/A+1<<endl;
                }else{ 
                    cout<<sum/A<<endl;
                }
            }else{ 
                sum=sum-X*60*A+X*60;
                cout<<sum<<endl;
            }
        }else{ 
            cout<<0<<endl;
        }
    }
    //system("pause");
    return 0;
}
