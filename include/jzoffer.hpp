/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-06-04 21:46:03
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-07-22 16:46:30
 */
#pragma once

#include <bits/stdc++.h>
using namespace std;

/**================================================================================================
 * ----------------------------------------链表结构------------------------------------------------
 *===============================================================================================*/
struct ListNode{
    int         m_nKey;
    ListNode*   m_pNext;
    ListNode(int val):m_nKey(val),m_pNext(nullptr){}
    ListNode(int x, ListNode *next) : m_nKey(x), m_pNext(next) {}
};
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode(0);
    pNode->m_nKey = value;
    pNode->m_pNext = nullptr;

    return pNode;
}
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}
/**================================================================================================
 * ----------------------------------------二叉树结构----------------------------------------------
 *===============================================================================================*/
struct BinaryTreeNode{
    int value;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
    BinaryTreeNode(int v = 0, BinaryTreeNode* pLeft=nullptr, BinaryTreeNode* pRight=nullptr)
                    :value(v), m_pLeft(pLeft), m_pRight(pRight){}
};
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->value = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;

    return pNode;
}

void ConnectBinaryTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if(pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if(pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}
/**================================================================================================
 * ----------------------------------------复杂链表结构--------------------------------------------
 *===============================================================================================*/
struct ComplexListNode
{
    int                 m_nValue;
    ComplexListNode*    m_pNext;
    ComplexListNode*    m_pSibling;
};
ComplexListNode* CreateNode(int nValue);
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
void PrintList(ComplexListNode* pHead);
ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();
    
    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;

    return pNode;
}
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}
void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);

        if(pNode->m_pSibling != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}
/**================================================================================================
 * ------------------------------------------------------------------------------------------------
 *===============================================================================================*/
/**
 * @name: 十种排序算法
 * @msg: 
 * @param {type} 
 * @return: 
 */
namespace SORT{
    /**
     * @name: 1.插入排序
     * @msg: 从第二个元素开始，依次比较前面的元素，如果前面元素大于当前temp就将前面元素后移一位，
     *       直到遇到比本元素小的，将temp插入到这个元素后面。
     *       |---O(n^2)---稳定---|
     */    
    template<typename T>
    void insertSort(vector<T> &vec){
        size_t j;
        for (size_t i = 1; i<vec.size(); i++){
            T temp = vec[i];
            for ( j = i; j>0 && temp < vec[j-1]; j--){
                vec[j] = vec[j-1];
            }
            vec[j] = temp;
        }
    }
    
    /**
     * @name: 2.快速排序
     * @msg: 主要是找到中间元素，这里用的方法是随机下标作为中间值，将中间值移至集合末尾，逐个比较，
     *       将vec[index]<vec[end]的元素和vec[small]交换，最后small的位置就是分割的位置，通过分治，解决子问题。
     *       |---O(nlog2n)---不稳定---|
     */    
    int RandomInRange(int min, int max)
    {
        int random = rand() % (max - min + 1) + min;
        return random;
    }
    template<typename T>
    int Partition(vector<T> &vec, int i, int j){
        int index = RandomInRange(i, j);
        swap(vec[index], vec[j]);
        int small = i-1;
        for (index = i; index < j; index++){
            if (vec[index]<vec[j]){
                ++small;
                swap(vec[small], vec[index]);
            }
        }
        ++small;
        swap(vec[small], vec[j]);
        return small;
    }
    template<typename T>
    void quickSort(vector<T> &vec, int i, int j){
        if (i<j){
            int index = Partition<T>(vec, i, j);
            quickSort<T>(vec, i, index-1);
            quickSort<T>(vec, index+1, j);
        }
    }
    template<typename T>
    void quickSort(vector<T> &vec){
        if (vec.empty()) return ;
        int i = 0, j = vec.size()-1;
        quickSort<T>(vec, i, j);
    }
    // 快排循环写法
    template<typename T>
    void quickSortLoop(vector<T> &vec){
        int i = 0, j = vec.size()-1;
        stack<int> stk;
        stk.push(i);stk.push(j);
        while (!stk.empty()){
            int end = stk.top();stk.pop();
            int start = stk.top();stk.pop();
            if (start < end){
                int index = RandomInRange(start, end);
                swap(vec[index], vec[end]);
                int small = start-1;
                for (index = start; index<end; index++){
                    if (vec[index]<vec[end]){
                        ++small;
                        swap(vec[index], vec[small]);
                    }
                }
                ++small;
                swap(vec[end], vec[small]);

                stk.push(start);stk.push(small-1);
                stk.push(small+1);stk.push(end);
            }
        }
        for(auto s:vec){
            cout << s << "\t" ;
        }
        cout << endl;
    }
}


/**
 * @name: 面试题1：赋值运算符函数
 * @msg: 1.返回值为该类型的引用，返回左值允许连续赋值；
 *       2.传入参数为常量引用，一方面引用可以节省内存空间，另外一方面由于是赋值操作传入的数值是不需要改变其数值的；
 *       3.判断传入的实例是否和当前实例是一个对象，因为考虑到在拷贝的同时会释放掉当前实例中的内容，如果不比较两者地址，会将这个对象直接释放掉；
 *       4.需要将实例自身已有的内存释放，不然会出现内存泄漏。
 */
class CMyString{
public:
    CMyString(char *pData = nullptr){
        if (pData == nullptr){
            m_pData = new char[1];
            m_pData[0] = '\0';
        }
        else {
            m_pData = new char[strlen(pData)+1];
            strcpy(m_pData, pData);
        }
    }
    CMyString(const CMyString& str){
        m_pData = new char[strlen(str.m_pData)+1];
        // delete []m_pData;
        strcpy(m_pData, str.m_pData);
    }
    ~CMyString(){
        delete []m_pData;
    }

    CMyString& operator=(const CMyString &cmp){
    #if 0 // 这种写法存在内存不足，导致程序异常，由于在释放当前实例后，分配新的内存空间可能太大，系统不能成功new这个对象，并且之前的实例也被释放了，非常不安全
        if (this == &cmp){
            return (*this);
        }
        // --------------内存不安全--------------------------------------
        delete []m_pData;
        m_pData = new char[strlen(cmp.m_pData)+1];
        // --------------内存安全--------------------------------------
        // char * new_pData = new char[strlen(cmp.m_pData)+1];
        // delete []m_pData;
        // m_pData = new_pData;
        // ---------------结束-------------------------------------
        strcpy(m_pData, cmp.m_pData);
        return (*this);
        
    #else // 为了解决上述问题，一种解决方法是 先用new分配新内容，再用delete释放已有内容，另外一种解决方法是 创建一个临时实例在交换临时实例和原来的实例
        if (this != &cmp){
            CMyString tmp(cmp);
            char *pTemp = tmp.m_pData;   // pTemp和tmp.m_pData地址一样
            tmp.m_pData = m_pData;       // tmp.m_pData和m_pData地址一样
            m_pData = pTemp;             // m_pData和pTemp地址一样
            // 事实上三者交换，目的是为了让之前的实例中的指针所指的空间释放
        }
        return *this;

    #endif
    }
    
private:
    char* m_pData;
};

/**
 * @name: 面试题2.单例模式——对于系统中的某些类来说，只有一个实例很重要
 * @msg: 1.单例模式中构造函数、拷贝构造、赋值构造为私有函数，以避免重复创建实例对象；
 *       2.创建一个静态实例对象instance，这个对象是一个私有化的单例类的静态指针，未初始化；****延迟初始化****
 *       3.考虑实例化函数GetInstance()中线程问题；
 *       4.主要有两种模式，懒汉模式和饿汉模式
 * @tips: 全局变量和单例模式之间的区别，全局变量在有效管理下是可以达到单例模式的功能，即工程
 *        范围内只对一个全局对象操作，但是考虑到一般工程是在团队开发基础上实施，难免会遇到有
 *        人再次实例了一个对象，就会破坏大家的默契，如果这个实例化的类当中有静态成员对象就会
 *        导致不协调。另外从设计模式的角度出发，这种模式化设计在一定程度上减轻了项目开发的复
 *        杂化问题，让变量管理变得简单化。
 */
namespace Singleton{
    class Singleton_1{
    public:
        static Singleton_1* GetInstance(){
            // 二次检查锁，持有锁和等待锁两种线程在这个同步块中
            if (instance == nullptr){
                std::lock_guard<std::mutex> lock(m_mutex);
                if (instance == nullptr)
                    instance = new Singleton_1;
                    // 编译器可能会将这里的顺序重排，如果发生重排序，另一个并发执行的线程 B 就有可能在第 4 行判断 instance 不为 null。
                    // 线程 B 接下来将访问 instance 所引用的对象，但此时这个对象可能还没有被 A 线程初始化！
            }
            return instance;
        }
        // // 单例模式（线程安全 std::call_once）
        // static Singleton* GetInstance(){
        //     static std::once_flag m_flag;
        //     std::call_once(m_flag,[&](){
        //         instance.reset(new Singleton);
        //     });
        //     return instance;
        // }
        // std::unique_ptr<Singleton_1> instance; instance.reset(new Singleton_1);
        void DeleteInstance(){
            if (instance != nullptr)
            {
                delete instance;
                instance = nullptr;
            }
        }
        ~Singleton_1() = default;
    private:
        Singleton_1()=default;
        Singleton_1(const Singleton_1& rhs) = delete;
        Singleton_1& operator=(const Singleton_1& rhs) = delete;
        
        static std::mutex m_mutex;
        static Singleton_1* instance;
    };

    std::mutex Singleton_1::m_mutex;
    Singleton_1* Singleton_1::instance = nullptr;

    // 单例模式 2（饿汉模式）
    class Singleton_2{
    public:
        static Singleton_2 *GetInstance(){
            return instance_2;
        }

        static void DestreyInstance() {
            if (instance_2 != nullptr) {
                delete instance_2;
            }
        }
    private:
        Singleton_2() = default;
        Singleton_2(const Singleton_2& rhs) = delete;
        Singleton_2& operator=(const Singleton_2& rhs) = delete;

        static Singleton_2* instance_2;
    };

    Singleton_2* Singleton_2::instance_2 = new Singleton_2;
}

