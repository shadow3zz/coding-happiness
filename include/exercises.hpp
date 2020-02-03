/*
 * @Descripttion: book_exec
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-01 17:15:09
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-03 15:34:27
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
    list<int> list_2 = {2, 4, 5};
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
            itr_1++;
            itr_2++;
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

/**
 * @name: 课后习题3.6
 * @msg: Josephus问题是下面的这个游戏：有N个人坐成一圈，编号为1至N。从编号为1的人开始传递热马铃薯。M次传递后，持有热马铃薯的人
 * 退出游戏，圈缩小，然后游戏从退出人下面的人开始，继续进行。最终留下来的人获胜。这样，如果M=0并且N=5，那么参加游戏的人依次退出，
 * 5号获胜。如果M=1并且N=5，那么退出的顺序就是2、4、1、5.
 * @tips: M%N
 */
void JosephusProblem(int M, int N)
{
    list<int> circle;
    for (int i = 0; i < N; i++)
    {
        circle.push_back(i + 1);
    }

    typename list<int>::iterator itr = circle.begin();
#if 0
    int lastPos = 0;
    while (!circle.empty())
    {
        for (int k = 0; k < M; ++k)  // 可以优化k，现在如果M很大，N很小需要多次循环，可以利用M%N的结果作一次循环
        {
            itr++;
            if (itr == circle.end())
                itr = circle.begin();
        }
        lastPos = *itr;
        itr = circle.erase(itr);
        if (itr == circle.end()) 
            itr = circle.begin();
    }
    std::cout << "The winner is No." << lastPos << std::endl;
#else
    int nextPos;
    int lastPos = 0;
    while (!circle.empty())
    {
         nextPos = M % circle.size();
        for (int k = 0; k < nextPos; ++k) 
        {
            itr++;
            if (itr == circle.end())
                itr = circle.begin();
        }
        lastPos = *itr;
        itr = circle.erase(itr);       
        if (itr == circle.end()) 
            itr = circle.begin();
    }
    std::cout << "The winner is No." << lastPos << std::endl;
#endif
}
void exec_3_6()
{
    JosephusProblem(0, 5);
}


