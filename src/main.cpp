/*
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-01-30 13:35:17
 * @LastEditors  : shadow3zz
 * @LastEditTime : 2020-01-30 17:07:37
 */
#include <iostream>
#include <stdlib.h>
#include "Vector.h"
int a=1,b=2,c=3,d=4;
double e=1.1,f=2.21;
char* str[]={"aaa","aab","aac"};

void example_vector();
void example_list();

int main(int argc, char const* argv[]){
    std::cout << "数据结构与算法分析 C++描述" << std::endl;
    
    example_vector();

    system("pause");
    return 0;
}

void example_vector(){
        // Vector用例
    Vector<int> v_int;
    v_int.push_back(a);
    v_int.push_back(b);
    v_int.push_back(c);
    v_int.push_back(d);
    
    std::cout << "v_int的元素大小：" << v_int.size() 
            <<"\tv_int的容量大小："<< v_int.capacity()
            <<std::endl;
    for(auto itr = v_int.begin();itr!=v_int.end();itr++)
        std::cout << *itr << " ";
    std::cout << std::endl;
         
    Vector<int> v_int_1;
    if(&v_int == &v_int_1) 
        std::cout << "地址相同"<< std::endl;
    else
        std::cout <<"v_int:"<< &v_int << "\t v_int_1:" <<  &v_int_1 << std::endl;
    v_int_1 = (v_int);
    v_int_1.pop_back();
    std::cout << "v_int_1最后一个元素： "<< v_int_1.back() << std::endl;
    for(auto itr_1 = v_int_1.begin();itr_1!=v_int_1.end();itr_1++)
        std::cout << *itr_1 << " ";
    std::cout << std::endl;
}

void example_list(){}
