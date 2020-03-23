/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-23 14:22:19
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-23 14:41:05
 */
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // 将原来函数参数改为常量const否则vector<int>(itr,itr2) c++中临时变量不能作为非const的引用参数
    // }
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if (preorder.size() > 0){
            TreeNode *root = new TreeNode(0);
            root->val = preorder[0];
            //中序遍历中找到根结点迭代器
            auto mid = find(inorder.begin(), inorder.end(), root->val);
            int left2mid = distance(inorder.begin(), mid);
            // 左子树()
            root->left = buildTree(vector<int>(preorder.begin()+1, preorder.begin()+1+left2mid), vector<int>(inorder.begin(), mid));
            // 右子树
            root->right = buildTree(vector<int>(preorder.begin()+1+left2mid, preorder.end()), vector<int>(mid+1, inorder.end()));
            return root;
        }
        return NULL;
    }
};
// @lc code=end

