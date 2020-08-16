/*
 * @Descripttion: test
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-12 16:49:38
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-16 10:44:34
 */

#include<bits\stdc++.h>
using namespace std;

bool isPalindrome(int x){
    bool f=false;
    if(x<0){
        return false;
    }else{
        int y=x;
        int res = 0;
        while(x!=0){
            int temp=x%10;
            x /= 10;
            res = res * 10 + temp;
        }
        f = res == y;
    }
    return f;
}

bool f[26];
void stringFilt(const char *input, int inputlen, char *output){
    int i = 0;
    if(input==NULL||inputlen<=1){
        return;
    }
    const char *p=input;
    while(*p!='\0'){
        if(f[*p-'a']){
            p++;
        }else{
            output[i++] = *p;
            f[*p - 'a'] = 1;
        }
    }
    output[i] = '\0';
}

long long numbers(int a, int b, int c, int d, int p) {
        // write code here
        int  m=0,n=0;
        bool r=false,t=false;
        long long ans;
        for(int i=a; i<=b; i++){
            if(i%p==0)
            {
                m = i / p;
                r=true;
                break;
            }
            
        }

        for(int i=b; i>=a; i--){
            if(i%p==0)
            {
                n = i / p;
                r=true;
                break;
            }
            
        }
        long long q=1, w=1;
        if(n!=m)
        q = n - m + 1;
        m = 0, n = 0;
        for(int i=c; i<=d; i++){
            if(i%p==0)
            {
                m = i / p;
                t=true;
                break;
            }
            
        }

        for(int i=d; i>=c; i--){
            if(i%p==0)
            {
                n = i / p;
                t=true;
                break;
            }
            
        }
        cout << r << t << endl;
        if(!r&&!t) return 0;
     //   if(!r||!t) return 1;
        if(n!=m)
        w = n - m + 1;
        
        return (long long)q * ((d - c) + 1) + (long long)w * ((b - a) + 1 - q);
    }
// long long numbers(int a, int b, int c, int d, int p) {
//         // write code here
//         long long left = (b / p) - (a - 1) / p;
//         long long right = (d / p) - (c - 1) / p;
//         return (b - a + 1) * right + (d - c + 1) * left - left * right;
//     }

int main(){

    // cout << isPalindrome(101) << endl;
    // cout << isPalindrome(1011) << endl;
    // cout << isPalindrome(-101) << endl;
    cout << numbers(1, 1, 1, 1, 3) << endl;
    system("pause");
}
