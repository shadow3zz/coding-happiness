/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-09 16:36:48
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-11 13:01:59
 */
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

template <typename Comparable>
class AvlTree
{
private:
    struct AvlNode
    {
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;
        AvlNode(const Comparable &theElement, AvlNode *lt, AvlNode *rt, int h = 0)
            : element(theElement), left(lt), right(rt), height(h) {}
        AvlNode(Comparable &&theElement, AvlNode *lt, AvlNode *rt, int h = 0)
            : element(std::move(theElement)), left(lt), right(rt), height(h) {}
    };

    AvlNode *root;

    int height(AvlNode *t) const { return t == nullptr ? -1 : t->height; }
    void insert(const Comparable &x, AvlNode *&t)
    {
        if (!t)
            t = new AvlNode(x, nullptr, nullptr);
        else if (x < t->element)
        {
            insert(x, t->left);
        }
        else if (t->element < x)
        {
            insert(x, t->right);
        }
        balance(t);
    }
    static const int ALLOWED_IMBALANCE = 1;
    void balance(AvlNode *&t)
    {
        if (!t)
            return;
        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
            if (height(t->left->left) >= height(t->left->right))
                rotateWithLeftChild(t); //(1)
            else
                doubleWithLeftChild(t); //(2)
        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
            if (height(t->right->right) >= height(t->right->left))
                rotateWithRightChild(t); //(4)
            else
                doubleWithRightChild(t); //(3)
        t->height = std::max(height(t->left), height(t->right)) + 1;
    }

    void rotateWithLeftChild(AvlNode *&k2)
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }
    void rotateWithRightChild(AvlNode *&k2)
    {
        AvlNode *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->right), k2->height) + 1;
        k2 = k1;
    }
    void doubleWithLeftChild(AvlNode *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(AvlNode *&k3)
    {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    AvlNode *findMax(AvlNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        return findMax(t->right);
    }
    AvlNode *findMin(AvlNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }
    bool contains(const Comparable &x, AvlNode *t) const
    {
        if (t == nullptr)
            return false;
        if (x < t->element)
            contains(x, t->left);
        else if (t->element < x)
            contains(x, t->right);
        else
            return true;
    }
    void makeEmpty(AvlNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
    void printTree(AvlNode *t)
    {
        std::vector<std::vector<Comparable>> v = levelOrder(t);
        std::cout << "[";
        for (auto s : v)
        {
            std::cout << "[";
            for (auto w : s)
                std::cout << w << ",";
            std::cout << "]" << std::endl;
        }
        std::cout << "]" << std::endl;
    };

    std::vector<std::vector<Comparable>> levelOrder(AvlNode *t)
    {
        std::vector<std::vector<Comparable>> result;
        std::queue<AvlNode *> current, next;
        if (!t)
            return result;
        current.push(t);
        while (!current.empty())
        {
            std::vector<int> level;
            while (!current.empty())
            {
                level.push_back(current.front()->element);
                if (current.front()->left)
                    next.push(current.front()->left);
                if (current.front()->right)
                    next.push(current.front()->right);
                current.pop();
            }
            result.push_back(level);
            std::swap(next, current);
        }
        return result;
    }
    void remove(const Comparable &x, AvlNode *&t)
    {
        if (!t)
            return;
        if (x < t->element)
            remove(x, t->left);
        else if (t->element < x)
            remove(x, t->right);
        else if (!t->left && !t->right)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else{
            AvlNode *oldNode = t;
            t = (!t->right)?t->left:t->right;
            delete oldNode;
        }
        balance(t);
    }

    AvlNode *clone(AvlNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        return new AvlNode(t->element, clone(t->left), clone(t->right));
    }
    bool isValidBST(AvlNode*t) {
        if (!t) return true;
        if (t->left && t->element > t->left->element)
            return isValidBST(t->left);
        else if (t->right && t->element < t->right->element)
            return isValidBST(t->right);
        else if (!t->left && !t->right)
            return true;
        else
            return false;
    }

public:
    AvlTree() { init(); }
    AvlTree(const AvlTree &rhs) { operator=(rhs); }
    ~AvlTree() { makeEmpty(); }

    void init()
    {
        root = nullptr;
    }

    const Comparable &findMin() const { return findMin(root)->element; }
    const Comparable &findMax() const { return findMax(root)->element; }
    bool contains(const Comparable &x) const { return contains(x, root); }
    bool isEmpty() const { return (root == nullptr) ? true : false; }
    void makeEmpty() { makeEmpty(root); }

    const AvlTree &operator=(const AvlTree &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            root = clone(rhs.root);
        }
        return this;
    }

    int height() const { return height(root); }
    void insert(const Comparable &x) { insert(x, root); }
    void remove(const Comparable &x) { remove(x, root); }
    void printTree() { printTree(root); }
    bool isValid(){return isValidBST(root);}
    
};
