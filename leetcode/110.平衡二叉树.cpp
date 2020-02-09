/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-08 17:10:45
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-08 17:10:46
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode *root)
    {
        return process(root) != -1;
    }
    // -1为不平衡
    int process(TreeNode *root)
    {
        if (!root)
            return 0; //根节点定义返回值为0
        if (!root->left && !root->right)
            return 1; //叶结点定义返回值为1;

        int left_subtree_height = process(root->left);
        if (left_subtree_height == -1)
            return -1;
        int right_subtree_height = process(root->right);
        if (right_subtree_height == -1)
            return -1;

        if (abs(left_subtree_height - right_subtree_height) > 1)
            return -1;

        return max(left_subtree_height, right_subtree_height) + 1;
    }
};
// @lc code=end

