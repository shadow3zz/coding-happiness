/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-23 15:05:44
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-23 15:26:58
 */
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(const vector<int>& inorder, const vector<int>& postorder) {
        if (postorder.size() > 0){
            TreeNode *root = new TreeNode(0);
            root->val = postorder[postorder.size()-1];
            auto mid = find(inorder.begin(), inorder.end(), root->val);
            int left2mid = distance(inorder.begin(), mid);
            root->left = buildTree(vector<int>(inorder.begin(), mid),vector<int>(postorder.begin(), postorder.begin()+left2mid));
            root->right = buildTree(vector<int>(mid+1, inorder.end()),vector<int>(postorder.begin()+left2mid, postorder.end()-1));
            return root;
        }
        return NULL;
    }
};
// @lc code=end

