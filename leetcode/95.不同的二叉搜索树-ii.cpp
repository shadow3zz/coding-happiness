/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-14 20:59:01
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-14 23:42:49
 */
/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> generateTrees(int n)
    {
        if(n==0) return vector<TreeNode*>(0);
        return generateTrees(1, n);
    }
    vector<TreeNode *> generateTrees(int start, int end)
    {
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(nullptr);
            return result;
        }
        for(int i = start; i<=end; i++)
        {
            vector<TreeNode*> lefts = generateTrees(start, i-1);
            vector<TreeNode*> rights = generateTrees(i+1, end);
            for (int j = 0; j < lefts.size(); j++)
            {
                for (int k = 0; k < rights.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    result.push_back(root);
                }
                
            }
        }
        return result;
    }
};
// @lc code=end
