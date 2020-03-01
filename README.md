[TOC]

# Cmake学习笔记

## 1.关键词

### 1.1 cmake_policy

CMake 在添加新特性后可能不会完全兼容旧的 CMake 版本，这导致了在新版本的 CMake 中使用旧的 CMakeLists 文件时可能会存在一些问题。策略的引入就是帮助用户和开发者解决这些问题，它是 CMake 中用来改善向后兼容性和追踪兼容性的一种机制。 CMake 中的所有策略都被赋予一个 CMPNNNN 格式的识别符，其中 NNNN 是一个整数值。策略通常既保留了用于保持旧版本兼容性的旧行为，又包含了让用户在新项目中优先使用的正确的新行为。每个策略相关的文档都会描述旧行为和新行为，以及引入该策略的原因。
————————————————
版权声明：本文为CSDN博主「punymc」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/lixiang19910909/article/details/78231028

```cmake
IF (COMMAND cmake_policy)
  if (POLICY CMP0043)
    CMAKE_POLICY(SET CMP0043 NEW)
  endif (POLICY CMP0043)
  if (POLICY CMP0025)
    CMAKE_POLICY(SET CMP0025 NEW)
  endif ()
ENDIF (COMMAND cmake_policy)
```

使用 NEW 选项的 cmake_policy 命令明确告诉 CMake 使用策略的新行为。

#### 1.1.1 设置策略
工程可以设置各种策略来选择新的或旧的行为。当 CMake 遇到会被特殊策略影响的用户代码时，它会检查工程是否设置了策略。如果没有设置策略，工程会使用旧行为，并会给出警告要求项目作者设置工程的策略。
　　有许多方法设置一个策略的行为，最快速的方式是设置所有的策略版本与编写项目的 CMake 版本一致，设置策略的版本会获取所有指定的版本或更早的版本中引入的策略。所有指定的版本之后引入的策略会标记为未设置，这是为了输出这些新策略合适的警告信息。设置策略版本的命令为：

`cmake_policy (VERSION major.minor[.patch[.tweak]])`

同时，cmake_minimum_required 命令也会设置策略的版本，该命令用在 CMakeLists 文件的最顶端。一个 CMakeLists 文件开始的几行通常为如下所示：

```cmake
cmake_minimum_required (VERSION 2.6)
project (projectname)
#...code using CMake 2.6 policies
```

每个策略也可以单独设置，cmake_policy 命令的 SET 选项可以用来明确地指定一个特定策略是使用新的行为还是旧的行为。

```cmake
cmake_policy (SET CMPNNNN OLD)
使用 OLD 选项的 cmake_policy 命令明确告诉 CMake 使用策略的旧行为。
cmake_policy (SET CMPNNNN NEW)
使用 NEW 选项的 cmake_policy 命令明确告诉 CMake 使用策略的新行为。
```

#### 1.1.2 策略栈
CMake 将策略设置保存在一个栈结构中，当进入一个项目的子目录时，就会在策略栈中入栈新的一层元素，离开子目录时就会出栈这层元素。因此在一个项目的子目录中设置策略并不会影响父目录以及同层路径，但会影响子目录。这在一个项目包含了多个分别维护的子目录但在一起编译时非常有用，它可以让不同的子目录使用不同的策略版本。用户可以使用 cmake_policy 命令来入栈出栈自己的临时策略层，只要入栈和出栈是成对出现的，这对于临时对一小段代码改变策略设置时比较有用。

```cmake
cmake_policy (PUSH)
#change cmake policy
#do something
cmake_policy (POP)
```

#### 1.1.3 升级项目到新版本的 CMake
当新版本的 CMake 引入了新的策略时，一些旧的项目可能会产生提示信息用来指示项目需要进行修改来适应新的策略。有两种方法将旧项目进行策略版本升级：一次性方法和增量式方法。采用哪种方式取决于项目的规模以及新策略产生的提示信息。
(1) 一次性方法
将一个项目升级到新版的 CMake 最简单的方法是修改项目 CMakeLists 文件最开头的策略版本，尝试使用最新版本的 CMake 进行编译并修复问题。例如命令：

