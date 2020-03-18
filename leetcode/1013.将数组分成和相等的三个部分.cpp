/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-13 22:55:27
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-14 00:04:48
 */
/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum%3!=0||A.size()<=3) return false;
        sum /= 3;
        auto it_front = A.begin();
        auto it_back = --A.end();
        int front,back;
        front = *it_front; back = *it_back;
        if (front != sum) it_front++;
        if (back != sum) it_back--;
        while (it_front<it_back)
        {
            if (front != sum) front+=(*it_front++);
            if (back != sum) back+=(*it_back--);
            if (front == sum && back == sum && it_front<=it_back) return true;
        }
        return false;
    }
};
// @lc code=end

