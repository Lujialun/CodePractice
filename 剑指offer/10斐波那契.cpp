/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-05 16:07:27
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-05 16:07:35
 */
class Solution {
public:
    int fib(int n) {
        int f0=0,f1=1,f2;
        for(int i=0; i<n; i++){
            f2=(f0+f1)%1000000007;
            f0=f1;
            f1=f2;
        }
        return f0;
    }
};