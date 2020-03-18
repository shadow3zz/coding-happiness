/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-18 19:59:38
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-18 19:59:38
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int max = 1;
        
        int a[128];int b[128];int c[128];
        for (int i = 0 ;i<128;i++)
        {
            a[i] = 0;
        }
        memcpy(b,a,sizeof(a));
        memcpy(c,a,sizeof(a));
        int sub_len = 0;
        for (int i = 0; i<s.size(); i++){
            a[s[i]]+=1;
            if(a[s[i]] == 2)
            {
                max = max>sub_len?max:sub_len;
                sub_len = 0;
                memcpy(a,b,sizeof(b));
                i = c[s[i]];
                memcpy(c,b,sizeof(b));
            }   
            else
            {
                sub_len++;
                c[s[i]] = i;
            }
                
        }
        return max>sub_len?max:sub_len;
    }
};
// @lc code=end

