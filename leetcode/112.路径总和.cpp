/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-15 13:08:29
 * @LastEditors: shadow3zz
 * @LastEditTime : 2020-02-15 13:50:17
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return checkPathSum(root, sum, 0);
    }
    bool checkPathSum(TreeNode* root, int sum, int result){
        if (!root) return false;
        if (!root->left && !root->right){
            result += root->val;
            if (sum == result) return true;
            else return false;
        } 
        else{
            result += root->val;
            return checkPathSum(root->left, sum, result)||checkPathSum(root->right, sum, result);
        }
    
    }
};
// @lc code=end