/**
 * @name: 面试题3：数组中重复的数字 有两个题目（长度为n，元素在0~n-1之间，找出所有重复数字）和（长度为n+1，元素在1~n之间，找出任意一个重复的数字）
 * @msg: 1.通过长度为n的辅助数组，将原数组中的数字i放到辅助数组下标为i的位置，如果辅助数组下标记录是重复的对象，就说明原数组中i是重复数字；
 *       2.类似1方法，用map存储记录；
 *       3.以上两种方法都用了O(n)的额外辅助空间，一方面是因为要输出所有重复数字需要空间，另外一方面是有辅助数组需要空间，假如不需要输出所有的重复数字，只需要找到一个重复数字：
 *          3.1 找到所有重复数字 题目一：比较下标i对应元素m，是否满足m==i，如果满足则i++，否则比较下标m对应元素是否等于m，等于表明重复，否则交换;
 *          3.2 找到一个重复数字 题目二：以时间换空间，长度为n+1，那么计算数组中属于1~(n+1)>>1范围内的个数，如果超过(n+1)>>1，
 *              则说明在1~(n+1)>>1范围内存在重复的元素，否则一定在另外(n+1)>>1+1~n之间。确定区间后，再次二分，直到确认一个重复的数字。
 */
namespace duplicate{
    std::vector<int> duplicate_1(std::vector<int> &input, int n){
        if (input.size() <= 1){
            return {};
        }
        // std::sort(input.begin(), input.end());
        std::vector<int> ans;
        std::vector<bool> dup(n, 0);
        for(size_t i = 0; i<input.size(); ++i){
            if (dup[input[i]] == 0) {
               
                dup[input[i]] = 1;
            }
            else if(dup[input[i]] == 1) {
                dup[input[i]] = 2;
                ans.push_back(input[i]);
            }
        }
        return ans;
    }
    
    std::vector<int> duplicate_2(std::vector<int> &input, int n){
        if (input.size() <= 1){
            return {};
        }
        std::map<int, bool> dup;
        std::vector<int> ans;
        for (auto s:input){
            if (dup.find(s) != dup.end()){
                dup[s] = true;
            }
            else{
                 dup[s] = false;
            }
        }
        for (auto itr = dup.begin(); itr != dup.end(); itr++){
            if (itr->second == true) 
                ans.push_back(itr->first);
        }
        return ans;
    }

    std::vector<int> duplicate_3(std::vector<int> &input, int n){
        if (input.size() <= 1){
            return {};
        }
        std::vector<int> ans;
        for (int i = 0; i<input.size(); ++i){
            while(input[i] != i){
                if (input[i] == input[input[i]]){
                    ans.push_back(input[i]);
                    break;
                }
                std::swap(input[i], input[input[i]]);
            }
        }
        // 去重
        std::sort(ans.begin(), ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }

     int rangeCount(std::vector<int> &input, int from, int to){
        int i = 0;
        for(auto s:input){
            if (s<=to&&s>=from){
                i++;
            }
        }
        return i;
    }
    int duplicate_4(std::vector<int> &input, int n){
        // input.size()  = n + 1 数组长度为n+1，元素个数在1~n之间n个数
        if (input.size() <= 1){
            return -1;
        }
        int first = 1;
        int end = input.size()-1;
        while (end>=first)  
        {
            int middle = ((end-first)>>1 )+ first;
            int count = rangeCount(input, first, middle);
            if (end == first)
                return input[first];
            if (count > (middle-first+1))
                end = middle;
            else
                first = middle+1;
        }
        return -1;
    }
}

/**
 * @name: 面试题4.二维数组中的查找
 * @msg: 基本上就是一个找规律的问题，从矩阵的一个角上面开始比较数字，但要考虑是不是范围有重复的问题，
 *       在按照题目的所述要求下，从右上角比较合适，数字小于number就将范围移到下一行，如果数字大于number
 *       就将范围移到上一列，直到超出矩阵或找到number。时间复杂度O(n+n)=O(n)。
 */
namespace Find{
    bool Find(std::vector<std::vector<int> > &input, int number){
        if (input.size() == 0) 
            return false;
        size_t row = 0, col = input[0].size()-1;
        while (row<input.size() && col>0){
            if (input[row][col] == number){
                return true;
            }
            else if (input[row][col] > number){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
}

/**
 * @name: 面试题5.空格替换
 * @msg: 没啥好说的，如果输入是个string字符串就很简单，如果是char*就要分配具体空间。
 */
namespace ReplaceBlank{
    void ReplaceBlank(std::string &input){
        if (input.size() == 0)
            return;
        std::string output;
        for (auto s:input){
            if (s!=' '){
                output+=s;
            }
            else
                output+="%20";
        }
        input = output;
    }
}

/**
 * @name: 面试题6：从尾到头打印链表
 * @msg: 主要还是要从源头遍历到尾，记录每一个对象的数值，然后逆序打印出来：
 *          1.模拟栈，模拟递归的思想；
 *          2.递归，直到遇到链表尾开始return。
 */
namespace PrintListReversing_Iteratively{
    void PrintList_Reversing_Iteratively_1(ListNode* input){
        if (!input){
            return;
        }
        
        std::stack<int> stk;
        while (!input->m_pNext)
        {
            stk.push(input->m_nKey);
            input = input->m_pNext;
        }
        while (!stk.empty())
        {
            std::cout << stk.top() << '\t' ;
            stk.pop();
        }
        std::cout << std::endl;       
    }

    void PrintList_Reversing_Iteratively_2(ListNode* input){
        if (!input){
            return;
        }
        else{
            PrintList_Reversing_Iteratively_2(input->m_pNext);
            std::cout << input->m_nKey << '\t';
        }
    }
}

/**
 * @name: 面试题7.重建二叉树
 * @msg: 重建二叉树有多种方法，主要看提供哪些信息：
 *          1.前序遍历和中序遍历构造二叉树，由前序遍历获得根节点，然后根据中序遍历获得左子树和右子树序列，根据左子树和右子树长度在前序遍历中分出左子树部分和右子树部分，递归直到遍历所有元素；
 *          2.中序遍历和后续遍历类似；
 *          3.层次遍历和中序遍历，由层次遍历获得根节点，然后根据中序遍历获得左子树和右子树序列，左右子树不为空时，根据层序遍历中下两个个元素属于左子树和右子树的根节点。
 */
namespace ConstructBinaryTree{
    /**
     * @msg: 递归重建二叉树，前序和中序
     */    
    BinaryTreeNode* ConstructBinaryTree_1(std::vector<int> &preorder, std::vector<int> &midorder){
        if (preorder.size()!=0){
            BinaryTreeNode* root = new BinaryTreeNode();
            root->value = preorder[0];
            auto mid = std::find(midorder.begin(), midorder.end(), root->value);
            int leftTreeNumber = std::distance(midorder.begin(), mid);
            std::vector<int> leftTreePreorder(preorder.begin()+1, preorder.begin()+leftTreeNumber+1);
            std::vector<int> leftTreeMidorder(midorder.begin(), mid);
            root->m_pLeft = ConstructBinaryTree_1(leftTreePreorder, leftTreeMidorder);
            std::vector<int> rightTreePreorder(preorder.begin()+1+leftTreeNumber, preorder.end());
            std::vector<int> rightTreeMidorder(mid+1, midorder.end());
            root->m_pRight = ConstructBinaryTree_1(leftTreePreorder, leftTreeMidorder);
            return root;
        }
        return nullptr;
    }
    /**
     * *******************************************************************************************
     * @msg: 非递归重建二叉树**********************************************************************
     * *******************************************************************************************
     */    
    BinaryTreeNode* ConstructBinaryTree_2(std::vector<int>& preorder, std::vector<int>& inorder){
        int len = preorder.size(), i = 0, j = 0;

        BinaryTreeNode **nodes = new BinaryTreeNode*[len+1];
        int sLen = 0;
        BinaryTreeNode *root = new BinaryTreeNode(0);
        BinaryTreeNode *toAddRight = NULL, *p;
        nodes[sLen++] = root;
        while(j < len){
            do{
                p = new BinaryTreeNode(preorder[i]);
                if(toAddRight){
                    toAddRight->m_pRight = p;
                } else {
                    nodes[sLen-1]->m_pLeft = p;
                }
                toAddRight = NULL;
                nodes[sLen++] = p;
            }while(preorder[i++] != inorder[j]);

            while(j < len && nodes[sLen-1]->value == inorder[j]){
                toAddRight = nodes[--sLen];
                j++;
            }
        }
        return root->m_pLeft;
    }
}

/**
 * @name: 面试题8.二叉树的下一个结点（中序遍历）
 * @msg: 二叉树的中序遍历序列中，对应一个结点的下一个结点就是中序遍历里的下一个元素，
 *       1.如果一个结点有右子树，那么他的下一个结点就是他的右子树的最左结点
 *       2.如果结点没有右子树，且是他父节点的左子结点，那么他的下一个结点就是他的父节点；
 *       3.如果一个结点既没有右子树，并且他还是他父节点的右子节点，沿着父节点一直向上遍历，
 *         直到父节点是一个结点的左子结点，那么这个结点就是下一个结点，如果直到父节点是根节点，那么就没有下一个节点了。
 */
namespace NextNodeInBinaryTrees{
    BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
        if (!pNode)
            return nullptr;
        BinaryTreeNode* pNext = nullptr;
        if (pNode->m_pRight){
            pNext = pNode->m_pRight;
            while (pNext->m_pLeft)
            {
                pNext = pNext->m_pLeft;
            }
            return pNext;
        }
        else {
            if (pNode->m_pParent->m_pLeft == pNode)
                return pNode->m_pParent;
            else{
                BinaryTreeNode* current = pNode;
                BinaryTreeNode* parent = pNode->m_pParent;
                while (parent!=nullptr && parent->m_pParent && parent->m_pParent->m_pLeft == parent)
                {
                    current = parent;
                    parent = parent->m_pParent;
                }
                return parent;
            }
        }
        return nullptr;
    }
}

/**
 * @name: 面试题9.用两个栈实现队列 （简单题）
 */
namespace QueueByStack{
    template<typename T>
    class Queue{
    public:
        Queue(void){}
        ~Queue(void){}
        
        void appendTail(const T& node){
            stk1.push(node);
        }
        void deleteHead(){
            while (!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
            T head = stk2.pop();
            while (!stk2.empty())
            {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
    private:
        std::stack<T> stk1; //栈顶是队尾
        std::stack<T> stk2; //栈顶是队首
    };
}

/**
 * @name: 面试题10.斐波那契数列
 * @msg: 输入n，求斐波那契（Fibonacci）数列的第n项，有三种解法：
 *          （1）简单递归，return (n) = f(n-1) + f(n-2);效率低，时间复杂度是O(n^2);
 *          （2）动态规划，自下而上，记录f(1),f(2),f(3).....f(n);
 *          （3）数学方法，矩阵{1 1;1 0}^(n-1)。
 */
namespace Fibonacci{
    int Fibonacci(int number){
        if (number == 0) return 0;
        if (number<=2) return 1;
        int f1 =  1;
        int f2 = 1;
        vector<int> dp(number, 0);
        dp[0] = f1;
        dp[1] = f2;
        for (int i = 2; i<number; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp.back();
    }
}

namespace MinNumberInRotatedArray{
    int findMinInRotatedArray_1(vector<int> &input){
        if (input.size()==0) return -1;
        std::sort(input.begin(), input.end());
        return input[0];
    }
    
    int findMinInRotatedArray_2(vector<int> &input){
       
        int i = 0;
        int j = input.size()-1;
        int mid = (i+j)>>1; 
         if (input[i]<input[j]) return input[i];
        while(i<j){
            if(input[i] == input[j] && input[i] == input[mid])
                return findMinInRotatedArray_1(input);
            if (j-i==1){
                return input[j];
            }
            if(input[mid]>input[i]){
                i = mid;
                mid = (i+j)>>1;
            }
            else if (input[mid]<input[j]){
                j = mid;
                mid = (i+j)>>1;
            }
            
        } 
        return  input[0];
    }
}

/**
 * @name: 面试题12.矩阵中的路径
 * @msg: 主要是要理解DFS最大深度遍历，这种棋盘式的遍历有四个方向，有一个对应的置为向量来提示这个点位有没有走过。
 * 格式：
 *      void dfs(int step)
        {
                判断边界
                {
                    相应操作
                }
                尝试每一种可能
                {
                    满足check条件
                    标记
                    继续下一步dfs(step+1)
                    恢复初始状态（回溯的时候要用到）
                }
        }
 */
namespace StringPathInMatrix{

    int direction[4][2] = {
        {0,1},  //right
        {0,-1},  //left
        {-1,0},  //up
        {1,0}   //down
    };
    bool help(std::vector<std::vector<char> >& matrix, string& input, int num, int x, int y, std::vector<std::vector<bool> >& flag){
        if (input.size() == num) return true;
        int Nx;
        int Ny;
        bool is;
        for ( int k = 0; k<4; k++){
            Nx = x + direction[k][0];
            Ny = y + direction[k][1];
            if (Nx>=matrix.size() || Nx < 0 || Ny >= matrix[0].size() || Ny < 0){
                continue;
            }
            if (matrix[Nx][Ny] == input[num]){
                flag[Nx][Ny] == true;
                is = is || help(matrix, input, num+1, Nx, Ny, flag);
                flag[Nx][Ny] == false;
            }
        }
        return is;
    }  
    bool StringPathInMatrix(std::vector<std::vector<char> >& matrix, string& input){
        if (matrix.size() == 0) return false;
        bool ans = false;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j]!=input.at(0)) continue;
                std::vector<std::vector<bool> > flag(matrix.size(), std::vector<bool>(matrix[0].size(), false));
                flag[i][j] = true;
                if (help(matrix, input, 1, i, j, flag))
                    return true;
            }
        }
        return false;
    }
    
    void PermutationDFS(vector<int>& ans, vector<bool> &flag, int step, int n);
    void Permutation(int n){
        vector<bool> flag(n, false);
        vector<int> ans(n, 0);
        PermutationDFS(ans, flag, 0, n);
    }
    void PermutationDFS(vector<int>& ans, vector<bool> &flag, int step, int n){

        if(step>=n){
            for (auto& a:ans)
                cout << a << '\t';
            cout << endl;
            return;
        }
        for(int i = 1; i<=n; i++){
            if (!flag[i-1]){
                ans[step] = i;
                flag[i-1] = true;
                PermutationDFS(ans, flag, step+1, n);
                flag[i-1] = false;
            }
        }
    }
}

/**
 * @name: 面试题13.机器人的运动范围
 * @msg: BFS广度优先搜索，通过队列实现
 * 格式：
 *      while(!q.empty()){bfs(q);}
 *      void bfs(queue<T> q)
        {
            q.pop();       
            尝试每一种可能
            {
                满足check条件
                标记
                q.push();
            }
        }
 */
namespace RobotMove{
    int direction[4][2] = {
        {0,1},  //right
        {0,-1},  //left
        {-1,0},  //up
        {1,0}   //down
    };

    int getDigitSum(int x, int y);
    void movingCountCore(int& res, vector<vector<bool>>& flag, int m, int n, int t, queue<pair<int,int>>& pos);
    int RobotMove(int m, int n, int threshold){
        if(threshold < 0 || m <= 0 || n <= 0)
            return 0;
        
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        queue<pair<int,int>> pos;
        pos.push(pair<int,int>(0,0));
        flag[0][0] = true;

        int result = 1;
        while(!pos.empty()){
            
            
            movingCountCore(result, flag, m, n, threshold, pos);
                
            
        }
        return result;
    }
    void movingCountCore(int& res, vector<vector<bool>>& flag, int m, int n, int t, queue<pair<int,int>>& pos){
        
        int Nm, Nn;
        int tempX = pos.front().first;
        int tempY = pos.front().second;
        pos.pop();
        for (int k = 0; k < 4; k++){
            Nm = tempX + direction[k][0];
            Nn = tempY + direction[k][1];
            if (Nm < 0 || Nn < 0 || Nm>=m || Nn>=n){
                continue;
            }
            if(!flag[Nm][Nn] ){
                pos.push(pair<int,int>(Nm,Nn));
                flag[Nm][Nn] = true;
                if (getDigitSum(Nn,Nm)<=t) res++;
                //movingCountCore(res, flag,  m, n, t, pos);
            }
        }
    }
    int getDigitSum(int x, int y){
        int count = 0;
        while(x){
            count += x%10;
            x/=10;
        }
        while(y){
            count += y%10;
            y/=10;
        }
        return count;
    }
}

/**
 * @name: 面试题14.剪绳子
 * @msg: 方法一是动态规划，自下而上，分析状态方程：f(n) = max{f(i)-f(n-i)} , 其中i属于(1,n-1)。
 *       方法二是贪婪算法，求积最大，就将整数拆分成大量的3和少量的2. 
 * @param {type} 
 * @return: 
 */
namespace CuttingRope{
    int maxProductAfterCutting_solution1(int n){
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n == 3) return 2;

        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i = 4; i<=n; ++i){
            int max = 0;
            for (int j = 1; j < 4; j++){
                int temp = dp[j]*dp[i-j];
                if (max < temp)
                    max = temp;
            }
            dp[i] = max;
        }

        return dp.back();
    }

