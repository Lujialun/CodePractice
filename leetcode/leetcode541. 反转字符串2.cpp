/*
 * @Descripttion: https://leetcode-cn.com/problems/reverse-string-ii/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-30 11:51:50
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-30 11:54:48
 */
class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0;
        while(i<s.size()){
            int left=i,c=0;
            while(i<s.size()&&c<k){
                c++;
                i++;
            }
            int right=i-1;
            while(left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            i+=k;
        }
        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) { 
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            } 
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + s.size());                     
        }
        return s;
    }
};

作者：carlsun-2
链接：https://leetcode-cn.com/problems/reverse-string-ii/solution/cjian-ji-dai-ma-xiang-xi-zhu-shi-bu-kan-hou-hui-xi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。