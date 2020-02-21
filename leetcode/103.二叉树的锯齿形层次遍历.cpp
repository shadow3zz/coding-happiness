/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-18 10:29:31
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-18 10:40:17
 */
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bool flag=false;
        queue<TreeNode *> current, next;
        if (!root)
            return result;
        current.push(root);
        while (!current.empty())
        {
            vector<int> level;
            while (!current.empty())
            {
                level.push_back(current.front()->val);
                if(current.front()->left) next.push(current.front()->left);
                if(current.front()->right) next.push(current.front()->right);
                current.pop();
            }
            if (flag)
                reverse(level.begin(), level.end());
            flag = !flag;
            result.push_back(level);
            swap(next, current);
        }
        return result;
    }
};
// @lc code=end