    int maxProductAfterCutting_solution2(int n){
        if (n < 2) return 0;
        if (n == 2) return 1;
        if (n == 3) return 2;

        // 尽可能多地减去长度为3的绳子段
        int timesOf3 = n / 3;

        // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
        // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
        if(n - timesOf3 * 3 == 1)
            timesOf3 -= 1;

        int timesOf2 = (n - timesOf3 * 3) / 2;

        return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));
    }
}

/**
 * @name: 面试题15.二进制中1的个数
 * @msg: （1）考虑到负数是补码且最左边高位是符号位，向右移位是添加数字1，所以考虑将flag = 1，向左移位，比较数字的每一位
 *       （2）一个数n,n&(n-1)即可将最右边的1置0，循环执行可将所有的1置0.
 */
namespace NumberOf1InBinary{
    int NumberOf1_Solution1(int n){
        int count = 0;
        unsigned int flag = 1;
        while(n){
            if (n & flag) count++;
            flag = flag << 1;
        }
        return count;
    }

    int NumberOf1_Solution2(int n){
        int count;
        while (n) {
            n = n&(n-1);
            count ++;
        }
        return count;
    }

    // 相关题目1 判断一个整数是不是2的整数次方  2 = 0000 0010 | 4 = 0000 0100 | 16 = 0001 0000
    // 所以2的次方中其二进制数只有一位是1
    bool JudgeNumberIsCube(int n){
        if ((n&(n-1))) return false;
        return true;
    }
}

/**
 * @name: 面试题16.数值的整数次方
 * @msg: 要考虑次方是负数，底数是0的情况，除法可以用>>1来表示，奇数可以用（n&0x1==1）来表示。
 */
namespace Power{
    double PowerWithUnsignedExponent(double base, unsigned int exponent);
    bool equal(double num1, double num2)
    {
        if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
            return true;
        else
            return false;
    }
    double Power(double base, int exponent){
        if (exponent<0 && equal(base, 0.0))  // 浮点数是否为0，不能直接和0.0比较，要做差值和一个极小数比较
            return 0; //无效输入
        unsigned int tempExponent;
        if (exponent<0)
            tempExponent =  (unsigned int)(-exponent);
        else   
            tempExponent = (unsigned int)exponent;
        
        double res = PowerWithUnsignedExponent(base, tempExponent);
        if (exponent<0)
            return 1.0/res;
        return res;
                
    }
    
    double PowerWithUnsignedExponent(double base, unsigned int exponent)
    {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;

        double result = PowerWithUnsignedExponent(base, exponent >> 1);
        result *= result;
        if ((exponent & 0x1) == 1)
            result *= base;

        return result;
    }
}

/**
 * @name: 面试题17.打印从1到最大的n位数
 * @msg: 考虑大树问题，其次是要考虑赋值方式，这里用到DFS全排列。
 */
namespace Print1ToMaxOfNDigitsRecursively{
    void PrintNumberDFS(string& str, vector<bool>& flag, int step, int n);
    void PrintNumber(int n){
        if (n <= 0) return;
        string str(n,'0');
        vector<bool> flag(n, false);
        PrintNumberDFS(str, flag, 0, n);
    }

    void PrintNumberDFS(string& str, vector<bool>& flag, int step, int n){
        if (step>=n){
            int ZeroFlag = true;
            for (int k = 0; k<n; k++){
                if (str[k] == '0' && ZeroFlag){
                    if (k == n-1)
                        cout << int(0);
                    continue;
                }
                ZeroFlag = false;
                cout << str[k];
            }
            cout << endl;
            return;
        } 
        for (int j = 0; j<n; j++){
            if (!flag[j]){
                flag[j] = true;
                for(int i = 0; i<10; i++){
                        str[step] = i+'0';
                        PrintNumberDFS(str, flag, step+1, n);
                }
                flag[j] = false;
            }
        }
    }
}

