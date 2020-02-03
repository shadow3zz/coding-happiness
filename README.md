[TOC]

# WSL-Ubuntu 16.04环境配置

## 1.设置[清华源](https://mirrors.tuna.tsinghua.edu.cn/help/ubuntu/)

- 备份官方源source.list

    `sudo cp /etc/tmp/source.list /etc/tmp/source.list.backup`

- 替换`source.list`内容

    ```
    sudo vi /etc/tmp/source.list
    # 在vi中将原内容删除esc+dG，然后将清华源内容复制到文本中

    # 保存后，执行以下内容
    sudo apt update
    sudo apt list -upgradable
    sudo apt upgrade
    # 等待一段时间后更新完成
    ```

- 清华源

    ```
    # 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-updates main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-backports main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-security main restricted universe multiverse

    # 预发布软件源，不建议启用
    # deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-proposed main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ xenial-proposed main restricted universe multiverse
    ```

## 2.相关工具和IDE

- 安装cmake

    `sudo apt install cmake`

- 检查gcc，g++版本

    `gcc --version`

    `g++ --version`

    如果没有安装g++，执行`sudo apt install g++`

- 安装并启动vscode

    由于wsl是windows系统中的一部分，这里安装vscode很简单，只要直接输入命令`code ./`，就可以自动安装。

## 实践

    参考https://github.com/JingruiLea/CppProjectTemplate用例



## 遗留问题

    如何配置调试？

    需要将wxWidgets编译安装，并做到第三方引用。

# 使用 Visual Studio Code 搭建 C/C++ 开发和调试环境

## 1.开发和调试环境配置

- 在Linux中安装gdb

     `sudo apt install gdb`

