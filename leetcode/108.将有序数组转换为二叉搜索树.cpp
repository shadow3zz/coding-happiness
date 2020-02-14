/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-12 13:07:27
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-14 11:43:52
 */
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        if(end<=start) return NULL; 
        int mixIndex = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mixIndex]);
        root->left = sortedArrayToBST(nums, start, mixIndex);
        root->right = sortedArrayToBST(nums, mixIndex+1, end);
        return root;
    }
};
// @lc code=end

