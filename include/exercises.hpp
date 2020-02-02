/*
 * @Descripttion: book_exec
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-01 17:15:09
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-02 13:20:00
 */
#pragma once
#include <iostream>
#include <iterator>
#include <list>
#include <time.h>

extern char *str[];
/**
 * @name: 课后习题3.1
 * @msg: 给定一个链表L和另外一个链表P，他们包含以升序排列的整数。操作printLots(L, P)将打印L中哪些由P所指定的位置上的元素。
 * @param {type} 
 * @return: 
 */
template <class Object>
void printLots(list<Object> &L, list<int> &P)
{
    if (P.back() > L.size())
        return;
    typename list<Object>::iterator itr_l;
    typename list<int>::iterator itr_p;
    int k = 1; //第一个元素对应L[0]
    itr_l = L.begin();
    for (itr_p = P.begin(); itr_p != P.end(); itr_p++)
    {
        for (; k != (*itr_p); k++, itr_l++)
            ;
        std::cout << *(itr_l) << std::endl;
    }
}
void exec_3_1()
{
    clock_t startTime, endTime;
    list<char *> l_char;
    list<int> count;
    count.push_back(int(1));
    count.push_back(3);
    count.push_back(4);
    int n = sizeof(str) / sizeof(char *);
    for (int i = 0; i < n; i++)
    {
        l_char.push_back(str[i]);
    }
    startTime = clock();
    printLots(l_char, count);
    endTime = clock();
    std::cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
}

/**
 * @name: 课后习题3.4 
 * @msg: 给定两个排序后的表L1、L2，仅使用基本的表操作来计算交集。 
 * @tips: 给定的表也是一个集合，不存在重复的元素
 */
template <class Object>
list<Object> intersection(list<Object> &L_1, list<Object> &L_2)
{
    list<Object> result;
    typename list<Object>::iterator itr_1 = L_1.begin();
    typename list<Object>::iterator itr_2 = L_2.begin();
    while (itr_1 != L_1.end() && itr_2 != L_2.end())
    {
        if (*itr_1 == *itr_2)
        {
            result.push_back(*itr_2);
            itr_1++;
            itr_2++;
        }
        else if (*itr_1 < *itr_2)
        {
            itr_1++;
        }
        else
        {
            itr_2++;
        }
    }

    return result;
}

void exec_3_4()
{
    list<int> list_1 = {1, 2, 3, 4, 5, 6};
    list<int> list_2 = {2, 4,  5};
    for (auto s : intersection(list_1, list_2))
        std::cout << s << "";
    std::cout << std::endl;
}

/**
 * @name: 课后习题3.5
 * @msg: 给定两个排序后的表L1、L2，仅使用基本的表操作来计算并集。
 * @tips: 给定的表也是一个集合，不存在重复的元素
 */
template <class Object>
list<Object> listUnion(list<Object> &L_1, list<Object> &L_2)
{
    list<Object> result;
    typename list<Object>::iterator itr_1 = L_1.begin();
    typename list<Object>::iterator itr_2 = L_2.begin();
    while (itr_1 != L_1.end() && itr_2 != L_2.end())
    {
        if (*itr_1 == *itr_2)
        {
            result.push_back(*itr_1);
            itr_1++;itr_2++;
        }
        else if (*itr_1 < *itr_2)
        {
            result.push_back(*itr_1);
            itr_1++;
        }
        else
        {
            result.push_back(*itr_2);
            itr_2++;
        }
    }
    return result;
}

void exec_3_5()
{
    list<int> list_1 = {1, 2, 3, 4, 5, 6};
    list<int> list_2 = {2, 4, 5};
    for (auto s : listUnion(list_1, list_2))
        std::cout << s << "";
    std::cout << std::endl;
}


