/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-06-30 15:07:21
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-07-22 16:45:29
 */ 
/*
 * @Descripttion: main
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-30 13:35:17
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-06-30 15:07:21
 */
// #include <iostream>
// #include <sstream>
// #include <cmath>
// #include <stdlib.h>
// #include <cstring>
// #include <map>
// #include <memory>
// #include <unordered_map>
#include <bits/stdc++.h>
// #include <wx/wx.h>
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "AvlTree.hpp"
#include "utils.h"
#include "sort.h"
#include "jzoffer.hpp"
#include "List.h"
#include "HashMap.h"

char *str[] = {"aaa", "aab", "aac", "zhouzhou", "yiyi"};

void example_vector();
void example_list();
void example_stack();
void exmaple_avltree();
void jzoffer_test();
void leetcode_test();
void book_exec();
void sort_test();


int main(int argc, char const *argv[])
{   
   
    
    // divide(12345, 12);
    jzoffer_test();
    // example_vector();
    // example_list();
    // example_stack();
    // exmaple_avltree();
    // leetcode_test();
    // sort_test();
    // book_exec();
    system("pause");
    return 0;
}

void jzoffer_test(){
    #if 0
    std::vector<int> input_1 = {1,2,4,2,3,3,4,5};
    duplicate::duplicate_1(input_1, 8);
    duplicate::duplicate_2(input_1, 8);
    duplicate::duplicate_3(input_1, 8);
    int cc = duplicate::duplicate_4(input_1, 7);

    std::vector<std::vector<int> > input2 = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    bool result = Find::Find(input2, 16);

    std::string input3 = "   ";
    ReplaceBlank::ReplaceBlank(input3);

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    PrintListReversing_Iteratively::PrintList_Reversing_Iteratively_2(pNode1);
    
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
    ConnectBinaryTreeNode(pNode8, pNode6, pNode10);
    ConnectBinaryTreeNode(pNode6, pNode5, pNode7);
    ConnectBinaryTreeNode(pNode10, pNode9, pNode11);
    BinaryTreeNode* pNext = NextNodeInBinaryTrees::GetNext(pNode7);
    
    int Fibonacci_result_n = Fibonacci::Fibonacci(8);
        
    std::vector<int> array1 = {  3, 4, 5, 1, 1, 2};
    std::vector<int> array2 = {3, 4, 5, 1, 2, 2 };
    std::vector<int> array3 = { 1};
    int array1_result = MinNumberInRotatedArray::findMinInRotatedArray_2(array1);
    int array2_result = MinNumberInRotatedArray::findMinInRotatedArray_2(array2);
    int array3_result = MinNumberInRotatedArray::findMinInRotatedArray_2(array3);

    std::vector<std::vector< char>> matrix = {{'A','B','T','G'},{'C','F','C','S'},{'J','D','E','H'}};
    std::string str = "BFCE";
    bool StringPathInMatrixResult = StringPathInMatrix::StringPathInMatrix(matrix, str);
    StringPathInMatrix::Permutation(3);
    
    cout  << RobotMove::RobotMove(10, 10, 5) << endl;

    cout  << CuttingRope::maxProductAfterCutting_solution1(7) << endl;

    cout << NumberOf1InBinary::NumberOf1_Solution1(10) << endl;
    
    Print1ToMaxOfNDigitsRecursively::PrintNumber(3);
        
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    DeleteListNode::DeleteDuplication(&pHead);
    
    bool RE_result_1 = RegularExpressions::match("aaa", "ab*ac*a");
    bool RE_result_2 = RegularExpressions::match("bcbbabab", ".*a*a");

    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};
    ReorderArray::ReorderOddEven_1(numbers);
    
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = KthNodeFromEnd::FindKthToTail(pNode1, 0);
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);
    EntryNodeInListLoop::MeetingNode(pNode1);
    
    int rows = 1, columns = 5;
    vector<vector<int> > numbers(rows, vector<int>(columns, 0));
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrix::PrintMatrixClockwisely(numbers);

    vector<int> push = {1};
    vector<int> pop = {4};

    bool result = StackPushPopOrder::IsPopOrder(push, pop);

    vector<int> data =   {4, 8, 6, 12, 16, 14, 10};
    SquenceOfBST::VerifySquenceOfBST(data);

    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectBinaryTreeNode(pNode10, pNode5, pNode12);
    ConnectBinaryTreeNode(pNode5, pNode4, pNode7);
    
    PathInTree::FindPath(pNode10, 22);

    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    ComplexListNode* pClone = CopyComplexList::Clone(pNode1);

    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectBinaryTreeNode(pNode10, pNode6, pNode14);
    ConnectBinaryTreeNode(pNode6, pNode4, pNode8);
    ConnectBinaryTreeNode(pNode14, pNode12, pNode16);
    ConvertBinarySearchTree::Convert(pNode10);

    string s = "abcd";
    StringPermutation::Permutation(s);
    StringPermutation::Combination(s);
    vector<int> cubic = {0,1,2,3,4,5,6,7};
    bool cubicresult = StringPermutation::CubicEqualExist(cubic);

    vector<int> numbers = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    MoreThanHalfNumber::CheckMoreThanHalf(numbers);

    vector<int> vec = {3,2,4,1,6,5,8};
    KLeastNumbers::GetLeastNumbers_Solution1(vec, 3);
    
    vector<int> data = {1, -2, 3, 10, -4, 7, 2, -5};
      vector<int> newData(&data[8],&data[data.size()]);
     cout << GreatestSumOfSubarrays::FindGreatestSumOfSubArray(data);

     NumberOf1::NumberOf1Between1AndN(21345);

     cout << DigitsInSequence::digitAtIndex(1001);

     vector<int> input = {1, 11, 111};
    SortArrayForMinNumber::PrintMinNumber(input);

     TranslateNumbersToStrings::GetTranslationCount(12258);

    vector<vector<int>> values = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    MaxValueOfGifts::getMaxValue_solution1(values); 
    
    LongestSubstringWithoutDup::longestSubstringWithoutDuplication("abcacfrar");
    
    UglyNumber::GetUglyNumber(30);

    FirstNotRepeatingChar::FirstNotRepeatingChar("google");

    bool RE_result_2 = RegularExpressions::match("aaaaaaaaaaab", ".*a*a*a*a*a*a*a*a*a*a*b");

    vector<int> numbers =  { 9, 11, 5, 7, 16, 1, 4, 2 };
    MaximalProfit::maxProfit_3(numbers);
    #else
    // ListNode* pNode1 = CreateListNode(1);
    // ListNode* pNode2 = CreateListNode(4);
    // ListNode* pNode3 = CreateListNode(3);
    // ListNode* pNode4 = CreateListNode(2);
    // ListNode* pNode5 = CreateListNode(5);
    // ListNode* pNode6 = CreateListNode(2);
    // ConnectListNodes(pNode1, pNode2);
    // ConnectListNodes(pNode2, pNode3);
    // ConnectListNodes(pNode3, pNode4);
    // ConnectListNodes(pNode4, pNode5);
    // ConnectListNodes(pNode5, pNode6);
    
    // partition(pNode1, 3);
    vector<int> vec = {4,2,3,5,7,1,9,12,4};
    SORT::quickSortLoop<int>(vec);
    
    #endif
}

