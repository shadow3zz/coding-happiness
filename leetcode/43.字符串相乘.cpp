/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-12 23:02:37
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-12 23:02:38
 */
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_length = num1.size();
        int num2_length = num2.size();
        if (num1 =="0"||num2=="0") return "0";
        vector<int> result(num1_length+num2_length, 0);
        
        int mult_of_two_number;
        for(int i=num2_length-1; i>=0;--i){ //取第二个数字的每一位
           int temp1 = num2[i]-'0';
            for(int j=num1_length-1;j>=0;--j){
                int temp2 = num1[j]-'0';
                mult_of_two_number = temp1*temp2;
                mult_of_two_number += result[i+j+1];
                result[i+j] += mult_of_two_number/10;
                result[i+j+1] = mult_of_two_number%10;
            }
        }
        auto it = result.begin();
        while(*it == 0)
        {
            it++;
        }
        string new_result;
        for (;it!=result.end();++it)
            new_result += *it+'0';
        return new_result;
    }
};
// @lc code=end

