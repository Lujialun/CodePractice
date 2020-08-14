/*
 * @Descripttion: 43. 字符串相乘 https://leetcode-cn.com/problems/multiply-strings/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-13 15:02:00
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-13 15:28:39
 */
#include<bits\stdc++.h>
using namespace std;
string add2String(string num1, string num2){
        string res;
        int f=0,temp;
        int i=num1.size()-1;
        int j=num2.size()-1;
        while(i>=0&&j>=0){
            temp=(num1[i]-'0')+(num2[j]-'0')+f;
            f=temp/10;
            res.push_back(temp%10+'0');
            i--;
            j--;
        }
        while(i>=0){
            temp=(num1[i]-'0')+f;
            f=temp/10;
            res.push_back(temp%10+'0');
            i--;
        }
        while(j>=0){
            temp=(num2[j]-'0')+f;
            f=temp/10;
            res.push_back(temp%10+'0');
            j--;
        }
        if(f>0) res.push_back(f+'0');
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) {
         string res="0";
        int f,temp;
        int i=num1.size()-1;
        if(num1[0]=='0'||num2[0]=='0') return "0";
        while(i>=0){
            f=0;
            int j=num2.size()-1;
            string sum;
            while(j>=0){
                temp=(num1[i]-'0')*(num2[j]-'0')+f;
                f=temp/10;
                sum.push_back(temp%10+'0');
                j--;
            }
            if(f>0) sum.push_back(f+'0');
            reverse(sum.begin(),sum.end());
            int cnt=num1.size()-1-i;
            while(cnt--) sum.push_back('0');
            res=add2String(res,sum);
            i--;
        //    cout<<i<<"here"<<endl;
        }
        return res;
    }

int main(){
    //cout<<multiply("20","20")<<endl;
    cout<<multiply("2","3")<<endl;
    //cout<<multiply("111","222")<<endl;
    system("pause");
}