/**
 * @name: 面试题18.（1）删除链表的指定结点 （2）删除链表中重复的结点
 * @msg: （1）要考虑三种情况，当前结点为一般节点，为尾结点，或链表只有一个结点
 *       （2）初始化一个参考值，如果链表下一个元素不为空，且数值不重复，移位下一个结点，如果下一个结点为空，那么结束，下一个不为空，下一个结点删除
 */
namespace DeleteListNode{
    void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
        if ((!pListHead) || (!pToBeDeleted))
            return;
        if(pToBeDeleted->m_pNext){
            ListNode* pNext = pToBeDeleted->m_pNext;
            pToBeDeleted->m_nKey = pNext->m_nKey;
            pToBeDeleted->m_pNext = pNext->m_pNext;
            delete pNext; 
        }
        // 链表只有一个结点，删除头结点（也是尾结点）
        else if(*pListHead == pToBeDeleted)
        {
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
            *pListHead = nullptr;
        }
        // 链表中有多个结点，删除尾结点
        else
        {
            ListNode* pNode = *pListHead;
            while(pNode->m_pNext != pToBeDeleted)
            {
                pNode = pNode->m_pNext;            
            }
    
            pNode->m_pNext = nullptr;
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }
    // 三指针法，
    void DeleteDuplication(ListNode** pHead){
        if(pHead == nullptr || *pHead == nullptr)
            return;
        ListNode* pPreNode = nullptr;
        ListNode *pNext = nullptr;
        ListNode* pNode = *pHead;
        if (pNode){
            pNext = pNode->m_pNext;
            bool needDelete = false;
            if (pNext!=nullptr && pNode->m_nKey == pNext->m_nKey)
                needDelete = true;
            if (!needDelete){
                pPreNode = pNode;
                pNode = pNext;
            }
            else{
                int value = pNode->m_nKey;
                ListNode* NeedDeleteNode = pNode;
                while (NeedDeleteNode && NeedDeleteNode->m_nKey == value){
                    pNext = NeedDeleteNode->m_pNext;
                    delete NeedDeleteNode;
                    NeedDeleteNode = nullptr;
                    NeedDeleteNode = pNext;
                }
                if (pPreNode == nullptr){
                    *pHead = pNext; 
                }
                else{
                    pPreNode->m_pNext = pNext;
                }
                pNode = pNext;
            }
        }
    }
}

/**
 * @name: 面试题19.正则表达式匹配
 * @msg: 用递归实现有限状态机
 * @param {type} 
 * @return: 
 */
namespace RegularExpressions{

    string::iterator str_end;
    string::iterator pattern_end;
    bool matchCore(string::iterator str, string::iterator pattern);

    bool match(string str, string pattern){
        if (str.size() == 0 || pattern.size() == 0)
            return false;
        
        auto itr_str = str.begin();
        auto itr_pattern = pattern.begin();
        str_end = str.end();
        pattern_end = pattern.end();
        
        return matchCore(itr_str, itr_pattern);
    }
    
    bool matchCore(string::iterator str, string::iterator pattern){
        if (str == str_end && pattern == pattern_end)
            return true;
        if (str != str_end && pattern == pattern_end)
            return false;
        if (*(pattern+1) == '*'){
            if (*str == *pattern || (*pattern == '.' && str != str_end)){
                return matchCore(str+1, pattern) || matchCore(str+1, pattern+2) || matchCore(str, pattern+2);
            }
            else{
                return matchCore(str, pattern+2);
            }
        }
        
        if (*str == *pattern|| (*pattern=='.'&& str!=str_end)){
            return matchCore(str+1, pattern+1);
        }
    }
    // 状态表示：dp[i][j]代表s的前i个字符和p的前j个字符是否匹配。
    bool matchDP(string s, string p){
        int n = s.length(), m = p.length();
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true; // s、p为空字符
        for (int i = 1; i<=m; i++){
            if (p[i-1] == '*' && dp[0][i-2]){
                dp[0][i] = true;
            }
        }
        for (int i = 1; i<=n; i++){
            for (int j = 1; j<=m; j++){
                if (s[i-1] == p[j-1] || p[j-1] == '.'){
                    // 第i个字符匹配
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*'){
                    if (s[i-1] != p[j-2] && p[j-2] != '.'){
                        // '~*'匹配空
                        dp[i][j] = dp[i][j-2];
                    }
                    else{
                        // '~*'匹配
                        dp[i][j] = dp[i][j-2] || dp[i-1][j] || dp[i][j-1];
                    }
                }
            }
        }
        return dp[n][m];
    }
}

/**
 * @name: 面试题20.表示数值的字符串
 * @msg: 首先A[.[B]][e|EC] 或者 .[B][e|EC] 形式，
 *         首先A和C都是含有符号位的数，B是不含符号位数
 *         根据指针位置变化，如果是符合要求的数字就+1，特殊情况时首位位点的，i不变的情况下看是不会点
 * @param {type} 
 * @return: 
 */
namespace NumericStrings{

    bool isInteger(string &str, int &i);
    bool isUnsignedInteger(string &str, int &i);

    bool isNumeric(string &str){
        if (str.size() == 0) 
            return false;
        int i = 0;
        bool result = isInteger(str, i);

        if (str[i] == '.'){
            i++;
            result = result || isUnsignedInteger(str, i);
        }

        if (str[i] == 'e' || str[i] == 'E'){
            i++;
            
            result = result && isInteger(str, i);
        }
        return result && i==str.size();
    }

    bool isInteger(string &str, int &i){
        if (str[i] == '+' || str[i] == '-')
            ++i;
        return isUnsignedInteger(str, i);
    }
    bool isUnsignedInteger(string &str, int &i){
        int start = i;
        while(i<str.size() && str[i]>0+'0' && str[i]< 9+'0')
            ++i;
        return i!=start?true:false;
    }
}

/**
 * @name: 面试题21.调整数组顺序使奇数位于偶数前面
 * @msg: 双指针 一个位于数组begin，一个位于数组末尾，首部的指针遇到奇数+1，尾部的指针遇到偶数-1，然后交换两个指针所指的内容
 */
namespace ReorderArray{
    bool isEven(int n);
    void ReorderOddEven_1(vector<int> &input){
        if (input.size() == 0) return ;
        int i = 0, j = input.size()-1;
        while(i<j){
            if (!isEven(input[i]) && isEven(input[j]))
            {
                i++; j--;
            }
            else if (!isEven(input[i]) && !isEven(input[j])){
                i++;
            }
            else if (isEven(input[i]) && !isEven(input[j])){
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
                i++;j--;
            }
            else{
                j--;
            }
        }
    }

    bool isEven(int n)
    {
        return (n & 1) == 0;
    }
}

/**
 * @name: 面试题22.链表中倒数第k个结点
 * @msg: 考虑问题要全面：
 *          1.输入链表是否有效，输入k是否有效
 *          2.如果k大于链表长度需要不做处理，即初始化的nullptr结点输出
 *          3.考虑特殊情况和初始条件
 */
namespace KthNodeFromEnd{
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
        if (!pListHead || k==0) return nullptr;
        ListNode* pKthNode = nullptr;
        ListNode* backNode = pListHead;
        unsigned int i = 2;
        if (k==1) pKthNode = pListHead;
        while(backNode->m_pNext){

            backNode = backNode->m_pNext;
            if (i<k){
                i++;
            }
            else if (i == k){
                pKthNode = pListHead;
                i++;
            }
            else{
                pKthNode = pKthNode->m_pNext;
            }
        }
        return pKthNode;
    }
}

/**
 * @name: 面试题23.链表中环的入口结点 (考虑链表中有重复结点)
 * @msg: 1.确定链表中存在环，两个快慢指针，在环中相遇，标记相遇的结点
 *       2.确定环中包含的结点数，通过1中相遇的结点，计数自增，再次到这个结点时，就是环的大小
 *       3.双指针，一个指针先移动结点数次数，然后两个指针按照相同的方向+1，相遇时则是入口结点
 * @param {type} 
 * @return: 
 */
namespace EntryNodeInListLoop{
    ListNode* MeetingNode(ListNode* pHead){
        if (!pHead) return nullptr;
        ListNode* Fast = pHead->m_pNext;
        if (!Fast||!Fast->m_pNext) return nullptr;
        ListNode* Slow = pHead;
        while (Fast != Slow){
            Fast = Fast->m_pNext;
            if (!Fast||!Fast->m_pNext) return nullptr;
            Fast = Fast->m_pNext;
            Slow = Slow->m_pNext;
        }
        ListNode* NodeInLoop = Fast->m_pNext;
        int count = 1;
        while(NodeInLoop != Fast){
            count++;
            NodeInLoop = NodeInLoop->m_pNext;
        }

        Fast = pHead; Slow = pHead;
        for (int i = 0; i<count; i++){
            Fast = Fast->m_pNext;
        }
        while (Fast!=Slow)
        {
            Fast = Fast->m_pNext;
            Slow = Slow->m_pNext;
        }
        return Fast;
    }
}

/**
 * @name: 面试题24.反转链表
 * @msg: 通过画一张反转前和反转后的对比图，利用三个指针（当前结点，前一个结点、后一个结点），当前结点在另外两个结点之间来回切换。
 *       最后下一个结点为空时，即到了反转链表的最后位置。
 *       1.pNext记录下一个结点
 *       2.pNode是当前需要修改的结点pNode->next指向pPre
 *       3.pPre更新为当前结点，pNode更新为pNext
 */
namespace ReverseList{
    ListNode* ReverseList(ListNode* pHead){
        ListNode* pNode = pHead;
        ListNode* pPre  = nullptr;
        ListNode* ans = nullptr;        
        while (pNode){
            ListNode* pNext = pNode->m_pNext;
            if (pNext == nullptr)
                ans = pNode;
            pNode->m_pNext = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        return ans;
    }
}

/**
 * @name: 面试题25.合并两个排序的链表
 * @msg: 递归实现
 */
namespace MergeSortedLists{
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == nullptr)
            return pHead2;
        else if(pHead2 == nullptr)
            return pHead1;
        
        ListNode* pMergedHead = nullptr;
        if(pHead1->m_pNext < pHead2->m_pNext)
        {
            pMergedHead = pHead1;
            pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
        }
        else
        {
            pMergedHead = pHead2;
            pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
        }

        return pMergedHead;

    }
}

