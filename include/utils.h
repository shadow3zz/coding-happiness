/*
 * @Descripttion: leetcode代码调试用
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-31 21:49:23
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-21 23:59:58
 */

#pragma once
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>

#define INT_MAX 2147483648
#define INT_MIN -2147483648

using namespace std;
class Solution
{
private:
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    /**
     * @name: 2.两数相加
     * @msg: 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
     * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
     * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
     */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *start = new ListNode(0);
        ListNode *result = start;
        ListNode *pNode_1 = l1;
        ListNode *pNode_2 = l2;
        int flag = 0;
        while (pNode_1 || pNode_2)
        {
            int temp = (pNode_1 ? pNode_1->val : 0) + (pNode_2 ? pNode_2->val : 0) + flag;
            result = result->next = new ListNode(temp%10);
            flag = temp/10;
            if (pNode_1)
                pNode_1 = pNode_1->next;
            if (pNode_2)
                pNode_2 = pNode_2->next;                
        }
        if (flag == 1)
        {
            result->next = new ListNode(1);
        }
        return start->next;
    }

    /**
     * @name: 8. 字符串转换整数 (atoi)
     * @msg: 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
     * 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
     * 当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，
     * 作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
     * 该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
     * 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
     * 在任何情况下，若函数不能进行有效的转换时，请返回 0。
     * @param {type} 
     * @return: 
     */
    int myAtoi(string str)
    {
        int number = 0;
        int strlength = str.length();
        list<int> numbers;

        int flag = 0;
        char num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int i = 0;
        while (i < strlength)
        {
            if (str[i] == ' ')
            {
                if (!numbers.empty() || flag != 0)
                    break;
                i++;
                continue;
            }

            else if (str[i] == '+')
            {
                if (!numbers.empty())
                    break;
                if (flag != 0)
                    return 0;
                flag = 1;
                i++;
                continue;
            }
            else if (str[i] == '-')
            {
                if (!numbers.empty())
                    break;
                if (flag != 0)
                    return 0;
                flag = -1;
                i++;
                continue;
            }
            else if (isdigit(str[i]))
            {
                numbers.push_back(str[i] - '0');
                i++;
                continue;
            }
            else
            {
                if (numbers.empty())
                    return 0;
                else
                    break;
            }
            /*code*/
        }
        while (!numbers.empty())
        {

            if (number > INT_MAX / 10 || (number == INT_MAX / 10 && numbers.back() > 7))
            {
                return flag == -1 ? INT_MIN : INT_MAX;
            }

            number = number * 10 + numbers.front();
            numbers.pop_front();
        }
        return flag == -1 ? -number : number;
    }

    /**
     * @name: 9. 回文数
     * @msg: 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
     * @param {type} 进阶:
            你能不将整数转为字符串来解决这个问题吗？
     * @return: 
     */
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        if (x % 10 == 0)
            return false;
        vector<int> num;
        while (x > 0)
        {
            num.push_back(x % 10);
            x /= 10;
        }
        auto itr_1 = num.begin();
        auto itr_2 = num.end();
        itr_2--;
        while (*itr_1 == *itr_2)
        {
            ++itr_1;
            if (itr_1 == itr_2 && *itr_1 == *itr_2)
                return true;
            --itr_2;
            if (itr_1 == itr_2)
                return true;
        }
        return false;
    }

    /**
     * @name: 20. 有效的括号
     * @msg: 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
     * 有效字符串需满足：
     * 左括号必须用相同类型的右括号闭合。
     * 左括号必须以正确的顺序闭合。
     * 注意空字符串可被认为是有效字符串。
     * @param {type} 
     * @return: 
     */
    bool isValid(string s)
    {
        if (s.empty())
            return true;
        stack<char> kuohao;
        for (auto letter : s)
        {
            if (letter == '{' || letter == '(' || letter == '[')
            {
                kuohao.push(letter);
            }
            else if (letter == '}' || letter == ')' || letter == ']')
            {
                if (kuohao.empty())
                    return false;
                if ((kuohao.top() == '{' && letter == '}') || (kuohao.top() == '(' && letter == ')') || (kuohao.top() == '[' && letter == ']'))
                    kuohao.pop();
                else
                    return false;
            }
        }
        if (!kuohao.empty())
            return false;
        return true;
    }

    /**
     * @name: 21. 合并两个有序链表(迭代法)
     * @msg: 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
     * 输入：1->2->4, 1->3->4
     * 输出：1->1->2->3->4->4
     */

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *result = new ListNode(0);
        ListNode *temp = result;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1 == NULL)
            temp->next = l2;
        if (l2 == NULL)
            temp->next = l1;
        return result->next;
    }

    /**
     * @name: 22. 括号生成
     * @msg: 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
     * @param {type} 例如，给出 n = 3，生成结果为:
                        [
                        "((()))",
                        "(()())",
                        "(())()",
                        "()(())",
                        "()()()"
                        ]
     */
    vector<string> generateParenthesis(int n)
    {
    }
    /**
     * @name: 28.实现 strStr()
     * @msg: 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
     * @tips: 当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
     * @输入: haystack = "hello", needle = "ll"
     * @输出: 2
     * 比str1.find(str2)好
    */
    int strStr(std::string haystack, std::string needle)
    {
        haystack.find(needle);
        if (!needle.empty())
        {
            int N = haystack.size() - needle.size() + 1;
            for (int i = 0; i < N; i++)
            {
                int k = 0;
                int j = i;
                while (haystack[j++] == needle[k++])
                    if (k == needle.length())
                        return i;
            }
            return -1;
        }
        else
        {
            return 0;
        }
    }

    /**
     * @name: 38. 外观数列
     * @msg: 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
     * 前五项如下：
     * 1.     1
     * 2.     11
     * 3.     21
     * 4.     1211
     * 5.     111221
     */
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        else
        {
            string temp = countAndSay(n - 1);
            int count = 1;
            if (temp == "1")
                return to_string(count) + "1";
            else
            {
                string str;
                for (int i = 0; i < temp.length() - 1; i++)
                {

                    if (temp[i] == temp[i + 1])
                    {
                        count++;
                        if (i == temp.length() - 2)
                        {
                            return str + to_string(count) + temp[i];
                        }
                        continue;
                    }
                    else if (count == 1 && temp[i] != temp[i + 1])
                    {
                        str += to_string(count) + temp[i];
                        if (i == temp.length() - 2)
                        {
                            return str + to_string(count) + temp[i + 1];
                        }
                        continue;
                    }
                    else
                    {
                        str += to_string(count) + temp[i];
                        count = 1;
                        if (i == temp.length() - 2)
                        {
                            return str + to_string(count) + temp[i + 1];
                        }
                        continue;
                    }
                }
                return str;
            }
        }
    }
    // Tree
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    /**
     * @name: 94.二叉树的中序遍历
     * @msg: 给定一个二叉树，返回它的中序 遍历。
     */
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
            return;
        inorderTraversalProcess(t->left, v);
        v.push_back(t->val);
        inorderTraversalProcess(t->right, v);
    }
    /**
     * @name: 95.不同的二叉搜索树 II
     * @msg: 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
     * @param {type} 
     * @return: 
     */
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>(0);
        return generateTrees(1, n);
    }
    vector<TreeNode *> generateTrees(int start, int end)
    {
        vector<TreeNode *> result;
        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> lefts = generateTrees(start, i - 1);
            vector<TreeNode *> rights = generateTrees(i + 1, end);
            for (int j = 0; j < lefts.size(); j++)
            {
                for (int k = 0; k < rights.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    /**
     * @name: 96.不同的二叉搜索树
     * @msg: 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
     * h(n)=h(n-1)*(4*n-2)/(n+1);
     */
    int numTrees(int n)
    {
        if (n == 0)
            return 1;
        long c = 1;
        for (int i = 1; i <= n; i++)
        {
            c = c * (4 * i - 2) / (i + 1);
        }
        return c;
    }
    /**
     * @name: 98.验证二叉搜索树
     * @msg: 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
     */
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
    // 中序遍历 重载
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
    /**
     * @name: 99.恢复二叉搜索树
     * @msg: 二叉搜索树中的两个节点被错误地交换。
     * 请在不改变其结构的情况下，恢复这棵树。
     */
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
        if (in[0] != root->val)
        {
            root->val = in.front();
        }
        in.erase(in.begin());
        recoverTreeHelper_(root->right, in);
    }
    // 中序遍历 重载
    void inorderTraversal(TreeNode *root, list<TreeNode *> &l)
    {
        if (root == nullptr)
            return;
        else
        {
            inorderTraversal(root->left, l);

            if (root->val < l.back()->val)
            {
                int temp = l.back()->val;
                l.back()->val = root->val;
                root->val = temp;
            }
            l.push_back(root);
            inorderTraversal(root->right, l);
        }
    }
    /**
     * @name: 101.对称二叉树
     * @msg:  给定一个二叉树，检查它是否是镜像对称的。
     * @param {type} 首先分析下这个对称二叉树，也就是一个二叉树中间对称。所以我们可以使用递归的思想，首先以根节点以及其左右子树，左子树的左子树和右子树的右子树相同，左子树的右子树和右子树的左子树相同。
     * @return: 
     */
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return checkSymmetric(root->left, root->right);
    }
    bool checkSymmetric(TreeNode *leftSymmetricNode, TreeNode *rightSymmetricNode)
    {
        if (!leftSymmetricNode && !rightSymmetricNode)
            return true;
        if (!leftSymmetricNode || !rightSymmetricNode)
            return false;
        if (leftSymmetricNode->val == rightSymmetricNode->val)
            return checkSymmetric(leftSymmetricNode->left, rightSymmetricNode->right) && checkSymmetric(leftSymmetricNode->right, rightSymmetricNode->left);
        return false;
    }
    /**
     * @name: 102.二叉树的层次遍历
     * @msg: 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
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
        return result;
    }
    /**
     * @name: 103.二叉树的锯齿形层次遍历
     * @msg: 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        bool flag = false;
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
            if (flag)
                reverse(level.begin(), level.end());
            flag = !flag;
            result.push_back(level);
            swap(next, current);
        }
        return result;
    }
    /**
     * @name: 104.二叉树的最大深度
     * @msg: 给定一个二叉树，找出其最大深度。
     * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
     * 说明: 叶子节点是指没有子节点的节点。
     */
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    /**
     * @name: 107.二叉树的层次遍历 II [相关102]
     * @msg: 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
     */
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result = levelOrder(root);
        reverse(result.begin(), result.end());
        return result;
    }
    /**
     * @name: 108.将有序数组转换为二叉搜索树
     * @msg: 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
     */
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (end <= start)
            return NULL;
        int mixIndex = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mixIndex]);
        root->left = sortedArrayToBST(nums, start, mixIndex);
        root->right = sortedArrayToBST(nums, mixIndex + 1, end);
        return root;
    }
    /**
     * @name: 110.平衡二叉树
     * @msg: 给定一个二叉树，判断它是否是高度平衡的二叉树。
     */
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
    /**
     * @name: 111.二叉树的最小深度
     * @msg: 给定一个二叉树，找出其最小深度。
     * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
     * 说明: 叶子节点是指没有子节点的节点。
     * @param {type} 
     * @return: 
     */
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int L = minDepth(root->left), R = minDepth(root->right);
        return 1 + (min(L, R) ? min(L, R) : max(L, R));
    }
    /**
     * @name: 112.路径总和
     * @msg: 
     * @param {type} 
     * @return: 
     */
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        return checkPathSum(root, sum, 0);
    }
    bool checkPathSum(TreeNode *root, int sum, int result)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
        {
            result += root->val;
            if (sum == result)
                return true;
            else
                return false;
        }
        else
        {
            result += root->val;
            return checkPathSum(root->left, sum, result) || checkPathSum(root->right, sum, result);
        }
    }
    /**
     * @name: 199.二叉树的右视图
     * @msg: 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
     */
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> current, next;
        vector<int> result;
        if (!root)
            return result;
        current.push(root);
        while (!current.empty())
        {
            vector<int> level;
            while (!current.empty())
            {
                TreeNode *tn = current.front();
                current.pop();
                if (tn->left)
                    next.push(tn->left);
                if (tn->right)
                    next.push(tn->right);
                level.push_back(tn->val);
            }
            result.push_back(level.back());
            swap(current, next);
            // level.clear();
        }
        return result;
    }
    /**
     * @name: 224. 基本计算器
     * @msg: 实现一个基本的计算器来计算一个简单的字符串表达式的值。字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
     * @param {type} 
     * @return: 
     */
    int calculate(string s)
    {
    }
    /**
     * @name: 459. 重复的子字符串
     * @msg: 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
     */
    bool repeatedSubstringPattern(string s)
    {
    }

    /**
     * @name: 622. 设计循环队列
     * @msg: 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。
     * 它也被称为“环形缓冲器”。 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，
     * 我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。 
     * Your MyCircularQueue object will be instantiated and called as such:
     * MyCircularQueue* obj = new MyCircularQueue(k);
     * bool param_1 = obj->enQueue(value);
     * bool param_2 = obj->deQueue();
     * int param_3 = obj->Front();
     * int param_4 = obj->Rear();
     * bool param_5 = obj->isEmpty();
     * bool param_6 = obj->isFull();
     */
    class MyCircularQueue
    {
    private:
        //int theSize; // 依靠队列为空时的基准情形来记录大小
        std::vector<int> data;
        int front, rear;
        int maxSize;

    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        explicit MyCircularQueue(int k)
            : maxSize(k + 1), front(0), rear(0)
        {
            data.resize(maxSize);
        }

        /** Insert an element into the circular queue. Return true if the operation is successful. */
        bool enQueue(int value)
        {
            if (isFull())
                return false;
            else
            {
                data[rear] = value;
                rear = (rear + 1) % maxSize;
                return true;
            }
        }

        /** Delete an element from the circular queue. Return true if the operation is successful. */
        bool deQueue()
        {
            if (isEmpty())
                return false;
            else
            {
                front = (front + 1) % maxSize;
                return true;
            }
        }

        /** Get the front item from the queue. */
        int Front()
        {
            if (isEmpty())
                return -1;
            return data[front];
        }

        /** Get the last item from the queue. */
        int Rear()
        {
            if (isEmpty())
                return -1;
            if (rear == 0)
                return data[maxSize - 1];
            return data[rear - 1];
        }

        /** Checks whether the circular queue is empty or not. */
        bool isEmpty()
        {
            return front == rear;
        }

        /** Checks whether the circular queue is full or not. */
        bool isFull()
        {
            return (rear + 1) % maxSize == front;
        }
    };
    /**
     * @name: 735.行星碰撞
     * 对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。
     * 找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞。
     */
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> stk;
        stack<int> stk_;
        vector<int> result;
        for (int star : asteroids)
        {
            if (stk.empty())
                stk.push(star);
            else
            {
                int temp = stk.top();
                if (temp < 0) //栈顶为负数
                {
                    stk.push(star);
                    continue;
                }
                else //栈顶为正数
                {
                    if (star > 0) //目标为正数，直接入栈
                    {
                        stk.push(star);
                        continue;
                    }
                    else // 目标为负数，需要比较
                    {
                        int sum = temp + star;
                        if (sum > 0) //栈顶>目标，栈不变
                            continue;
                        else if (sum == 0) //栈顶==目标，栈顶弹出
                        {
                            stk.pop();
                            continue;
                        }
                        else
                        //栈顶<目标，栈顶弹出，检测栈顶是否仍旧小于目标，
                        //如果是继续弹出，直到栈顶大于目标或者栈为空或者
                        //栈顶为负数或者栈顶和目标相等
                        {
                            stk.pop();
                            while (!stk.empty())
                            {
                                if (stk.top() > 0 && stk.top() + star < 0)
                                    stk.pop();
                                else
                                    break;
                            }
                            if (stk.empty())
                            {
                                stk.push(star);
                                continue;
                            }
                            else if (stk.top() + star == 0)
                            {
                                stk.pop();
                                continue;
                            }
                            else if (stk.top() + star > 0)
                            {
                                continue;
                            }
                            else if (stk.top() < 0 || stk.empty())
                            {
                                stk.push(star);
                                continue;
                            }
                        }
                    }
                }
            }
        }

        while (!stk.empty())
        {
            stk_.push(stk.top());
            stk.pop();
        }
        while (!stk_.empty())
        {
            result.push_back(stk_.top());
            stk_.pop();
        }
        return result;
    }
    /**
     * @name: 1041. 困于环中的机器人
     * @msg: 在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。机器人可以接受下列三条指令之一：
     * "G"：直走 1 个单位
     * "L"：左转 90 度
     * "R"：右转 90 度
     * 机器人按顺序执行指令 instructions，并一直重复它们。
     * 只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。
     * @tip: 如果可以循环最多执行四次，如果不可以循环，一定是因为第一次结束后点的位置不是（0，0）且指向正北
     * 
     */
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0;
        double thea = M_PI / 2;
        for (auto s : instructions)
        {
            if (thea >= M_PI * 2)
                thea -= M_PI * 2;
            if (thea < 0)
                thea += M_PI * 2;
            switch (s)
            {
            case 'G':
                std::cout << "(" << cos(thea) << "," << sin(thea) << ")" << std::endl;
                x += int(cos(thea));
                y += int(sin(thea));
                break;
            case 'L':
                thea += M_PI / 2;
                break;
            case 'R':
                thea -= M_PI / 2;
                break;
            default:
                break;
            }
        }
        if ((x != 0 || y != 0) && (thea == M_PI / 2))
            return false;
        else
            return true;
    }
    /**
     * @name: 二维网格迁移
     * 给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。
     * 每次「迁移」操作将会引发下述活动：
     *  位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
     *  位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
     *  位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
     * 请你返回 k 次迁移操作后最终得到的 二维网格。
     */
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        if (m == 0)
            return grid;
        for (; k > 0; k--)
        {
            vector<int> last_line;
            last_line.push_back(0);
            for (int i = 0; i < m; i++)
            {
                last_line.push_back(grid[i][n - 1]);
            }
            for (int j = 0; j < m; j++)
            {
                for (int l = n - 1; l > 0; l--)
                {
                    grid[j][l] = grid[j][l - 1];
                }
                grid[j][0] = last_line[j];
            }
            grid[0][0] = last_line.back();
        }
        return grid;
    }
};