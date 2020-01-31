/*
 * @Descripttion: Vector.h-向量的实现
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-30 12:17:51
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-01-31 17:18:17
 */
#pragma once
#include <iostream>
template <typename Object>
class Vector
{
public:
    explicit Vector(int initSize = 0) : theSize(initSize), theCapacity(initSize + SPACE_CAPACITY)
    {
        objects = new Object[theCapacity];
    }
    Vector(const Vector &rhs) : objects(NULL)
    {
        operator=(rhs);
    }
    ~Vector()
    {
        delete[] objects;
    }

    // 操作符重载
    const Vector& operator=(const Vector &rhs);
    //
    void resize(int newSize);
    //
    void reserve(int newCapacity);
    //
    Object &operator[](int index);
    const Object &operator[](int index) const;
    //
    bool empty() const { return size() == 0; }
    int size() const { return theSize; }
    int capacity() const { return theCapacity; }
    //
    void push_back(const Object &x);
    void pop_back();
    Object &back() {return objects[theSize-1];};
    const Object &back() const;
    //
    typedef Object *iterator;
    typedef const Object &const_iterator;
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    enum
    {
        SPACE_CAPACITY = 16
    };

private:
    int theSize;
    int theCapacity;
    Object *objects;
};

template <class Object>
const Vector<Object>& Vector<Object>::operator=(const Vector<Object> &rhs)
{
    if (this != &rhs)
    {
        delete[] objects;
        theCapacity = rhs.capacity();
        theSize = rhs.size();
        objects = new Object[theCapacity];

        // 另外一种常规写法
        for (int i = 0; i < theSize; i++)
        {
            objects[i] = rhs.objects[i];
        }
    }
    return *this;
}

template <class Object>
void Vector<Object>::resize(int newSize)
{
    if (newSize > theCapacity)
    {
        reserve(2 * newSize + 1);
    }
    theSize = newSize;
}

template <class Object>
void Vector<Object>::reserve(int newCapacity)
{
    if (newCapacity < theSize)
    {
        return;
    }
    Object *oldArray = objects;
    delete[] objects;
    theCapacity = newCapacity;
    objects = new Object[newCapacity];
    for (int i = 0; i < theSize; i++)
    {
        objects[i] = oldArray[i];
    }
    delete[] oldArray;
}

template <class Object>
Object &Vector<Object>::operator[](int index)
{
    return objects[index];
}

template <class Object>
const Object &Vector<Object>::operator[](int index) const
{
    return objects[index];
}

template <typename Object>
void Vector<Object>::push_back(const Object &x)
{
    if (theSize == theCapacity)
        reserve(theSize * 2 + 1);
    objects[theSize++] = x;
}

template <class Object>
void Vector<Object>::pop_back()
{
    theSize--;
}

template <class Object>
const Object &Vector<Object>::back() const
{
    return objects[theSize - 1];
}

template <class Object>
Object *Vector<Object>::begin()
{
    return &objects[0];
}

template <class Object>
Object *Vector<Object>::end()
{
    return &objects[size()];
}

template <class Object>
const Object &Vector<Object>::begin() const
{
    return &objects[0];
}

template <class Object>
const Object &Vector<Object>::end() const
{
    return &objects[size()];
}