/**
 * @name: 面试题26.树的子结构
 * @msg: （1）树的遍历
 *       （2）比较这两个子树是否相同 又是一个遍历
 *       （3）和树的遍历相关的就是递归
 */
namespace SubstructureInTree{
    bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
    bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
        bool result = false;
        if(pRoot1 && pRoot2){
            if (pRoot1->value == pRoot2->value)
                result = DoesTree1HaveTree2(pRoot1, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->m_pLeft, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->m_pRight, pRoot2);;
        }
        return result;
    }
    bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
        if (!pRoot2)
            return true;
        if (!pRoot1)
            return false;
        if (pRoot1->value == pRoot2->value)
            return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) 
                && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
        else 
            return false;
    }
}

/**
 * @name: 面试题27.二叉树的镜像
 * @msg: （1）用递归的方式中序遍历每个结点，并且将左右子树交换，就是对指针的操作
 *       （2）用循环的方式层次遍历，用栈和队列应该都可以，也是类似（1）将每个结点的左右子树交换
 */
namespace MirrorOfBinaryTree{
    void MirrorRecursively(BinaryTreeNode *pNode){
        if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
            return;
        BinaryTreeNode* temp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = temp;

        if (pNode->m_pLeft)
            MirrorRecursively(pNode->m_pLeft);
        if (pNode->m_pRight)
            MirrorRecursively(pNode->m_pRight);
    }
    
    void MirrorIteratively(BinaryTreeNode* pNode){
        if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
            return;
        stack<BinaryTreeNode*> stk;
        stk.push(pNode);
        while (!stk.empty()){
            BinaryTreeNode* pNode = stk.top();
            stk.pop();
            if (pNode->m_pLeft)
                stk.push(pNode->m_pLeft);
            if (pNode->m_pRight)
                stk.push(pNode->m_pRight);
            BinaryTreeNode* temp = pNode->m_pLeft;
            pNode->m_pLeft = pNode->m_pRight;
            pNode->m_pRight = temp;
        }
    }
}

/**
 * @name: 面试题28.对称的二叉树
 * @msg: 考察二叉树的遍历，中序遍历中先结点然后左右子树，那么如果对称的话，就一个左右 一个右左
 */
namespace SymmetricalBinaryTree{
    bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

    bool isSymmetrical(BinaryTreeNode* pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }

    bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
        if (pRoot1 == nullptr && pRoot2 == nullptr)
            return true;
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        if (pRoot1->value!=pRoot2->value)
            return false;
        
        return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)   //pRoot1是左右中序遍历
            && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);  //pRoot2是右左中序遍历
    }
}

/**
 * @name: 面试题29.顺时针打印矩阵
 * @msg: 找规律，分层分析，将问题拆解
 */
namespace PrintMatrix{
    void PrintMatrixInCircle(vector<vector<int>> &matrix, int m);
    void PrintMatrixClockwisely(vector<vector<int>>& matrix){
        if (matrix.size() == 0) return;

        int columns = matrix[0].size(),  rows = matrix.size();
        int start = 0;
        while(columns > start * 2 && rows > start * 2)
        {
            PrintMatrixInCircle(matrix, start);

            ++start;
        }
            
    }
    void printNumber(int number)
    {
        printf("%d\t", number);
    }
    void PrintMatrixInCircle(vector<vector<int>> &numbers, int start){
        int endX = numbers[0].size() - 1 - start;
        int endY = numbers.size() - 1 - start;

        // 从左到右打印一行
        for(int i = start; i <= endX; ++i)
        {
            int number = numbers[start][i];
            printNumber(number);
        }

        // 从上到下打印一列
        if(start < endY)
        {
            for(int i = start + 1; i <= endY; ++i)
            {
                int number = numbers[i][endX];
                printNumber(number);
            }
        }

        // 从右到左打印一行
        if(start < endX && start < endY)
        {
            for(int i = endX - 1; i >= start; --i)
            {
                int number = numbers[endY][i];
                printNumber(number);
            }
        }

        // 从下到上打印一行
        if(start < endX && start < endY - 1)
        {
            for(int i = endY - 1; i >= start + 1; --i)
            {
                int number = numbers[i][start];
                printNumber(number);
            }
        }
    }
}

/**
 * @name: 面试题30.包含min函数的栈
 * @msg: 利用辅助栈思维 将最小值保存在辅助栈中 辅助栈的大小和原来的栈相同
 */
namespace StackWithMin{
    template <typename T> class StackWithMin
    {
    public:
        StackWithMin() {}
        virtual ~StackWithMin() {}

        T& top();
        const T& top() const;

        void push(const T& value);
        void pop();

        const T& min() const;

        bool empty() const;
        size_t size() const;

    private:
        std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
        std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
    };
    
    template <typename T> 
    T& StackWithMin<T>::top(){
        return m_data.top();
    }

    template <typename T>
    const T& StackWithMin<T>::top() const{
        return m_data.top();
    }

    template <typename T>
    const T& StackWithMin<T>::min() const{
        assert(m_data.size() > 0 && m_min.size() > 0);
        return m_min.top();
    }
        
    template <typename T>
    void StackWithMin<T>::push(const T& value){
        m_data.push(value);
        if (m_min.empty())
            m_min.push(value);
        else{
            if (m_min.top() > value)
                m_min.push(value);
            else
                m_min.push(m_min.top());
        }
    }
    template <typename T>
    void StackWithMin<T>::pop(){
        assert(m_data.size() > 0 && m_min.size() > 0);
         m_data.pop();
        m_min.pop();
    }

    template <typename T> bool StackWithMin<T>::empty() const
    {
        return m_data.empty();
    }

    template <typename T> size_t StackWithMin<T>::size() const
    {
        return m_data.size();
    }
}

/**
 * @name: 面试题31.栈的压入、弹出序列
 * @msg: 模拟入栈和出栈过程 通过一个辅助栈 来比较栈顶元素和出栈序列之间的关系
 */
namespace StackPushPopOrder{
    bool IsPopOrder(const vector<int> &pPush, const vector<int>& pPop){
        if (pPop.empty() || pPush.empty())
            return false;
        auto itr_push = pPush.begin();
        auto itr_pop  = pPop.begin();

        stack<int> stk;
        
        while(itr_push!=pPush.end()){
            if (stk.empty() || stk.top()!=*itr_pop){
                stk.push(*itr_push);
                itr_push++;
                continue;
            }
            while (stk.top()==*itr_pop){
                itr_pop++;
                stk.pop();
            }
        }
        while(!stk.empty() && itr_pop!=pPop.end()){
            if(stk.top() == *itr_pop){
                stk.pop();itr_pop++;
            }
            else 
                return false;
        }
        if (stk.empty() && itr_pop==pPop.end())
            return true;
        return false;
        
    }
}

/**
 * @name: 面试题32.三种层序遍历
 * @msg: 熟练使用栈和队列，满足题目要求
 *          （1）直接输出层序遍历结构，用队列即可
 *          （2）分层输出层序遍历结果，用两个数值记录当前层数总共的结点和当前层剩余结点
 *          （3）之字形打印，要用两个栈，一个栈存储正序，一个存储逆序
 */
namespace PrintTreeLevel{
    void PrintFromTopToBottom(BinaryTreeNode* pRoot){
        if (!pRoot) return;
        queue<BinaryTreeNode*> queueTreeNode;
        queueTreeNode.push(pRoot);
        while (!queueTreeNode.empty())
        {   
            BinaryTreeNode* pNode = queueTreeNode.front();
            queueTreeNode.pop();
            printf("%d", pNode->value);
            if (pNode->m_pLeft)
                queueTreeNode.push(pNode->m_pLeft);
            if (pNode->m_pRight)
                queueTreeNode.push(pNode->m_pRight);
        }
    }
    void PrintTreesInLines(BinaryTreeNode* pRoot){
        if (!pRoot) return;
        queue<BinaryTreeNode*> queueTreeNode;
        queueTreeNode.push(pRoot);
        
        int levelCount = 0;
        int elementInEachLevel = 1;
        while (!queueTreeNode.empty())
        {   
            BinaryTreeNode* pNode = queueTreeNode.front();
            queueTreeNode.pop();
            printf("%d", pNode->value);
            if (pNode->m_pLeft){
                queueTreeNode.push(pNode->m_pLeft);
                levelCount++;
            }
            if (pNode->m_pRight){
                queueTreeNode.push(pNode->m_pRight);
                levelCount++;
            }
                
            elementInEachLevel--;
            if (elementInEachLevel == 0){
                printf("\n");
                elementInEachLevel = levelCount;
                levelCount = 0;
            }
        }
    }

    
    void PrintTreesInZigzag(BinaryTreeNode* pRoot){
         if (!pRoot)
            return ;
        stack<BinaryTreeNode*> stk[2];
        int current = 0;
        int next = 1;
        stk[current].push(pRoot);
        while (!stk[1].empty() || !stk[2].empty()){
            BinaryTreeNode* pNode = stk[current].top();
            stk[current].pop();
            printf("%d", pNode->value);
            if (current){
                if(pNode->m_pLeft != nullptr)
                    stk[next].push(pNode->m_pLeft);
                if(pNode->m_pRight != nullptr)
                    stk[next].push(pNode->m_pRight);
            }
            else{
                if(pNode->m_pRight != nullptr)
                    stk[next].push(pNode->m_pRight);
                if(pNode->m_pLeft != nullptr)
                    stk[next].push(pNode->m_pLeft);
            }
            if (stk[current].empty()){
                printf("\n");
                current = 1-current;
                next = 1-next;
            }
        }
    }
}

/**
 * @name: 面试题33.二叉搜索树的后序遍历序列
 * @msg: 后序遍历最后一个元素是根节点，前面i个是左子树，剩下的是右子树，左子树比根节点小，右子树相反。
 */
namespace SquenceOfBST{
    bool VerifySquenceOfBST(vector<int>& sequence){
        if (sequence.empty())
            return false;
        int length = sequence.size();
        int root = sequence[length-1];
        int i = 0;
        for (; i<length-1; ++i){
            if (sequence[i]>root)
                break;
        }
        int j = i;
        for (; j<length-1; ++j){
            if (sequence[j]<root)
                return false;
        }
        bool left = true;
        if (i>0){
            auto temp = vector<int>(&sequence[0], &sequence[i]);
            left = VerifySquenceOfBST(temp);
        }
        bool right =true;
        if (i<length-1){
            auto temp = vector<int>(&sequence[i], &sequence[length-1]);
            right = VerifySquenceOfBST(temp);
        }
        return left&&right;
    }
}

