/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-23 10:00:42
 */ 
#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static int lowbit(int x) {
        return x & (-x);
    }

    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
};

vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        // 离散化
        sort(tmp.begin(), tmp.end());
        for (int& num: nums) {
           
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
            
        }
        // 树状数组统计逆序对
        BIT bit(n);
        vector<int> res(n);
        for (int i = n - 1; i >= 0; --i) {
            res[i]=bit.query(nums[i] - 1);
        //    cout << nums[i] << " " << ans << endl;
            bit.update(nums[i]);
        }
        return res;
    }


int main()
{
    vector<int> a = {5, 5, 2, 10, 3};
    char *p = nullptr;
    if(p==nullptr)
        cout << "ss" << endl;
    system("pause");
}