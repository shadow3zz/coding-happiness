/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-11 00:03:23
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-11 12:22:03
 */
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        list<int> elements;
        if (!root)
            return true;
        inorderTraversal(root, elements);
        int element;
        while (!elements.empty())
        {
            element = elements.front();
            elements.pop_front();
            if (elements.empty())
                return true;
            else if (element < elements.front())
                continue;
            else
                return false;
        }
        return true;
    }

    void inorderTraversal(TreeNode *root, list<int> &l)
    {
        if (root == nullptr)
            return;
        else
        {
            inorderTraversal(root->left, l);
            l.push_back(root->val);
            inorderTraversal(root->right, l);
        }
    }
};
// @lc code=end
