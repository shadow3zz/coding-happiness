/*
 * @Descripttion: main
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-30 13:35:17
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-03 15:06:28
 */
#include <iostream>
#include <stdlib.h>
#include <cstring>
// #include <wx/wx.h>
#include "Vector.h"
#include "List.h"
#include "Stack.h"
#include "utils.h"

int a = 1, b = 2, c = 3, d = 4;
double e = 1.1, f = 2.21;
char *str[] = {"aaa", "aab", "aac", "zhouzhou", "yiyi"};

void example_vector();
void example_list();
void example_stack();
void leetcode_test();
void book_exec();

int main(int argc, char const *argv[])
{
    std::cout << "数据结构与算法分析 C++描述" << std::endl;
    // wxString msg(wxT("ready!"));
    // std::cout << "测试wxwidgets：" << msg.mb_str() << std::endl;
    // example_vector();
    // example_list();
    // example_stack();
    // leetcode_test();
    book_exec();
    system("pause");
    return 0;
}

void example_vector()
{
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

void leetcode_test()
{
    Solution s;
    // 8
    std::string str_num = "-2147483646";
    std::cout << s.myAtoi(str_num) << std::endl; 
    // 9
    int Palindrome_1 = 1234321;
    int Palindrome_2 = 123321;
    s.isPalindrome(Palindrome_1);
    s.isPalindrome(Palindrome_2);
    //
    std::string Effectivebrackets = "(){}{()}";
    s.isValid(Effectivebrackets);
    //
    std::string str1 = "hello", str2 = "ll";
    s.strStr(str1, str2);
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
    std::cout << "习题3.6：";
    exec_3_6();
}