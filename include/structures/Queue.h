/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-01 16:01:47
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-01 16:18:32
 */
#pragma once
#define TYPE 1
#include "List.h"
#include "Vector.h"

#if TYPE
template <typename Object>
class Queue
{
public:
    Queue() {}
    ~Queue() {}
    void dequeue() { l.pop_front(); }
    void enqueue(Object &x) { l.push_back(x); }

    Object &front() { return l.front(); }
    Object &back() { return l.back(); }

    int size() const { return l.size(); }
    bool empty() const { return l.empty(); }

private:
    List<Object> l;
};
#else
template <typename Object>
class Queue
{
public:
private:
};
#endif
