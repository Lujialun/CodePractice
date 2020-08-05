/*
 * @Descripttion:  https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/
 * @version:  
 * @Author: Lucas
 * @Date: 2020-08-05 17:56:50
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-05 18:47:43
 */
class Solution {
public:
    vector<double> twoSum(int n) {
        double low=pow(6,n);
        vector<vector<int> > f(n+1,vector<int>(6*n+1));
        for(int i=1;i<=6; i++){
            f[1][i]=1;
        }
        for(int i=2; i<=n; i++){
            for(int j=2; j<=6*i; j++){
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur <= 0) {
                        break;
                    }
                    f[i][j] += f[i-1][j-cur];
                }
            }
        }
        vector<double> res;
        for(int i=n; i<=6*n; i++){
            res.push_back(f[n][i]/low);
        }
        return res;
    }
};


class Solution {
public:
    vector<double> twoSum(int n) {
        int dp[70];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 6; i ++) {
            dp[i] = 1;
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = 6*i; j >= i; j --) {
                dp[j] = 0;
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur < i-1) {
                        break;
                    }
                    dp[j] += dp[j-cur];
                }
            }
        }
        int all = pow(6, n);
        vector<double> ret;
        for (int i = n; i <= 6 * n; i ++) {
            ret.push_back(dp[i] * 1.0 / all);
        }
        return ret;
    }
};

作者：huwt
链接：https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。