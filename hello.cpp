#include<iostream>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt=0,m=0;
        int carry=1;
        int tmp=0;
        while(n>0){
            
           
            n=n/10;
            if(tmp>1){
                cnt +=(n+1)*carry;
                 cout << "tmp>1 " << cnt << endl;
            }else if(tmp==1){
                cnt +=1+m%10;
                cout << "tmp=1 " << cnt << endl;
            }else{
                cnt +=(n)*carry;
                cout << "tmp==0 " << cnt << endl;
            }
           
            tmp=n%10;
            m += tmp*carry;
            //cout << "cnt2 " << cnt << endl;
            carry = carry * 10;
        }
        return cnt;
    }
 int main()
 {
     cout << NumberOf1Between1AndN_Solution(101) << endl;
     system("pause");
 }