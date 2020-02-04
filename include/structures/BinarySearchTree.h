/*
 * @Descripttion: 二叉查找树，不含重复元素
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-04 17:02:29
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-04 22:45:17
 */
template <typename Comparable>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &rhs) { operator=(rhs); }
    ~BinarySearchTree() { makeEmpty(); }

    const Comparable &findMin() const
    {
        return findMin(root)->element;
    }
    const Comparable &findMax() const
    {
        return findMax(root)->element;
    }
    bool contains(const Comparable &x) const { return contains(x, root); }
    bool isEmpty() const { return (root == nullptr) ? true : false; }
    void printTree() const { printTree(root); }

    void makeEmpty() { makeEmpty(root); }
    void insert(const Comparable &x)
    {
        insert(x, root);
    }
    void remove(const Comparable &x)
    {
        remove(x, root);
    }

    const BinarySearchTree &operator=(const BinarySearchTree &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            root = clone(rhs.root);
        }
        return this;
    }

private:
    struct BinaryNode
    {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
            : element(theElement), left(lt), right(rt) {}
    };

    BinaryNode *root;

    void insert(const Comparable &x, BinaryNode *&t) const
    {
        if (t == nullptr)
        {
            t = new BinaryNode(x, nullptr, nullptr);
        }
        else if (x < t->element)
            insert(x, t->left);
        else if (t->element < x)
            insert(x, t->right);
        else
            ; // 暂不考虑重复元素的插入情况
    }
    void remove(const Comparable &x, BinaryNode *&t) const
    {
        if (t == nullptr)
            return;
        if (x < t->element)
            remove(x, t->left);
        else if (t->element < x)
            remove(x, t->right);
        else if (t->right != nullptr && t->left != nullptr)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }
    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        return findMax(t->right);
    }
    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }
    bool contains(const Comparable &x, BinaryNode *t) const
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
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
    void printTree(BinaryNode *t) const;
    BinaryNode *clone(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        return new BinaryNode(t->element, clone(t->left), clone(t->right));
    }
};

