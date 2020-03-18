/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-18 12:30:28
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-18 12:30:29
 */
/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {

    }
    
    void insert(string key, int val) {
        t[key] = val;
    }
    
    int sum(string prefix) {
        int length = prefix.size();
        string cmp;
        int Sum=0;
        for (auto s:t)
        {
            cmp = s.first;
            if(length <= cmp.size() 
            && cmp.substr(0,length) == prefix){
                Sum += s.second;
            }
        }
        return Sum;
    }
private:
    map<string, int> t;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

