/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-06-04 21:46:03
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-06-16 00:00:49
 */
#pragma once

// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <stack>
// #include <cstring>
// #include <cstdio>
// #include <algorithm>
// #include <iterator>

// // 多线程头文件
// #include <thread>
// #include <mutex>
#include <bits/stdc++.h>
using namespace std;

/**================================================================================================
 * ----------------------------------------链表结构------------------------------------------------
 *===============================================================================================*/
struct ListNode{
    int         m_nKey;
    ListNode*   m_pNext;
};
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
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
 * ------------------------------------------------------------------------------------------------
 *===============================================================================================*/



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
        if (pData = nullptr){
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

struct BinaryTreeNode{
    int value;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
    BinaryTreeNode(int v = 0, BinaryTreeNode* pLeft=nullptr, BinaryTreeNode* pRight=nullptr):value(v), m_pLeft(pLeft), m_pRight(pRight){}
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

    template<typename T>
    void quickSort(vector<T> &vec){
    
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