/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-22 21:13:08
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-22 21:21:45
 */
/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.empty() || A.size() == 1) return 0;
        
        sort(A.begin(), A.end());
        int temp = A[0];
        int ans = 0;
        auto it = (A.begin()+1);
        for (; it != A.end(); it++){
            if (*it > temp) {
                temp = *it;
                continue;
            }
            else {
                // auto itr_swap = find(it, A.end(), (temp+1));
                // if (itr_swap != A.end()){
                //     swap(it, itr_swap);
                //     temp = *it;
                //     continue;
                // }
                //没有找到增1元素，需要将本元素自增至此值
                ans += (temp+1 - *it);
                temp++;
            }
        }
        return ans;
    }
};
// @lc code=end

