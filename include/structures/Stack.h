/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-31 13:47:34
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-01-31 18:04:15
 */
#pragma once

#include "Vector.h"
template <typename Object>
class Stack
{
public:
    Stack() {}
    ~Stack() {}
    void push(Object &x) { v.push_back(x); }
    void pop() { v.pop_back(); }
    Object &top() { return v.back(); }
    const Object &top() const { return v.back(); }

    void clear()
    {
        while (!empty())
            pop();
    }
    bool empty() const { return v.empty(); }

private:
    Vector<Object> v;
};
