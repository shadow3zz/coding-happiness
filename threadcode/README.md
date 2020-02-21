<!--
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-21 12:03:44
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-21 22:02:29
 -->

# C++并发编程实战笔记

## 1.开始入门

### 1.4 第一个独立线程的程序

```c++
#include <iostream>
#include <thread>

void hello(){
    std::cout<< "Hello concurrent World!" << std::endl;
}

int main(){
    std::thread t(hello);
    t.join();
    return 0;
}
```

初始线程含义，场景和历史内涵。

## 2.管理线程

为保证程序有效检查和监视线程的状态，本章学习相关类。

### 2.1 基本线程管理

#### 2.2.1 启动线程

std::thread可以与任何可调用(callable)类型一同工作，可以将一个带有函数调用操作符的类的实例传递给std::thread的构造函数来进行替代。

当线程构造函数传递一个函数对象时，如果传递的是一个临时的且未命名的变量，要注意初始化语法格式，避免其解释为函数声明。也可以利用lambda表达式，编写局部函数解决，其可以捕捉一些局部变量，同时避免传递额外参数的需求。

一旦开始线程，需要决定是否是*结合*它还是*分离*它，这一过程需要显视说明。

- 结合：等待线程完成，调用join();

- 分离：自行运行，通过调用detach()表明当前函数不等待线程，但是要注意避免函数结束时，线程中所使用的变量不被销毁。

避免销毁变量在线程中使用，常见处理方式是使线程函数自包含，并且把数据复制到该线程中而不是共享数据。但仍需警惕包含有指针或者引用的对象。

#### 2.1.2 等待线程完成

- 检查线程

- 替代机制

- 关联存储器

- 只能对一个给定的线程调用一次join()

#### 2.1.3 在意尝环境下的等待

确保在std::thread对象被销毁前调用join()或detach()函数。

如果要分离线程，通常是在线程启动后就可以立即调用detach()；但是要等待线程就需要考虑join()具体调用位置。

确保线程在函数退出前完成很重要，解决这一问题的途径是资源获取即初始化(RAII)，并提供一个类，在它的析构函数中进行join()。

#### 2.1.4 在后台运行线程

参照UNIX的守护进程，被分离的线程通常称作守护线程，运行在后台。

- 监控文件系统

- 清除对象缓存中未使用的项

- 优化数据结构

只能在t.joinable()为true时，才能调用detach()。std::thread对象调用join()后，此对象不再是可连接的了，joinable()将返回false。

- 分离线程以处理其他文档

```c++
void edit_document(std::string const& filename){
    open_document_and_display_gui(filename);
    while(!done_editing()){
        user_command cmd = get_user_input();
        if (cmd.type == open_new_document){
            std::string const new_name = get_filename_from_user();
            std::string t(edit_document, new_name);
            t.detach();
        }
        else
        {
            process_user_input();
        }
    }
}
```

### 2.2 传递参数给进程

*避免悬浮指针：* 注意字符串字面值仅在新线程的上下文中才会作为char const\*传递，并转换为std::string。这是由于std::thread构造函数原样复制了所提供的值，并未转换未期望的参数类型。

*避免盲目复制：* std::thread构造函数无视函数所需的类型，并且盲目地复制所提供的值，具体而言是指调用带有引用参数的函数时，std::thread却传递的是其在内部的副本，当线程结束时对这个副本的改动将消失，初始线程中将继续沿用原本的参数值。
这个问题可以通过std::ref包装来解决，std::ref(参数)将正确传入参数的引用，而非参数副本(copy)的引用。

类似std::bind()可以传递一个成员函数的指针作为函数（第一个参数），前提是提供一个合适的对象指针作为第二个参数，第三个参数将作为成员函数的第一个参数。

```c++
class X
{
public:
    void do_lengthy_work();
};
X my_x;
std::thread t(&X::do_lengthy_work, &my_x);
```