`cmake_minimum_required (VERSION 2.8)`
以上命令告诉 CMake 对每个策略使用2.8以及之前版本的引入的新行为。当使用 CMake 2.8 来编译项目时策略不会产生任何提示信息因为没有任何新的策略在后来的版本中引入。但是如果这个项目依赖某个策略的旧行为时编译可能不会成功，因为 CMake 现在使用的时没有提醒的新行为。
(2) 增量式方法
将项目升级到新的 CMake 版本的另一个方法是根据提示信息一个一个的进行修改，这个方法的优点是项目在这个过程中可以持续的编译，所以这个修改是增量式的。当 CMake 遇到需要确定使用策略的旧行为还是新行为的情形时，CMake 获取检查项目是否设置了这个策略，如果设置了 CMake 就使用设定的行为，如果没有设置，CMake 会使用旧的行为并提示策略没有设置。

### 1.2 if

```cmake
if(COMMAND command-name)
如果给定名称是可以调用的命令，宏或函数，则为true。

if(POLICY policy-id)
如果给定名称是现有策略（格式为CMP<NNNN>），则为True 。

if(TARGET target-name)
如果给定名称是通过调用调用创建的现有逻辑目标名称，则为True。 add_executable()， add_library()， 要么 add_custom_target() 已经被调用的命令（在任何目录中）。

if(TEST test-name)
如果给定名称是由测试人员创建的现有测试名称，则为True add_test() 命令。

if(EXISTS path-to-file-or-directory)
如果指定的文件或目录存在，则为True。仅针对完整路径定义行为。解析符号链接，即，如果命名的文件或目录是符号链接，则如果符号链接的目标存在，则返回true。

if(file1 IS_NEWER_THAN file2)
如果file1是更新版本file2或两个文件之一不存在，则为true 。仅针对完整路径定义行为。如果文件时间戳完全相同，则IS_NEWER_THAN比较将返回true，这样，在出现平局的情况下将发生任何相关的生成操作。这包括为file1和file2传递相同文件名的情况。

if(IS_DIRECTORY path-to-directory)
如果给定名称是目录，则为True。仅针对完整路径定义行为。

if(IS_SYMLINK file-name)
如果给定名称是符号链接，则为True。仅针对完整路径定义行为。

if(IS_ABSOLUTE path)
如果给定路径是绝对路径，则为True。

if(<variable|string> MATCHES regex)
如果给定的字符串或变量的值与给定的常规条件匹配，则为true。有关正则表达式格式，请参见正则表达式规范。 ()组被捕获在CMAKE_MATCH_<n> 变量。

if(<variable|string> LESS <variable|string>)
如果给定的字符串或变量的值是有效数字且小于右边的数字，则为true。

if(<variable|string> GREATER <variable|string>)
如果给定的字符串或变量的值是有效数字并且大于右侧的数字，则为true。

if(<variable|string> EQUAL <variable|string>)
如果给定的字符串或变量的值是有效数字并且等于右侧的数字，则为true。

if(<variable|string> LESS_EQUAL <variable|string>)
如果给定的字符串或变量的值是有效数字且小于或等于右侧的数字，则为true。

if(<variable|string> GREATER_EQUAL <variable|string>)
如果给定的字符串或变量的值是有效数字并且大于或等于右侧的数字，则为true。

if(<variable|string> STRLESS <variable|string>)
如果给定的字符串或变量的值在字典上小于右侧的字符串或变量，则为true。

if(<variable|string> STRGREATER <variable|string>)
如果给定的字符串或变量的值在字典上大于右侧的字符串或变量，则为true。

if(<variable|string> STREQUAL <variable|string>)
如果给定的字符串或变量的值在字典上等于右侧的字符串或变量，则为true。

if(<variable|string> STRLESS_EQUAL <variable|string>)
如果给定的字符串或变量的值在字典上小于或等于右侧的字符串或变量，则为true。

if(<variable|string> STRGREATER_EQUAL <variable|string>)
如果给定的字符串或变量的值在字典上大于或等于右侧的字符串或变量，则为true。

if(<variable|string> VERSION_LESS <variable|string>)
按组件的整数版本号比较（版本格式为 major[.minor[.patch[.tweak]]]，省略的组件视为零）。任何非整数版本组件或版本组件的非整数结尾部分均会在该点处有效截断字符串。

if(<variable|string> VERSION_GREATER <variable|string>)
按组件的整数版本号比较（版本格式为 major[.minor[.patch[.tweak]]]，省略的组件视为零）。任何非整数版本组件或版本组件的非整数结尾部分均会在该点处有效截断字符串。

if(<variable|string> VERSION_EQUAL <variable|string>)
按组件的整数版本号比较（版本格式为 major[.minor[.patch[.tweak]]]，省略的组件视为零）。任何非整数版本组件或版本组件的非整数结尾部分均会在该点处有效截断字符串。

if(<variable|string> VERSION_LESS_EQUAL <variable|string>)
按组件的整数版本号比较（版本格式为 major[.minor[.patch[.tweak]]]，省略的组件视为零）。任何非整数版本组件或版本组件的非整数结尾部分均会在该点处有效截断字符串。

if(<variable|string> VERSION_GREATER_EQUAL <variable|string>)
按组件的整数版本号比较（版本格式为 major[.minor[.patch[.tweak]]]，省略的组件视为零）。任何非整数版本组件或版本组件的非整数结尾部分均会在该点处有效截断字符串。

if(<variable|string> IN_LIST <variable>)
如果给定元素包含在命名列表变量中，则为true。

if(DEFINED <name>|CACHE{<name>}|ENV{<name>})
如果<name>定义了具有给定的变量，缓存变量或环境变量，则为true 。变量的值无关紧要。请注意，宏参数不是变量。

if((condition) AND (condition OR (condition)))
首先评估括号内的条件，然后像前面的示例一样评估其余条件。如果有嵌套的括号，则将最里面的括号作为包含它们的条件的一部分进行评估。
————————————————
版权声明：本文为CSDN博主「万俟淋曦」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/maizousidemao/article/details/104099776
```

