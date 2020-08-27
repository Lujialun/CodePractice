/*
 * @Descripttion: 540. 有序数组中的单一元素 https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-25 14:44:33
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-25 14:58:35
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res=0;
        for(auto i:nums){
            res ^=i;
        }
        return res;
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool halvesAreEven = (hi - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid]) {
                if (halvesAreEven) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if (halvesAreEven) {
                    hi = mid - 2;
                } else {
                    lo = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }
};

作者：LeetCode
链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array/solution/you-xu-shu-zu-zhong-de-dan-yi-yuan-su-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。