/**
 * @name: 面试题34.二叉树中和为某一值的路径
 * @msg: 利用二叉树遍历的思想 逐个遍历，计算数值
 */
namespace PathInTree{
    void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int> pathNode);
    void FindPath(BinaryTreeNode* pRoot, int expectedSum){
        if (!pRoot)
            return ;
        vector<int> pathNode;
        FindPath(pRoot, expectedSum, pathNode);
    }
    void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int> pathNode){
        
        pathNode.push_back(pRoot->value);
        int Sum = 0;
        Sum = accumulate(pathNode.begin(), pathNode.end(), 0);
        if (Sum == expectedSum){
            for (auto s:pathNode){
                printf("%d\t", s);
            }
            printf("\n");
        }
        if (pRoot->m_pLeft)
            FindPath(pRoot->m_pLeft, expectedSum, pathNode);
        if (pRoot->m_pRight)
            FindPath(pRoot->m_pRight, expectedSum, pathNode);
        pathNode.pop_back();
    }
}

/**
 * @name: 面试题35.复杂链表的复制
 * @msg: 深拷贝 指针所指空间是不一样的两个内存地址，所以需要new一个新的空间
 *      这里用了map来存储这两个相同的指针
 *      还有另外一种方法，将链表重新练一遍，然后pNode->m_pSibling->next = pClone->m_pSibling
 */
namespace CopyComplexList{
    
    ComplexListNode* Clone(ComplexListNode* pHead){
        ComplexListNode* pNode = pHead;
        map<ComplexListNode*, ComplexListNode*> container;
        while(pNode){
            ComplexListNode* pClone = new ComplexListNode();
            pClone->m_nValue = pNode->m_nValue;
            pClone->m_pNext = nullptr;
            container[pNode] = pClone;
            //container.insert(pair<ComplexListNode*, ComplexListNode*>(pNode, pClone));
            
            pNode = pNode->m_pNext;
        }
        for (auto itr = container.begin(); itr!=container.end(); itr++){
            itr->second->m_pNext = container[itr->first->m_pNext];
            itr->second->m_pSibling = container[itr->first->m_pSibling];
        }
        return container[pHead];
    }
}

/**
 * @name: 面试题36.二叉搜索树与双向链表
 * @msg: 排序链表： 节点应从小到大排序，因此应使用 中序遍历 “从小到大”访问树的节点；
         双向链表： 在构建相邻节点（设前驱节点 prepre ，当前节点 curcur ）关系时，不仅应 pre.right = curpre.right=cur ，也应 cur.left = precur.left=pre 。
         循环链表： 设链表头节点 headhead 和尾节点 tailtail ，则应构建 head.left = tailhead.left=tail 和 tail.right = headtail.right=head 。
 */
namespace ConvertBinarySearchTree{
    BinaryTreeNode* pre, *head;
    void ConvertNode(BinaryTreeNode* pNode);

    BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
        if(pRootOfTree == nullptr)
            return nullptr;
        ConvertNode(pRootOfTree);
        pre->m_pRight = head;
        head->m_pLeft = pre;
        return head;
    }

    void ConvertNode(BinaryTreeNode* pNode){
        if(pNode == nullptr)
            return;

        BinaryTreeNode *pCurrent = pNode;

        if (pCurrent->m_pLeft != nullptr)
            ConvertNode(pCurrent->m_pLeft);

        if (pre == nullptr) head = pCurrent;
        else pre->m_pRight = pCurrent;

        pCurrent->m_pLeft = pre;

        if (pCurrent->m_pRight != nullptr)
            ConvertNode(pCurrent->m_pRight);
    }
}


/**
 * @name: 面试题37.序列化二叉树
 * @msg: 序列化直接用前序遍历到叶子节点，并且是叶子节点的左右结点也要遍历，所以判断条件是在递归里的，而不是递归前
 *       反序列化 首先要将序列按照流的形式读入，其实队列也可以，总之实现也是递归，递归里面要往下移位，遇到左右结点$这个就不操作，然后递归就会回答上一层根节点
 */
namespace SerializeBinaryTrees{
    void Serialize(const BinaryTreeNode* pRoot, ostream& stream){
        if (!pRoot){
            stream << "$,";
            return ;
        }
        stream << pRoot->value << ",";
        Serialize(pRoot->m_pLeft, stream);
        Serialize(pRoot->m_pRight, stream);
    }
    bool ReadStream(istream& stream, int* number){
        if (stream.eof())
            return false;
        char buf[32];
        buf[0] = '\0';

        char ch;
        stream >> ch;
        int i = 0;       
        while (!stream.eof() && ch!='$'){
            buf[i++] = ch;
            stream >> ch;
        }
        bool isNumeric = false;
        if (i>0 && buf[0]!='$'){
            *number = atoi(buf);
            isNumeric = true;
        }
        return isNumeric;
    }
    void Deserialize(BinaryTreeNode** pRoot, istream& stream){
        int number;
        if (ReadStream(stream, &number)){
            *pRoot = new BinaryTreeNode();
            (*pRoot)->value = number;
            (*pRoot)->m_pLeft = nullptr;
            (*pRoot)->m_pRight = nullptr;
            Deserialize(&((*pRoot)->m_pLeft), stream);
            Deserialize(&((*pRoot)->m_pRight), stream);
        }
    }
}

/**
 * @name: 面试题38.字符串的排列
 * @msg: DFS 全遍历 将字符串分成两部分 不同于全排列 通过交换 并且将字符串分为交换部分和为交换部分
 * @param {type} 
 * @return: 
 */
namespace StringPermutation{
    void Permutation(string& str, int i);
    bool isSwap(string& str, int i, int j){
        for (; i<j; i++){
            if (str[i] == str[j])
                return false;
        }
        return true;
    }
    void Permutation(string& str){
        if (str.empty()) return ;
        Permutation(str, 0);
    }
    void Permutation(string &str, int i){
        
        if (i == str.size()){
            printf("%s\n", str.c_str());
            return ;
        }
        for (int k = i; k<str.size(); ++k){
            if (isSwap(str, i, k)){
                swap(str[i], str[k]);
                Permutation(str, i+1);
                swap(str[i], str[k]);
            }
        }
    }

    //  输入三个字符a、b、c，组合有：a, b, c , ab, ac, bc, abc。
    void Combination(string &str, size_t start, size_t number, vector<char> &result);
    void Combination(string &str){
        if (str.empty())
            return ;
        vector<char> result;
        for (size_t i = 1;i<=str.size(); i++){
            result.clear();
            Combination(str, 0, i, result);
        }
    }
    void Combination(string &str, size_t start, size_t number, vector<char> &result){
        if (number == 0){
            for (auto s:result){
                cout << s;
            }
            cout << endl;
            return ;
        }
        if (start >= str.size()) return;
        result.push_back(str[start]);
        Combination(str, start+1, number-1, result);
        result.pop_back();
        Combination(str, start+1, number, result);
    }
    
    // 正方体对面顶点和相等数组
    bool CubicEqualExist(vector<int> &numbers, int k);
    bool CubicEqualExist(vector<int> &numbers) {
        if (numbers.size()!=8) return false;
        return CubicEqualExist(numbers, 0);
    }
    bool Judge(vector<int>& result){
        if (result[0]+result[1]+result[2]+result[3] == result[4]+result[5]+result[6]+result[7]
            && result[0]+result[2]+result[4]+result[6] == result[1]+result[3]+result[5]+result[7]
            && result[0]+result[1]+result[4]+result[5] == result[2]+result[3]+result[6]+result[7])
            return true;
        return false;
    }
    bool isCubicSwap(vector<int> &numbers, int i, int k){
        for (; i<k; i++){
            if (numbers[i] == numbers[k])
                return false;
        }
        return true;
    }
    bool CubicEqualExist(vector<int> &numbers, int i) {
        if (i == numbers.size()){
            return Judge(numbers);
        }
        bool flag = false;
        for (int k = i; k<numbers.size(); k++){
            if (isCubicSwap(numbers, i, k)){
                swap(numbers[i], numbers[k]);
                flag |= CubicEqualExist(numbers, i+1);
                swap(numbers[i], numbers[k]);
            }
        }
        return flag;
    }
}

/**
 * @name: 面试题39.数组中出现次数超过一半的数字
 * @msg: 设置一个pair数据类型，first用来存元素，second用来计数，遍历过程中元素等于first，second++，
 *       元素不等于first，second--，直到second==0，first设为新元素，并且second=1。直到最后second！=0
 * @param {type} 
 * @return: 
 */
namespace MoreThanHalfNumber{
    bool CheckMoreThanHalf(vector<int>& numbers){
        if (numbers.size() == 0) return false;
        map<int, int> countNumber;
        std::pair<int, int> pMax(numbers[0], 1);
        
        for(int n:numbers){
            if (countNumber.find(n)==countNumber.end()){
                countNumber[n] = 1;
            }
            else{
                countNumber[n]+=1;
            }
            if (pMax.first!=n && pMax.second < countNumber[n]){
                pMax.first = n;
                pMax.second=countNumber[n];
                continue;
            }
            if (pMax.first==n)
                pMax.second = countNumber[n];
        }

        if (pMax.second <= numbers.size()/2)
            return false;
        else{
            printf("超过数组长度的一半的数为：%d", pMax.first);
            return true;
        }
        return false;
    }
}

/**
 * @name: 面试题40.最小的k个数
 * @msg: 两种方法， 一种是分治法Partition，将输入排序
 *                 另一种是另外的一个大小为k的最大堆存储，最大堆用set实现，因为set底层是红黑树
 */
