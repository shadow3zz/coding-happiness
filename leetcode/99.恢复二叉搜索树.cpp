/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-15 16:45:37
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-18 10:49:12
 */
/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        //中序遍历
        vector<int> in_1;
        recoverTreeHelper(root, in_1);
        sort(in_1.begin(), in_1.end());
        recoverTreeHelper_(root, in_1);
    }
    void recoverTreeHelper(TreeNode *root, vector<int> &in)
    {
        if (!root)
            return;
        recoverTreeHelper(root->left, in);
        in.push_back(root->val);
        recoverTreeHelper(root->right, in);
    }
    void recoverTreeHelper_(TreeNode *root, vector<int> &in)
    {
        if (!root)
            return;
        recoverTreeHelper_(root->left, in);
        if (in[0] != root->val){
            root->val = in.front();
        }
        in.erase(in.begin());
        recoverTreeHelper_(root->right, in);
    }
};
// @lc code=end
