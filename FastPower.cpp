#include <bits/stdc++.h>
using namespace std;

    double getpower(double x, long long n)//注意写成long long 
    {
        double ans=1;
        while(n>0){
            if(n%2==1)
                ans *= x;
            x *= x;
            n=n >> 1;
        }
        cout << ans << endl;
        return ans;
    }

double myPow(double x, int n) {
    long long N = n;
    return N>=0?getpower(x,N):1.0/getpower(x,-N);
    }



int main()
{
    int a = -2;
    unsigned int b = (unsigned int)a;
    cout << b << endl;
    system("pause");
}