namespace KLeastNumbers{
    template<typename T> int Partition(vector<T> &vec, int i, int j);
    int RandomInRange(int min, int max)
    {
        int random = rand() % (max - min + 1) + min;
        return random;
    }
    vector<int> GetLeastNumbers_Solution1(vector<int> &input, int k){
        if (input.size()<=0 || k<=0) return {};
        // 将数组直接在index==k-1处分开
        int i = 0, j = input.size()-1;
        int index = Partition<int>(input, i, j);
        while (index != k-1){
            if (index<k-1)
               { i = index+1;
                index = Partition<int>(input, i, j);}
            else
                {j = index-1;
                index = Partition<int>(input, i, j);}
        }
        return vector<int>(&input[0], &input[k]);
    }
    template<typename T>
    int Partition(vector<T> &vec, int i, int j){
        int index = RandomInRange(i, j);
        swap(vec[index], vec[j]);
        int small = i-1;
        for (index = i; index < j; index++){
            if (vec[index]<vec[j]){
                ++small;
                swap(vec[small], vec[index]);
            }
        }
        ++small;
        swap(vec[small], vec[j]);
        return small;
    }
    vector<int> GetLeastNumbers_Solution2(vector<int> &input, int k){
        multiset<int, greater<int> > intSet;
        typedef multiset<int, greater<int> >::iterator setIterator;
        vector<int> result;
        auto itr = input.begin();
        for (; itr!=input.end(); ++itr){
            if (intSet.size() < k){
                intSet.insert(*itr);
            }
            else{
                setIterator greatest = intSet.begin();
                if (*greatest > *itr){
                    intSet.erase(greatest);
                    intSet.insert(*itr);
                }
            }
        }
        setIterator itr_set =  intSet.begin();
        for (; itr_set!=intSet.end(); itr_set++){
            result.push_back(*itr_set);
        }
        return result;
    }
}

/**
 * @name: 面试题41.数据流中的中位数
 * @msg: 通过两个最小堆和最大堆，将数据流分成两部分，一部分是最大堆中最大值是中位数的，一个是最小堆中最小值是中位数，满洲最大堆中的数普遍小于最小堆中的数。
 */
namespace StreamMedian{
    template<typename T> class DynamicArray
    {
    public:
        void Insert(T num){
            // 容量为奇数，就将大数填到最小堆，有两种情况，、
            // 1.这个数小于最大堆中的最大值，那么需要将这个数放到最大堆中，并将最大堆中的最大数，放到最小堆中
            // 2.这个数大于最大堆中的最大值，直接放到最小堆中
            if ( (max.size()+min.size()) & 1 == 0){
                if (max.size()>0 && num < max[0]){
                    max.push_back(num);
                    push_heap(max.begin(), max.end(), less<T>());
                    
                    num = max[0];
                    pop_heap(max.begin(), max.end(), less<T>());
                    max.pop_back();
                }
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());
            } 
            // 容量为偶数，就将小数填到最大堆
            // 1.如果这个数大于最小堆中的最小数，那么就要将最小堆中的最小数放到最大堆中，这个数放到最小堆里
            // 2.如歌这个数小于最小堆中的最小数，那直接放到最大堆中
            else{
                if (min.size()>0 && num>min[0])
                {
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<T>());
                    num = min[0];
                    pop_heap(min.begin(), min.end(), greater<T>());
                    min.pop_back();
                }
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());
            }
        }
        
        T GetMedian(){
            int size = min.size() + max.size();
            if(size == 0)
                throw exception("No numbers are available");

            T median = 0;
            if((size & 1) == 1)
                median = min[0];
            else
                median = (min[0] + max[0]) / 2;

            return median;
        }
    
    private:
        vector<T> min;
        vector<T> max;
    };
}

/**
 * @name: 面试题42.连续子数组的最大和
 * @msg: 动态规划 找状态转移方程
 */
namespace GreatestSumOfSubarrays{
    int FindGreatestSumOfSubArray(vector<int>& input){
        if (input.empty())
            return -1;
        // 状态转移方程
        // 1.f(i-1)<0 ---> f(i) = input[i];
        // 2.f(i-1)>0 ---> f(i) = f(i-1) + input[i];
        vector<int> dp(input.size(), 0);
        dp[0] = input[0];
        int i = 1;
        for (; i<input.size(); i++){
            if (dp[i-1]<0)
                dp[i] = input[i];
            else    
                dp[i] = dp[i-1] + input[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
}

/**
 * @name: 面试题43.从1到n整数中1出现的次数
 * @msg: 将数字按位数拆分 递归
 * @param {type} 
 * @return: 
 */
namespace NumberOf1{
    int Number1(string number);
    int NumberOf1Between1AndN(unsigned int n){
        string number = to_string(n);
        return Number1(number);
    }
    int Number1(string number){   
        if (number.size() == 0 || number[0] < '0' || number[0] > '9')
            return 0;
        if (number.size() == 1 && number[0] == '0')
            return 0;
        if (number.size() == 1 && number[0] >= '1')
            return 1;
        int numFirstDigit = 0;
        string nextNumber(&number[1], &number[number.size()]);
        if (number[0]>'1')
            numFirstDigit = pow10(number.size()-1);
        else
            numFirstDigit = atoi(nextNumber.c_str()) + 1;
        
        int numOtherDigits = (number[0] - '0')*(number.size()-1)*pow10(number.size()-2);
        int numRecursive = Number1(nextNumber);

        return numFirstDigit + numOtherDigits + numRecursive;
    }
}

/**
 * @name: 面试题44：数字序列中某一位的数字
 * @msg: 找规律
 */
namespace DigitsInSequence{
    int digitAtIndex(int index){
        if (index < 0) return -1;
        int back = 10;
        int countDig = 1;
        while( index > back ){
                countDig++;
                index -= back;
                back = countDig*pow10(countDig-1)*9;           
        }
        if (countDig == 1)
            return index-1;
        else{
            int start = pow10(countDig-1);
            int count = index/countDig;
            string result = to_string(start+count);
            
            return result[(start+count)%countDig] - '0';
        }
    }
}

/**
 * @name: 面试题45：把数组排成最小的数
 * @msg: 比较mn和nm的大小就可以了
 * @param {type} 
 * @return: 
 */
namespace SortArrayForMinNumber{
    bool Compare_str(const string& s1, const string& s2){
        return s1+s2 < s2+s1;
    }

    void PrintMinNumber(vector<int> &input){
        if (input.size() <=0 ) return ;
        vector<string> vec;
        for (auto &in:input){
            vec.push_back(to_string(in));
        }
        sort(vec.begin(), vec.end(), Compare_str);
        for (auto &a:vec){
            cout<< a;
        }
    }
}

/**
 * @name: 面试题46：把数字翻译成字符串 （求数量）
 * @msg: 动态规划 f(i) = 1. f(i+1)               i,i+1不能组成符合要求的数字
 *                       2. f(i+1) + f(i+2)      i,i+1能组成符合要求的数字，所以有两个子问题
 */
namespace TranslateNumbersToStrings{
    int GetTranslationCount(int number){
        if (number < 0) return 0;
        if (number < 10) return 1;
        string input = to_string(number);
        vector<int> dp(input.size(), 0);
        dp[input.size()-1] = 1;
        int lastNumber = (input[input.size()-2]-'0')*10 + (input[input.size()-1]-'0');
        if (lastNumber<=25 && lastNumber>=0){
            dp[input.size()-2] = 2;
        }
        else  
            dp[input.size()-2] = 1;
        for (int i = input.size()-3; i>=0; i--){
            
            bool flag;          // i,i+1能否组成符合要求的数字
            lastNumber = (input[i]-'0')*10 + (input[i+1]-'0');
            if (lastNumber<=25 && lastNumber>=0){

                flag = true;    // i,i+1能组成符合要求的数字，所以有两个子问题
            }
            else
                flag = false;   // i,i+1不能组成符合要求的数字
            dp[i] = flag ? (dp[i+1]+dp[i+2])  :dp[i+1];
        }
        return dp[0];
    }
}

/**
 * @name: 面试题47：礼物的最大价值
 * @msg: dp 状态方程是 f(i,j) = max(f(i-1,j),f(i,j-1))
 */
namespace MaxValueOfGifts{
    int getMaxValue_solution1(const vector<vector<int>> &input){
        if (input.size() == 0) return 0;
        vector<vector<int>> dp(input.size(), vector<int>(input[0].size(), 0));
        dp[0][0] = input[0][0];
        for (int i = 1; i < input.size(); i++) {
            dp[i][0] = dp[i-1][0] + input[i][0];
        }
        for (int j = 1; j < input[0].size(); j++) {
            dp[0][j] = dp[0][j-1] + input[0][j];
        }

        for (int i = 1; i < input.size(); i++){
            for (int j = 1; j < input[0].size(); j++) {
                dp[i][j] = input[i][j] + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp.back().back();
    }
}

/**
 * @name: 面试题48：最长不含重复字符的子字符串
 * @msg: 遇到关于26个字母的题可以用一个长度为26的数组存储，无论是计数还是作为标志都可以；
 *      本题主要是动态规划，用来记录每个位置之前的连续不重复字符长度
 *      f(i) = distance  if f(i-1)>=distance
 *             f(i-1)+1  else .....
 *      return *max_element(f(i))
 */
namespace LongestSubstringWithoutDup{
    int longestSubstringWithoutDuplication(const std::string& str){
        int result = 0;
        int* position = new int[26];
        for (int i = 0; i<26; i++)
            position[i] = -1;
        vector<int> dp(str.size(), 0);
        dp[0] = 1;
        position[str[0]-'a'] = 0;
        for (int i = 1; i<str.size(); i++){
            if (position[str[i]-'a'] == -1)
                dp[i] = dp[i-1]+1;
            else{
                int distance = i-position[str[i]-'a'];
                if (distance<=dp[i-1]){
                    dp[i] = distance;
                }
                else
                    dp[i] = dp[i-1]+1;
            }
            position[str[i]-'a'] = i;
            result = result<dp[i]?dp[i]:result;
        }
        return result;
    }
}

/**
 * @name: 面试题49：丑数
 * @msg: 数学规律 逐个生成 并且比较数值 去除重复
 */
namespace UglyNumber{
    int GetUglyNumber(int index){
        if (index <= 0) return 0;
        // lambda表达式
        // shared_ptr<int> pUglyNumbers = make_shared<int>(new int[index], [](int *p){delete [] p;});
        int *pUglyNumbers = new int[index];
        pUglyNumbers[0] = 1;
        int nextUglyNumberIndex = 1;
        int *pMultiply2 = pUglyNumbers;
        int *pMultiply3 = pUglyNumbers;
        int *pMultiply5 = pUglyNumbers;
        while (nextUglyNumberIndex < index)
        {
            int minN = min(min(*pMultiply2*2, *pMultiply3*3),*pMultiply5*5);
            pUglyNumbers[nextUglyNumberIndex] = minN;
            while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyNumberIndex])
                ++pMultiply2;
            while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyNumberIndex])
                ++pMultiply3;
            while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyNumberIndex])
                ++pMultiply5;

            ++nextUglyNumberIndex;
        }
        int ugly = pUglyNumbers[nextUglyNumberIndex - 1];
        delete[] pUglyNumbers;
        return ugly;
    }
}

