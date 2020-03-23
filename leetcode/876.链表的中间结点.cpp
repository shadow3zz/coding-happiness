/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-23 12:48:24
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-23 13:00:15
 */
/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        ListNode * first = head;
        ListNode * second = head;
        //双指针,不同步长
        for (;;){
            if (!first->next){
                return second;
            }
            else if (!first->next->next){
                return second->next;
            }
            else {
                first = first->next->next;
                second = second->next;
            }
        }
    }
};
// @lc code=end

