/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-12 23:13:22
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-12 23:13:23
 */
/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 *
 * [1342] 将数字变成 0 的操作次数
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps (int num) {
        int result = 0;
        while(num!=0){
            if (num%2==0)   //为偶数
                {num /= 2;result++;}
            else
                {num -= 1;result++;}
        }
        return result;
    }
};
// @lc code=end

