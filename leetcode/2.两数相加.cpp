/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-21 22:53:38
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-21 23:58:48
 */
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *start = new ListNode(0);
        ListNode *result = start;
        ListNode *pNode_1 = l1;
        ListNode *pNode_2 = l2;
        int flag = 0;
        while (pNode_1 || pNode_2)
        {
            
            int temp = (pNode_1 ? pNode_1->val : 0) + (pNode_2 ? pNode_2->val : 0);
            int sum = temp+flag;
            result = result->next = new ListNode(sum%10);
            flag = sum/10;
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
};
// @lc code=end
