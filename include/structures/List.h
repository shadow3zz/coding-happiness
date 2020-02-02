/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-30 16:18:24
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-02 12:17:19
 */
#pragma once

template <typename Object>
class List
{
private:
    struct Node
    {
        Object data;
        Node *prev;
        Node *next;

        explicit Node(const Object &d = Object(), Node *p = nullptr, Node *n = nullptr)
            : data(d), prev(p), next(n) {}
    };

public:
    class const_iterator
    {
    public:
        const_iterator() : current(nullptr) {}

        const Object &operator*() const { return retrieve(); }

        const_iterator &operator++() // ++itr
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int) //itr++
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) const { return current == rhs.current; }
        bool operator!=(const const_iterator &rhs) const { return !(*this == rhs); }

    protected:
        Node *current;
        Object &retrieve() const { return current->data; }

        explicit const_iterator(Node *p) : current(p) {}

        friend class List<Object>;
    };

    class iterator : public const_iterator
    {
    public:
        iterator() = default;

        Object &operator*() { return this->retrieve(); }
        const Object &operator*() const { return const_iterator::operator*(); }

        iterator &operator++()
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        iterator(Node *p) : const_iterator(p) {}
        friend class List<Object>;
    };

public:
    List() { init(); }
    List(const List &rhs)
    {
        init();
        *this = rhs;
    }
    ~List()
    {
        clear();
        delete head;
        delete tail;
    }

    const List &operator=(const List &rhs)
    {
        if (this == &rhs)
            return *this;
        clear();
        for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
            push_back(*itr);
        return *this;
    }

    iterator begin() { return iterator(head->next); }

    const_iterator begin() const { return const_iterator(head->next); }

    iterator end() { return iterator(tail); }
    const_iterator end() const { return const_iterator(tail); }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }
    void clear()
    {
        while (!empty())
            pop_front();
    }

    Object &front() { return *begin(); }
    const Object &front() const { return *begin(); }

    Object &back() { return *--end(); }
    const Object &back() const { return *--end(); }

    void push_front(const Object &x) { insert(begin(), x); }
    void push_back(const Object &x) { insert(end(), x); }
    void pop_front() { erase(begin()); }
    void pop_back() { erase(--end()); }

    iterator insert(iterator pos, const Object &x)
    {
        Node *p = pos.current;
        theSize++;
        return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
    }
    iterator erase(iterator pos)
    {
        Node *p = pos.current;
        iterator retVal(p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return retVal;
    }
    iterator erase(iterator start, iterator end)
    {
        for (iterator itr = start; itr != end;)
            itr = erase(itr);
        return end;
    }

private:
    int theSize;
    Node *head;
    Node *tail;

    void init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }


public:
    //3.2 交换两个相邻元素
    void swapWithNext(Node *p){
        Node *beforep, *afterp;
        beforep = p->prev;
        afterp = p->next;
        
        beforep->next = afterp;
        p->next = afterp->next;
        afterp->next->prev = p;
        afterp->prev = beforep;
        afterp->next = p;
        p->prev = afterp;
    }
    //3.3 实现find
    template<typename Iterator>
    iterator find(Iterator start, Iterator end, const Object& x)
    {
        for(;start!=end; start++)
            if (*start == x)
                break;
        return start;
    }
    
};

