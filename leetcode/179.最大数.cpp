/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-16 12:09:20
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-16 13:12:21
 */
/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "";
        
        vector<string> result;
        int length;
        for (auto s:nums){
            result.push_back(to_string(s));
        }
        sort(result.begin(), result.end(), [](string& x, string& y) {
            return x + y > y + x;
        });
        // for (int i = 0; i < result.size()-1; ++i){
        //     for (int j = 0; j < result.size()-1; ++j){
        //         if (largestNumberHelper(result[j], result[j+1])){
        //             swap(result[j], result[j+1]);
        //         }
        //     }
        // }
        string res;
        if (result[0] == "0") return "0";
        for (auto s:result){
            res+=s;
        }
        return res;
    }
    //s1<s2返回true
    bool largestNumberHelper(string s1, string s2){
        return (s1+s2)<(s2+s1)?true:false;
    }
    
};
// @lc code=end

