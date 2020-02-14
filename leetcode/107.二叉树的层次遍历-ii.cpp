/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
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
                if (current.front()->left)
                    next.push(current.front()->left);
                if (current.front()->right)
                    next.push(current.front()->right);
                current.pop();
            }
            result.push_back(level);
            swap(next, current);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

