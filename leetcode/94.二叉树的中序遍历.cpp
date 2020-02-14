/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-11 12:02:42
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-11 12:27:11
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;
        else
        {
            inorderTraversalProcess(root, result);
        }
        return result;
    }
    void inorderTraversalProcess(TreeNode *t, vector<int> &v)
    {
        if (t == nullptr)
            return ;
        inorderTraversalProcess(t->left, v);
        v.push_back(t->val);
        inorderTraversalProcess(t->right, v);
    }
};
// @lc code=end
