/*
 * @Descripttion: leetcode
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-31 21:49:23
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-02-01 16:45:30
 */

#pragma once
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
using namespace std;
class Solution
{
public:
    /**
     * @name: 8. 字符串转换整数 (atoi)
     * @msg: 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
     * 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
     * 当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，
     * 作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
     * 该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。
     * 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
     * 在任何情况下，若函数不能进行有效的转换时，请返回 0。
     * @param {type} 
     * @return: 
     */
    int myAtoi(string str)
    {
        while (&str)
        {
            /* code */
        }
        
    }

    /**
     * @name: 9. 回文数
     * @msg: 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
     * @param {type} 进阶:
            你能不将整数转为字符串来解决这个问题吗？
     * @return: 
     */
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        if (x % 10 == 0)
            return false;
        vector<int> num;
        while (x > 0)
        {
            num.push_back(x % 10);
            x /= 10;
        }
        auto itr_1 = num.begin();
        auto itr_2 = num.end();
        itr_2--;
        while (*itr_1 == *itr_2)
        {
            ++itr_1;
            if (itr_1 == itr_2 && *itr_1 == *itr_2)
                return true;
            --itr_2;
            if (itr_1 == itr_2)
                return true;
        }
        return false;
    }

    /**
     * @name: 20. 有效的括号
     * @msg: 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
     * 有效字符串需满足：
     * 左括号必须用相同类型的右括号闭合。
     * 左括号必须以正确的顺序闭合。
     * 注意空字符串可被认为是有效字符串。
     * @param {type} 
     * @return: 
     */
    bool isValid(string s)
    {
        if (s.empty())
            return true;
        stack<char> kuohao;
        for (auto letter : s)
        {
            if (letter == '{' || letter == '(' || letter == '[')
            {
                kuohao.push(letter);
            }
            else if (letter == '}' || letter == ')' || letter == ']')
            {
                if (kuohao.empty())
                    return false;
                if ((kuohao.top() == '{' && letter == '}') || (kuohao.top() == '(' && letter == ')') || (kuohao.top() == '[' && letter == ']'))
                    kuohao.pop();
                else
                    return false;
            }
        }
        if (!kuohao.empty())
            return false;
        return true;
    }
    /**
     * @name: 22. 括号生成
     * @msg: 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
     * @param {type} 例如，给出 n = 3，生成结果为:
                        [
                        "((()))",
                        "(()())",
                        "(())()",
                        "()(())",
                        "()()()"
                        ]
     */
    vector<string> generateParenthesis(int n)
    {
        
    }
    /**
     * @name: 28.实现 strStr()
     * @msg: 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
     * @tips: 当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
     * @输入: haystack = "hello", needle = "ll"
     * @输出: 2
     * 比str1.find(str2)好
    */
    int strStr(std::string haystack, std::string needle)
    {
        haystack.find(needle);
        if (!needle.empty())
        {
            int N = haystack.size() - needle.size() + 1;
            for (int i = 0; i < N; i++)
            {
                int k = 0;
                int j = i;
                while (haystack[j++] == needle[k++])
                    if (k == needle.length())
                        return i;
            }
            return -1;
        }
        else
        {
            return 0;
        }
    }
    /**
     * @name: 224. 基本计算器
     * @msg: 实现一个基本的计算器来计算一个简单的字符串表达式的值。字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
     * @param {type} 
     * @return: 
     */
    int calculate(string s)
    {
    }
    /**
     * @name: 459. 重复的子字符串
     * @msg: 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
     */
    bool repeatedSubstringPattern(string s)
    {
    }
};