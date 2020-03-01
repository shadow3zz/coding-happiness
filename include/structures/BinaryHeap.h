/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-03-01 12:04:47
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-03-01 12:33:44
 */
#pragma once
#include <vector>

/**
 * @name: 二叉堆
 * @msg: 堆序性质：最小元在根上，如果考虑任意子树则子树也是堆，所以每个结点就应该小于它所有的后裔
 * 二叉堆类比二叉树结构，类似于完全二叉树，每个结点存储在vector中，结点i对应左节点2i，右节点2i+1的位置
 * 
 * @param {type} 
 * @return: 
 */
template<typename Comparable>
class BinaryHeap
{
private:
    int  currentSize;
    std::vector<Comparable> array;

    void buildHeap();
    // 下滤
    void percolateDown(int hole);
public:
    explicit BinaryHeap(/* args */);
    explicit BinaryHeap(const std::vector<Comparable> & items);
    bool isEmpty() const;
    const Comparable & findMin() const;
    void insert( const Comparable& x){
        if (currentSize ==array.size() -1)
            array.resize(array.size()*2);
        //上滤
        int hole = ++currentSize;
        for (;hole>1&x<array[hole/2];hole/=2)
            array[hole] = array[hole/2];
        array[hole/2] = x; 
    }
    void deleteMin();
    void deleteMin(Comparable &minItem);
    void makeEmpty();

    ~BinaryHeap();
};


