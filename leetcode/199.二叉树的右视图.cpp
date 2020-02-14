/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-11 14:06:56
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-14 11:23:47
 */
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> current, next;
        vector<int> result;
        if (!root) return result;
        current.push(root);
        while(!current.empty()) {
            vector<int> level;
            while(!current.empty()){
                TreeNode *tn=current.front();
                current.pop();
                if (tn->left) next.push(tn->left);
                if (tn->right) next.push(tn->right);
                level.push_back(tn->val);
                
            }
            result.push_back(level.back());
            swap(current,next);
            // level.clear();
        }
        return result;
    }
};
// @lc code=end