- 新建工程

    新建如下工程模板[CppTemplate](https://blog.csdn.net/zhulinmanbu114/article/details/90754803)：

    ```
    .
    ├── bin
    ├── build
    ├── CMakeLists.txt
    ├── include
    │   └── utils.h
    └── src
        ├── CMakeLists.txt
        ├── main.cpp
        └── utils.cpp
    ```

    通过配置`./CMakeLists.txt`实现 CMake 编译，内容如下：

    ```cmake
    CMAKE_MINIMUM_REQUIRED(VERSION 2.8) # cmake最低版本要求

    PROJECT(CppTemplate)    # 工程名 CppTemplate

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # 添加c++11标准支持

    SET(CMAKE_C_COMPILER "/usr/bin/gcc") # 默认c编译器
    SET(CMAKE_CXX_COMPILER "/usr/bin/g++") # 默认c++编译器

    SET(CMAKE_BUILD_TYPE "Debug")  # Debug模式 选项: Release Debug MinSizeRel RelWithDebInfo

    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")  # debug模式下 gdb相关选项
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall") # release模式下 gdb相关选项

    # set(CMAKE_VERBOSE_MAKEFILE ON) # 开启调试 出现问题时开启

    # enable_testing() # �打开测试

    add_definitions(-DDEBUG) # 相当于代码中 #define DEBUG

    # add_subdirectory(test) # 添加test子目录

    SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin") # 可执行文件输出目录
    
    INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include") # 头文件包含目录

    # 这段代码可以区分操作系统
    MESSAGE("Identifying the OS...")
    if(WIN32)
    MESSAGE("This is Windows.")
    elseif(APPLE)
    MESSAGE("This is MacOS.")
    elseif(UNIX)
    MESSAGE("This is Linux.")
    endif()
    # 这段代码可以区分操作系统

    AUX_SOURCE_DIRECTORY(src DIR_SRCS) # 添加源代码文件夹, 自动扫描所有文件

    add_executable(chess  # 输出名为chess的可执行文件
    ${DIR_SRCS}
    )
    # 也可以这么写
    # add_executable(chess  # 输出名为chess的可执行文件
    #    ./src/main.cpp
    #    ./src/utils.cpp
    # )
    ```

    `src/main.cpp`

    ```c++
    #include "utils.h"
    #include <vector>
    using namespace std;

    int main(int argc, char const* argv[]) {
        for(int i=0;i<9;i++){
            cout << "Hello" << endl;
        }
        vector<std::string> msg{"a","b","c"};
        for (auto s:msg)
        {
            printf(s);
        }
        return 0; 
    }
    ```

    `src/utils.cpp`和`include/utils.h`

    ```c++
    #pragma once
    #include <iostream>
    #include <string>
    //单元测试时编写
    void printf(std::string& str);

    #include "utils.h"
    //单元测试时编写
    void printf(std::string& str)
    {
        std::cout << str << " ";
    }
    ```

    - 在vscode中安装cmake和cmake tool插件，然后编译

    ```bash
    cd build
    cmake ..
    make
    ```

    或者直接在cmake插件栏中生成

    - 配置vscode中task.json和launch.json文件

    ```json
    {
        // launch.json
        // 使用 IntelliSense 了解相关属性。 
        // 悬停以查看现有属性的描述。
        // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
        "version": "0.2.0",
        "configurations": [
            {
                "name": "g++ build and debug active file",
                "type": "cppdbg",
                "request": "launch",
                "program": "${workspaceRoot}/bin/chess",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "externalConsole": false,
                "MIMode": "gdb",
                "setupCommands": [
                    {
                        "description": "为 gdb 启用整齐打印",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ],
                "preLaunchTask": "make",
                "miDebuggerPath": "/usr/bin/gdb"
            }
        ]
    }
    //////////////////////////////////////
    {
        "version": "2.0.0",
        "options": {
            "cwd": "${workspaceRoot}/build"
        },/////////////////////////////////////////////////这个要加上，否则编译出问题
        "tasks": [
            {
                "label": "cmake",
                "type": "shell",
                "command": "cmake",
                "args": [
                    "-G",
                    "Unix Makefiles",
                    "-DCMAKE_BUILD_TYPE=Debug",
                    ".."
                ]
            },
            {
                "label": "make",/////////////////////// 下面的make就是这里
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "type": "shell",
                "command": "make",
                "args": []
            }
            
        ]
    }
    ```

- 断点调试

    断点 - F5（启动调试）- F10（逐步调试）
    （在F5之前，要提前用命令行cmake make一下）

    执行cmake 生成 makefile。

    执行make 根据生成的 makefile 来编译构建程序。

    在代码中设置断点。

    执行 debug，程序便会在断点处中断

## 2.第三方库加载-wxWidgets

### wxWidgets安装

有两种选择

①安装wxWidgets3.0.1[csdn](https://blog.csdn.net/qq_32768743/article/details/83220719)

    `sudo apt install libwxgtk3.0-dev`

②安装wxWidgets3.1.2[codelite](https://wiki.codelite.org/pmwiki.php/Main/WxWidgets312Binaries)

```bash
# 这些软件包都使用CodeLite公钥签名，应通过以超级用户身份（取决于您的发行版为su或sudo）来告知apt：
sudo apt-key adv --fetch-keys http://repos.codelite.org/CodeLite.asc
# 将url添加到/etc/apt/sources.list
sudo apt-add-repository 'deb http://repos.codelite.org/wx3.1.2/ubuntu/ eoan universe'

sudo apt update
# GTK+2
sudo apt-get install libwxbase3.1-0-unofficial \
                 libwxbase3.1-dev \
                 libwxgtk3.1-0-unofficial \
                 libwxgtk3.1-dev \
                 wx3.1-headers \
                 wx-common \
                 libwxgtk-webview3.1-0-unofficial \
                 libwxgtk-webview3.1-dev \
                 libwxgtk-media3.1-0-unofficial \
                 libwxgtk-media3.1-dev \
                 libwxbase3.1-0-unofficial-dbg \
                 libwxgtk3.1-0-unofficial-dbg \
                 libwxgtk-webview3.1-0-unofficial-dbg \
                 libwxgtk-media3.1-0-unofficial-dbg \
                 wx3.1-i18n \
                 wx3.1-examples
# GTK+3
sudo apt-get remove libwxbase3.1-0-unofficial3 \
                 libwxbase3.1unofficial3-dev \
                 libwxgtk3.1-0-unofficial3 \
                 libwxgtk3.1unofficial3-dev \
                 wx3.1-headers \
                 wx-common \
                 libwxgtk-media3.1-0-unofficial3 \
                 libwxgtk-webview3.1-0-unofficial3 \
                 libwxgtk-webview3.1unofficial3-dev \
                 libwxbase3.1-0-unofficial3-dbg \
                 libwxgtk3.1-0-unofficial3-dbg \
                 libwxgtk-webview3.1-0-unofficial3-dbg \
                 libwxgtk-media3.1-0-unofficial3-dbg \
                 wx3.1-i18n \
                 wx3.1-examples
```

③**vcpkg**

## 3.第三方库-boost

### 安装

```bash
sudo apt-cache search boost
sudo apt-get install libboost-all-dev
```

### CMakeLists.txt中配置

```cmake
# 利用cmake添加boost库
....
find_package(Boost REQUIRED COMPONENTS system filesystem)
if(NOT Boost_FOUND)
    message("Not found Boost")
endif()
message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARIES}")
...
# 需要添加-lboost_system避免报错
target_link_libraries(chess -lboost_system ${Boost_LIBRARIES})
```

### 测试用例一boostTest.h和boostTest.cpp

```c++
#pragma once
#include <boost/filesystem/path.hpp> 
#include <boost/filesystem/operations.hpp>
#include <string>

std::string newPrint(std::string str);

class Test
{
public:
    Test(){};
    ~Test(){};
    inline std::string testBack(){
        chessPath = boost::filesystem::initial_path<boost::filesystem::path>().string();
        return chessPath;
    }
private:
    std::string chessPath;
```

```c++
#include "boostTest.h"

std::string newPrint(std::string str)
{
    return str;
}
```

## 遗留问题：

    多线程相关知识

    wxwidgets在vscode中的使用问题 [wxWidgets and VSCode](http://wxwidgets.10942.n7.nabble.com/wxWidgets-and-VSCode-td93506.html)

# day 3

## 安装wxWidgets

### 1 配置vcpkg来安装 不可行

失败！！！！！

遗憾的一天 玩了一下午游戏

### 2 根据openCPN中的方法 可行

```bash
sudo apt-get install build-essential cmake gettext git-core gpsd gpsd-clients libgps-dev wx-common libwxgtk3.0-dev libglu1-mesa-dev libgtk2.0-dev wx3.0-headers libbz2-dev libtinyxml-dev libportaudio2 portaudio19-dev libcurl4-openssl-dev libexpat1-dev libcairo2-dev libarchive-dev liblzma-dev libexif-dev libelf-dev libsqlite3-dev
```

- 配置cmakelists.txt和c_cpp_properties.json

  ```cmake
  find_package(wxWidgets COMPONENTS core base ..)
  if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
    # and for each of your dependent executable/library targets:
    target_link_libraries(main ${wxWidgets_LIBRARIES})
    message("${wxWidgets_INCLUDE_DIRS}")
  endif()
  ```

  ```json
  {
      "configurations": [
          {
              "name": "Linux",
              "includePath": [
                  "${workspaceFolder}/**",
                  "${vcpkgRoot}/x64-linux/include",
                  "/usr/include/wx-3.0/",
                  "/usr/lib/x86_64-linux-gnu/wx/include/gtk2-unicode-3.0"
              ],
              "defines": [],
              "compilerPath": "/usr/bin/gcc",
              "cStandard": "c11",
              "cppStandard": "c++17",
              "intelliSenseMode": "gcc-x64"
          }
      ],
      "version": 4
  }
  ```

    添加头文件测试\#include <wx/wx.h> 

        wxString msg(wxT("ready!"));

        std::cout << "测试wxwidgets：" << msg.mb_str() << std::endl;