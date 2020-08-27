/*
 * @Descripttion:  https://leetcode-cn.com/problems/number-of-segments-in-a-string/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-27 15:49:21
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-27 15:52:17
 */
class Solution {
public:
    int countSegments(string s) {
        if(s.empty()) return 0;
        int i=0,j=0,res=0;
        while(j<s.size()){
            if(i==j&&s[i]==' '){
                i++;
                j++;
            } else if(s[j]!=' ') j++;
            else{
                res++;
                j++;
                i=j;
            }
        }
        return i<j?++res:res;
    }
};

class Solution {
    public int countSegments(String s) {
        int segmentCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s.charAt(i-1) == ' ') && s.charAt(i) != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/number-of-segments-in-a-string/solution/zi-fu-chuan-zhong-de-dan-ci-shu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。