/**
 * @name: 面试题50（一）：字符串中第一个只出现一次的字符
 * @msg: 用数组模拟hashTable 两次遍历即可，第一次构建计数数组，第二次查询数组
 */
namespace FirstNotRepeatingChar{
    char FirstNotRepeatingChar(const char* pString){
        if (pString == nullptr) return '\0';
        const int tableSize = 256;
        unsigned int hashTable[tableSize];
        for(unsigned int i = 0; i < tableSize; ++i)
            hashTable[i] = 0;
        const char* pStringCopy = pString;
        while (*pStringCopy!='\0')
            hashTable[*(pStringCopy++)]++;
        pStringCopy = pString;
        while (*pStringCopy!='\0'){
            if (hashTable[*(pStringCopy)] == 1)
                break;
            else
                pStringCopy++;
        }

        return *pStringCopy;
    }
}

/**
 * @name: 面试题50（二）：字符流中第一个只出现一次的字符
 * @msg: 类似面试题50（一）  只不过hashTable中int数值附有更多含义，-1是表明没有这个字符，-2是表明多个字符，index>=0表明只出现一次的位置
 */
namespace FirstCharacterInStream{
    class CharStatistics
    {
    public:
        CharStatistics() : index(0)
        {
            for(int i = 0; i < 256; ++i)
                occurrence[i] = -1;
        }

        void Insert(char ch)
        {
            if (occurrence[ch] == -1)
                occurrence[ch] = index;
            else if(occurrence[ch] >= 0)
                occurrence[ch] = -2;

            index++;
            
        }

        char FirstAppearingOnce()
        {
            char ch = '\0';
            int minIndex = numeric_limits<int>::max();
            for(int i = 0; i < 256; ++i)
            {
                if(occurrence[i] >= 0 && occurrence[i] < minIndex)
                {
                    ch = (char) i;
                    minIndex = occurrence[i];
                }
            }

            return ch;
        }

    private:
        // occurrence[i]: A character with ASCII value i;
        // occurrence[i] = -1: The character has not found;
        // occurrence[i] = -2: The character has been found for mutlple times
        // occurrence[i] >= 0: The character has been found only once
        int occurrence[256];
        int index;
    };
}

/**
 * @name: 面试题63：股票的最大利润
 * @msg:  leetcode股票类题型集合 
 */
namespace MaximalProfit{
    /**
     * @name: leetcode-121-买卖股票的最佳时机
     * 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
     * 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
     * 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
     * 收获最大的利润11。          
     * @msg: 一次遍历，每次记录前i-1个元素的最小值，并且和当前数值计算最大差值，如果差值大于当前的，就更新
     *       最终差值为正的就是最大收益。
     */    
    int MaxProfit_1(vector<int> &input){
        if (input.size() <= 2) return 0;
        int minOfFront = input[0];
        int maxOfBack = input[1];
        int i = 1;
        for (; i<input.size()-1; i++){
            minOfFront = minOfFront<=input[i]?minOfFront:input[i];
            maxOfBack = maxOfBack>input[i+1]?maxOfBack:input[i+1];
        }
        return maxOfBack-minOfFront;
    }
       
    /**
     * @name: leetcode-122-买卖股票的最佳时机 II
     * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
     * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
     * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
     * @msg: 1.暴力法，dfs，遍历所有情况，子序列里面继续买入卖出
     *
     *       2.动态规划，找寻状态转移方程
     *         dp[i][0 or 1] 第i天（持有或不持有）最大收益
     *         dp[i][0] = max(dp[i-1][1]+prices[i], dp[i-1][0])
     *         dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1])
     *       3.贪心
     *         
     */    
    // 1.暴力法，dfs，遍历所有情况，子序列里面继续买入卖出
    int maxProfitDfs_2(vector<int>& prices, int day){
        if (day > prices.size()-1)
            return 0;
        int maxP = 0;
        for (int i = day; i<prices.size()-1; i++){
            int maxProfitNumber = 0;
            for (int j = i+1; j<prices.size(); j++){
                if (prices[i]<prices[j]){
                    int profit = maxProfitDfs_2(prices,  j+1) - prices[i] + prices[j];
                    maxProfitNumber = max(maxProfitNumber, profit);
                }
            }
            maxP = max(maxProfitNumber, maxP);
        }
        return maxP;
    }
    // 2.动态规划，找寻状态转移方程
    int maxProfitDP_2(vector<int>& prices){
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        int i = 1;
        for (; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][1]+prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
        }
        return dp[prices.size()-1][0];
    }
    int maxProfit_2(vector<int>& prices) {
        // return maxProfitDfs(prices, 0);
        return maxProfitDP_2(prices);
    }

    /**
     * @name: leetcode-123-买卖股票的最佳时机 III
     * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
     * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两(k)笔 交易
     * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
     * @msg: 1.暴力法，dfs，遍历所有情况，子序列里面继续买入卖出，加入次数限制
     *       2.动态规划
     *          dp[i][k][0 or 1]  前i个并且买入k次后 0 不持有， 1 持有
     *          dp[i][k][0] = dp[i-1][k][1]+prices[i], dp[i-1][k][0]
     *          dp[i][k][1] = dp[i-1][k-1][0]-prices[i], dp[i-1][k][1]
     */    
    int maxProfitDfs_3(vector<int>& prices, int day, int k){
        if (day>prices.size()-1)
            return 0;
        int maxP = 0;
        for (int i = day; i<prices.size(); i++){
            int maxProfitNumber = 0;
            for (int j = i+1; j<prices.size(); j++){
                if (prices[i]<prices[j] && k>0){
                    int profit = maxProfitDfs_3(prices, j+1, k-1) - prices[i] + prices[j];
                    maxProfitNumber = max(maxProfitNumber, profit);
                }
            }
            maxP = max(maxProfitNumber, maxP);
        }
    }
    int maxProfitDP_3(vector<int> &prices, int k){
        if (prices.size()==0)
            return 0;
        vector<vector<vector<int> > > dp(prices.size(), vector<vector<int> >(k, vector<int>(2, 0)));

            
        int i = 1;
        for (; i<prices.size(); i++){
            for (int j = 1; j<k; j++){
                dp[i][j][0] = max(dp[i-1][j][1]+prices[i], dp[i-1][j][0]);
                dp[i][j][1] = max(dp[i-1][j-1][0]-prices[i], dp[i-1][j][1]);
            }
        }
        return dp[i][k][0];
    }
    int maxProfit_3(vector<int>& prices) {
        return maxProfitDfs_3(prices, 0, 2);
    }

    /**
     * @name: leetcode-309-最佳买卖股票时机含冷冻期
     * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格
     * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
     * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
     * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
     * @msg: 1.暴力法 dfs 单纯加了一个冷冻期 也就是多了一个遍历在卖出日期的基础上
     *       2.动态规划 
     *          dp[i][0,1,2] 第i天（不持有但能买, 持有可以卖, 不持有但不能买）最大收益
     *          dp[i][0] = max(dp[i-1][0],  dp[i-1][2]);
     *          dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
     *          dp[i][2] = max(dp[i-1][0], dp[i-1][1]+prices[i], dp[i-1][2]);
     */    
    int maxProfitDfs_5(vector<int>& prices, int day){
        if (day > prices.size()-1)
            return 0;
        int maxP = 0;
        for (int i = day; i<prices.size(); i++){
            int maxProfitNumber = 0;
            for (int j = i+1; j<prices.size(); j++){
                for (int k = j+1; k<prices.size(); k++){
                    if (prices[i]<prices[j]){
                        int profit = maxProfitDfs_5(prices,  k+1) - prices[i] + prices[j];
                        maxProfitNumber = max(maxProfitNumber, profit);
                    }
                }
            }
            maxP = max(maxProfitNumber, maxP);
        }
        return maxP;
    }
    int maxProfitDP_5(vector<int>& prices){
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        int i = 1;
        for (; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
            dp[i][2] = dp[i-1][1]+prices[i];
        }
        return dp[prices.size()-1][0];
    }
    int maxProfit_5(vector<int>& prices) {
        return maxProfitDfs_5(prices, 0);
    }
}






































namespace alibaba{
    /**
     * @name: 有n个物品编号为1−n，现将其重新排列，但要求相邻两物品的编号差值的绝对值不等于1，按字典序输出所有满足要求的方案
     * @msg: dfs 全排列
     */    
    namespace time_7_22_1{
        void dfs(vector<int> numbers, vector<bool> flag);

        vector<vector<int>> presult;
        int n;

        vector<vector<int>> findResult(int n){
            vector<bool> flag(n+1, true);
            for (int i = 1; i<=n; i++){
                flag[i] = false;
                dfs({i}, flag);
                flag[i] = true;
            }
            return presult;
        }

        void dfs(vector<int> numbers, vector<bool> flag){
            if (numbers.size() == n){
                presult.push_back(numbers);
                return ;
            }
            for (int j = 1; j<=n; j++){
                if (flag[j] == true){
                    if ( numbers.back()-1==j || numbers.back()+1 == j){
                        continue;
                    }
                    numbers.push_back(j);
                    flag[j] = false;
                    dfs(numbers, flag);
                    
                    numbers.pop_back();
                    flag[j] = true;
                }
            }
        }
    }
    /**
     * @name: 小强有一个长度为nn的数组aa和正整数mm。他想请你帮他计算数组aa中有多少个连续子区间[l,r][l,r]，其区间内存在某个元素出现的次数不小于mm次？例如数组a=[1,2,1,2,3]a=[1,2,1,2,3]且m=2m=2，那么区间[1,3],[1,4],[1,5],[2,4],[2,5][1,3],[1,4],[1,5],[2,4],[2,5]都是满足条件的区间，但区间[3,4][3,4]等都是不满足条件的。
     * @msg: 双指针
     */    
    namespace time_7_22_2{
         int m,n; 
        cin >> n >> m;
        vector<int> numbers;
        int num;
        int ans = 0;
        while (cin>>num)
        {
            numbers.push_back(num);
        }
        int len = numbers.size();
        for (int i = 0; i<len; i++){
            vector<int> count(400001,0);
            for (int j = i; j<len; j++){
                count[numbers[j]]++;
                if (count[numbers[j]] >= m) 
                    {ans += (len - j);break;}
            }
        }
        cout << ans << endl;
    }
}