### 1.3 MSVC

`True` when using Microsoft Visual C++.

Set to `true` when the compiler is some version of Microsoft Visual C++.

当使用Microsoft Visual C++的编译器时MSVC为true。

### 1.4 CMAKE_SOURCE_DIR

The path to the top level of the source tree.

This is **the full path to the top level of the current CMake source tree**. For an in-source build, this would be the same as [`CMAKE_BINARY_DIR`](https://cmake.org/cmake/help/v3.5/variable/CMAKE_BINARY_DIR.html#variable:CMAKE_BINARY_DIR).

When run in -P script mode, CMake sets the variables [`CMAKE_BINARY_DIR`](https://cmake.org/cmake/help/v3.5/variable/CMAKE_BINARY_DIR.html#variable:CMAKE_BINARY_DIR), [`CMAKE_SOURCE_DIR`](https://cmake.org/cmake/help/v3.5/variable/CMAKE_SOURCE_DIR.html?highlight=cmake_source_dir#variable:CMAKE_SOURCE_DIR), [`CMAKE_CURRENT_BINARY_DIR`](https://cmake.org/cmake/help/v3.5/variable/CMAKE_CURRENT_BINARY_DIR.html#variable:CMAKE_CURRENT_BINARY_DIR) and [`CMAKE_CURRENT_SOURCE_DIR`](https://cmake.org/cmake/help/v3.5/variable/CMAKE_CURRENT_SOURCE_DIR.html#variable:CMAKE_CURRENT_SOURCE_DIR) to the current working directory.

就是工程根目录

### 1.5 OPTION

Provides an option that the user can optionally select.

```cmake
option(<option_variable> "help string describing option"
       [initial value])
```

Provide an option for the user to select as `ON` or `OFF`. If no initial value is provided, `OFF` is used.

`OPTION (USE_GL "Enable OpenGL support" ON)`把原工程中使用GL关闭`OPTION (USE_GL "Enable OpenGL support" OFF)`

### 1.6 ADD_DEFINITIONS

### 1.7 [CONFIGURE_FILE](https://cmake.org/cmake/help/v3.5/command/configure_file.html?highlight=configure_file)

Copy a file to another location and modify its contents.

#### Example
Consider a source tree containing a foo.h.in file:

```cmake
#cmakedefine FOO_ENABLE
#cmakedefine FOO_STRING "@FOO_STRING@"
```

An adjacent CMakeLists.txt may use configure_file to configure the header:

```cmake
option(FOO_ENABLE "Enable Foo" ON)
if(FOO_ENABLE)
  set(FOO_STRING "foo")
endif()
configure_file(foo.h.in foo.h @ONLY)
```

This creates a foo.h in the build directory corresponding to this source directory. If the FOO_ENABLE option is on, the configured file will contain:

```c
#define FOO_ENABLE
#define FOO_STRING "foo"
```

Otherwise it will contain:

```c
/* #undef FOO_ENABLE */
/* #undef FOO_STRING */
```

One may then use the include_directories() command to specify the output directory as an include directory:

`include_directories(${CMAKE_CURRENT_BINARY_DIR})`

so that sources may include the header as #include <foo.h>.

## 2. 语法



# MySQL必知必会学习笔记

## 第四章 检索数据（SELECT）

### 4.5 检索不同的行

- **关键词 DISTINCT**

  ```sql
  selset distinct 列名 from 表名;
  ```

  只返回不同（唯一）的`vend_id`行，此关键字必须放在列名前面。

- **注意**

  不能部分使用distinct，当`distinct`应用到多个字段的时候，其应用的范围是其后面的所有字段，而不只是紧挨着它的一个字段，而且`distinct`只能放到所有字段的前面。

### 4.6 限制结果

- **关键词 LIMIT**

  ```sql
  select 列名 from 表名 limit 5；
  ```

  `limit 5`指示返回不多于5行。

  ```sql
  select 列名 from 表名 limit 5,5；
  ```

  `limit 5,5`指示从第5行开始的不多于5行。

- **注意**

  行5是表中第6行，行0是表中第一行；`limit 4 offset 3`等同于`limit 3, 4`。

## 第五章 排序检索数据（ORDER BY）

### 5.3 指定排序方向

- **关键词** 

  ```sql
  select 列名1, 列名2, 列名3 from 表名 
  order by 列名2 desc;
  ```

  Mysql中在不指定排序顺序前提下，以升序排序（A到Z）显示结果，在指定DESC后以降序排序显示结果。

- **注意**

  DESC只应用到直接位于其前面的列名，`order by 列名2 desc, 列名3`，列2降序，在列2中重复的按列3升序排序。DESC相反的是ASC，但是因为默认情况是升序，所以一般用不到。

  在使用order by需要位于from和where之后，使用limit需要在order by之后。

## 第六章 过滤数据 和 第七章 数据过滤（WHERE）

一般对数据库表进行检索时，很少会检索表中所有的行，通常只会根据特定操作或报告的需要提取表数据的子集，只检索所需数据需要指定搜索条件，也称过滤条件。

### 6.2 WHERE子句操作符

|      操作符      |              说明              |
| :--------------: | :----------------------------: |
|        =         |              等于              |
|     !=或者<>     |             不等于             |
|   <、>、<=、>=   | 小于、大于、小于等于、大于等于 |
| BETWEEN...AND... |       在指定的两个值之间       |

#### 		6.2.4 空值检查

- **关键词 NULL** 

  ```sql
  SELECT 列名1 FROM 表名 WHERE 列名2 IS NULL;
  ```

- **注意**

  一定要验证返回数据中确实给出了被过滤的列具有NULL的行。

### 7.1 组合WHERE子句

为了进行更强的过滤控制，可以在WHERE子句中使用AND子句或者OR子句。

#### 		7.1.3 计算次序

在处理OR操作符前，优先处理AND操作符，当然如果有括号就先处理括号中的内容。

### 7.2 **IN 操作符**

IN操作符其实就是OR操作符的集合。

- **关键词 IN** 

  ```sql
  SELECT 列名 FROM 表名 WHERE 列名 IN （数值1，数值2） ORDER BY 列名 DESC;
  ```

- **注意**

  IN操作符比OR操作符执行速度更快；IN的最大优点是可以套娃。

  Mysql中NOT操作符支持对IN、BETWEEN、EXISTS子句取反。

## 第八章 用通配符进行过滤



- **关键词 IN** 

  ```sql
  
  ```

  

- **注意**

  

