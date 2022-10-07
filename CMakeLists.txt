# 设置C编译器
set(CMAKE_C_COMPILER "gcc")

# 设置C++编译器
set(CMAKE_CXX_COMPILER "g++")

# -Wall -g
# add_compile_options(-g -fexec-charset=GBK)
add_compile_options(-g)
cmake_minimum_required(VERSION 3.0.0)
project(DS VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(${CMAKE_SOURCE_DIR}/list) # 表
add_subdirectory(${CMAKE_SOURCE_DIR}/linkList) # 链表
add_subdirectory(${CMAKE_SOURCE_DIR}/queue) # 队列
add_subdirectory(${CMAKE_SOURCE_DIR}/stack) # 栈
add_subdirectory(${CMAKE_SOURCE_DIR}/strings) # 串
add_subdirectory(${CMAKE_SOURCE_DIR}/hashTable) # 哈希
add_subdirectory(${CMAKE_SOURCE_DIR}/tree) # 树
add_subdirectory(${CMAKE_SOURCE_DIR}/sort/radixSort) # 基数排序