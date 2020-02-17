/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-14 23:50:19
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-15 12:58:51
 */
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
         if (n == 0) return 1;
         long c = 1;
         for (int i = 1; i <= n; i++)
         {
             c = c*(4*i-2)/(i+1);
         }
         return c;
    }
    
};
// @lc code=end