void example_vector()
{
    int a = 1, b = 2, c = 3, d = 4;
    double e = 1.1, f = 2.21;
    char *str[] = {"aaa", "aab", "aac", "zhouzhou", "yiyi"};
    // Vector用例
    Vector<int> v_int;
    v_int.push_back(a);
    v_int.push_back(b);
    v_int.push_back(c);
    v_int.push_back(d);

    std::cout << "v_int的元素大小：" << v_int.size()
              << "\tv_int的容量大小：" << v_int.capacity()
              << std::endl;
    for (auto itr = v_int.begin(); itr != v_int.end(); itr++)
        std::cout << *itr << " ";
    std::cout << std::endl;

    Vector<int> v_int_1;
    if (&v_int == &v_int_1)
        std::cout << "地址相同" << std::endl;
    else
        std::cout << "v_int:" << &v_int << "\t v_int_1:" << &v_int_1 << std::endl;
    v_int_1 = (v_int);
    v_int_1.pop_back();
    std::cout << "v_int_1最后一个元素： " << v_int_1.back() << std::endl;
    for (auto itr_1 = v_int_1.begin(); itr_1 != v_int_1.end(); itr_1++)
        std::cout << *itr_1 << " ";
    std::cout << std::endl;
}

void example_list()
{
    int a = 1, b = 2, c = 3, d = 4;
    double e = 1.1, f = 2.21;
    
    List<char *> l_char;
    for (int i = 0; i < sizeof(str)/sizeof(char*); i++)
    {
        l_char.push_back(str[i]);
    }
    for (auto itr = l_char.begin(); itr != l_char.end(); ++itr)
    {
        std::cout << *itr << " ";
    }
    l_char.insert(++l_char.begin(), "ddd");
    std::cout << std::endl;
}

