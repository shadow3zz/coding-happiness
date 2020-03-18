/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-18 12:16:18
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-18 12:16:18
 */
/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string s) {
        if( s == "") return 0;
        int i,j;
        for (i = 0,j = s.size()-1; i<=j; i++,j--)
        {
            if (s[i]!=s[j])
                return 2;
        }
        return 1;
    }
};
// @lc code=end

