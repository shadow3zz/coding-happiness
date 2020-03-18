/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-17 10:45:34
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-17 10:45:46
 */
/*
 * @lc app=leetcode.cn id=1160 lang=cpp
 *
 * [1160] 拼写单词
 */

// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> t;
        for (int i =0; i<26; ++i){
            t[i+'a'] = 0;
        }
        map<char, int> cmp(t);
        for (int j = 0; j<chars.size(); j++){
                t[chars[j]]+=1;
        } 
        vector<int> number;
        for (int i = 0; i<words.size(); ++i){
            map<char, int> temp = cmp;
            for (int j = 0; j<words[i].size(); ++j){
                temp[words[i][j]]+=1;
                if(t[words[i][j]] < temp[words[i][j]])
                    break; 
                if(t[words[i][j]] >= temp[words[i][j]]&&j==words[i].size()-1)
                    number.push_back(i);
            }
        }
        int length = 0;
        for (auto n:number){
            length += words[n].size();
        }
        return length;
    }
};
// @lc code=end