void example_stack()
{
    int a = 1, b = 2, c = 3, d = 4;
    double e = 1.1, f = 2.21;
    
    Stack<double> s_double;
    s_double.push(e);
    s_double.push(f);
    while (!s_double.empty())
    {
        std::cout << s_double.top() << " ";
        s_double.pop();
    }
    std::cout << std::endl;
}

void exmaple_avltree(){
    int N = 16;
    AvlTree<int> T;
    T.makeEmpty();
    int a[] = {1, 2, 3, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
    for (int i = 0; i < N; ++i) {
        T.insert(a[i]);
    }
    T.printTree();
    std::cout<<T.isValid()<<std::endl;
}

void leetcode_test()
{
    Solution s;
#if 0

    // 8
    std::string str_num = "-2147483646";
    std::cout << s.myAtoi(str_num) << std::endl; 
    // 9
    int Palindrome_1 = 1234321;
    int Palindrome_2 = 123321;
    s.isPalindrome(Palindrome_1);
    s.isPalindrome(Palindrome_2);
    //20
    std::string Effectivebrackets = "(){}{()}";
    s.isValid(Effectivebrackets);
    //28
    std::string str1 = "hello", str2 = "ll";
    s.strStr(str1, str2);
    //38
    std::cout << s.countAndSay(6) << std::endl;;

    //1041
    s.isRobotBounded("GGRGGRGGRGGR");

    //2
    Solution::ListNode *test_1 = new Solution::ListNode(4);
    Solution::ListNode *test_2 = new Solution::ListNode(9);
    Solution::ListNode *result = s.addTwoNumbers(test_1, test_2);
    
    //1013
    vector<int> test = {3,3,6,5,-2,2,5,1,-9,4};
    s.canThreePartsEqualSum(test);

    //面试题 17.17. 多次搜索
    string big = "mississippi";
    vector<string> smalls = {"is","ppi","hi","sis","i","ssippi"};
    s.multiSearch(big, smalls);   
    //695
    vector<vector<int> > grid;
    //grid={{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    grid={{1,1}};
    s.maxAreaOfIsland(grid);

    // 面试题 01.06
    string a = "aaabbbcc";
    s.compressString(a);

    //179
    vector<int> nums = {10, 0};
    s.largestNumber(nums);

    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";
    s.countCharacters(words, chars);

    string a = "";
    s.lengthOfLongestSubstring(a);
  
    //945
    vector<int> A = {3,2,1,2,1,7};
    s.minIncrementForUnique(A);

    //105
    vector<int> pre = {3,9,20,15,7};
    vector<int> ino = {9,3,15,20,7};
    s.buildTree2(pre, ino);
    
    //106
    vector<int> post = {9,15,7,20,3};
    vector<int> ino = {9,3,15,20,7};
    s.buildTree1(ino, post);

    vector<string> words = {"mass","as","hero","superhero"};
    s.stringMatching(words);

    vector<int> queries = {3,1,2,1};
    int m =5;
    s.processQueries(queries, m);

    string text = "&amp; is an HTML entity but &ambassador; is not.";
    s.entityParser(text);

    vector<vector<char> > board = {{'a','b'}, {'c','d'}};
    string word = "abcd";
    s.exist(board ,word);

    s.myPow(2.0, 9);

    vector<vector<int>> intervals = {{4,5},{2,4},{4,6},{3,4},{0,0},{1,1},{3,5},{2,2}};  //[[4,5],[2,4],[4,6],[3,4],[0,0],[1,1],[3,5],[2,2]]
    s.minMeetingRooms(intervals);
 
    vector<vector<int>> obstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
    s.uniquePathsWithObstacles(obstacleGrid);

     s.getPermutation(4, 7);

     vector<vector<int> > image = {{1,1,1},{1,1,0},{1,0,1}};
    s.floodFill(image, 1, 1, 2);
#endif 
    vector<int> nums1 = {1};
    vector<int> nums2 = {2,3,4,5,6};

    s.findMedianSortedArrays(nums1, nums2);

}

#include "exercises.hpp"
void book_exec()
{
    // std::cout << "习题3.1：";
    // exec_3_1();
    // std::cout << "习题3.4：";
    // exec_3_4();
    // std::cout << "习题3.5：";
    // exec_3_5();
    // std::cout << "习题3.6：";
    // exec_3_6();
}

void sort_test(){
    vector<int> obj = {34,8,64,2,1,3,4,5,2,11,31};
    insertionSort<int>(obj);
}