另外，可以利用std::move()将动态对象转移到一个线程中，其中std::unique_ptr提供了动态分配对象的内存管理，并且只有一个std::unique_ptr实例可以在某一时刻指向一个给定的对象，当该实例被销毁时，其指向的对象也被销毁。

```c++
void process_big_object(std::unique_ptr<big_object>);

std::unique_ptr<big_object> p(new big_object);
p->prepare_data(42);
std::thread t(process_big_object, std::move(p));
```

std::thread的实例是**可移动的**，即使他们**不是可复制的**。这保证在编程时，在任意时刻只有一个对象与某个特定的执行线程相关联。

### 2.3 转移线程的所有权

一个特定执行线程的所有权可以在std::thread实例之间移动，利用std::move()即可。

将std::thread对象放到std::vector中时线程迈向自动管理的一步。

ps: std::men_fn(),函数适配器,通过指向对象的指针调用成员函数时使用.

### 2.4 在运行时选择线程数量

c++标准库中对此有帮助的特性是std::thread::hardware_currency()，这个函数返回一个对应程序执行时能够真正并发运行的线程数量的指示。另外清单2.8给出例子，在假定所有线程操作都正常的情况下，std::accumulate的一个间的并行版本实现，它在线程之间划分所作的工作，是的每个线程具有最小数目的元素以避免过多线程的开销。

```c++
template<typename Iterator, typename T>
struct accumulate_block{
    void operator()(Iterator first, Iterator last, T& result){
        result=std::accumulate(first, last, result);
    }
};
template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init){
    unsigned long const length = std::distance(first, last);

    if(!length){
        return init;
    }

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length+min_per_thread-1)/min_per_thread;

    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads!=0?hardware_threads:2, max_threads)
    unsigned long const block_size = length/num_threads;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads-1);

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads-1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
        block_start = block_end;
    }
    accumulate_block<Iterator, T>()(
        block_start, last, results[num_threads-1]
    );
    std::for_each(threads.begin(), threads.end(),
        std::mem_fn(&std::thread::join)
    );
    return std::accumulate(results.begin(), result.end(), init);
}
```

ps: std::accumulate(first, last, result);其头文件在numeric中，累加操作。

### 2.5 标识线程

线程标识符是std::thread::id类型的，有以下两种获取方式：

1. 线程的标识符通过与之相关联的std::thread对象中调用get_id()成员函数来获得，如果std::thread没有相关联的执行线程，返回默认值，表示没有线程。

2. 当前线程标识符可以通过调用std::this_thread::get_id()获得。

## 附录A C++11 部分语言特性简明参考

### A.1 右值引用

左值是指表达式结束后依然存在的持久化对象，右值是指表达式结束时就不再存在的临时对象。区分左值和右值的便捷方法：看能不能对表达式取地址，如果能，则为左值，否则为右值。

为更好地在对象间进行线程、锁或者其他任何东西地所有权转换。c++的引用允许我们为一个现有的对象创建一个新的名字，所用通过引用完成的访问和修改操作都会影响本体。过去c语言中我们普遍使用左值引用，是指有确定存储空间的东西，包含对象、在栈和堆上分配的对象或者其他对象的成员。而右值指的是只能在赋值表达式右侧出现的东西，如字面值和临时对象。

左值引用只能被绑定到左值，也就是说左值引用赋值表达式右侧只能是左值。例如数字42就是一个右值`int& i=42；`(error)，但是能够将一个右值绑定到const左值引用'int const& i=42;'（correct）。在右值引用之前，为了能够将临时对象作为引用参数传递给函数，c++标准故意设置了一个例外，允许进行隐式转换。例如：

```c++
void print(std::string const& s);
print("hello");
```

右值引用只能绑定到右值，不能绑定到左值。c++11在声明一个右值引用的时候形式为`T&&`。当然，可以通过重载赋值函数，改变上述要求，这就和移动语义相关知识有关系了。

#### A.1.1 移动语义

通常右值是临时对象，可以被自由的修改，并且节约大量的内存空间。

[TOC]
