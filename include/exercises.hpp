/*
 * @Descripttion: book_exec
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-01 17:15:09
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-02 00:30:03
 */
#pragma once
#include <iostream>
#include <iterator>
#include <list>
/**
 * @name: 课后习题3.1
 * @msg: 给定一个链表L和另外一个链表P，他们包含以升序排列的整数。操作printLots(L, P)将打印L中哪些由P所指定的位置上的元素。
 * @param {type} 
 * @return: 
 */
template <class Object>
void printLots(list<Object> &L, list<int> &P)
{
    if (P.back() > L.size()) return;
    typename list<Object>::iterator itr_l;
    typename list<int>::iterator itr_p;
    int k = 1;  //第一个元素对应L[0]
    itr_l = L.begin();
    for ( itr_p = P.begin(); itr_p != P.end(); itr_p++)
    {
        for (;k!=(*itr_p);k++,itr_l++);
        std::cout << *(itr_l) << std::endl;
    }
    
}