/*
 * @Descripttion: https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-23 16:17:56
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-23 16:21:28
 */
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        // 找到公共前缀
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};



class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // 抹去最右边的 1
            n = n & (n - 1);
        }
        return n;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/shu-zi-fan-wei-an-wei-yu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。