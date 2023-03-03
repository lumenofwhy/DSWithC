cmake_minimum_required(VERSION 3.0.0)
# 设置C编译器
set(CMAKE_C_COMPILER "gcc")
# 设置C++编译器
set(CMAKE_CXX_COMPILER "g++")
# 设置安装位置
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

project(DS VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=utf-8")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=utf-8")

#tt
add_subdirectory(${CMAKE_SOURCE_DIR}/list) # 表
add_subdirectory(${CMAKE_SOURCE_DIR}/linkList) # 链表
add_subdirectory(${CMAKE_SOURCE_DIR}/queue) # 队列
add_subdirectory(${CMAKE_SOURCE_DIR}/stack) # 栈
add_subdirectory(${CMAKE_SOURCE_DIR}/strings) # 串
add_subdirectory(${CMAKE_SOURCE_DIR}/hashTable) # 哈希
add_subdirectory(${CMAKE_SOURCE_DIR}/tree) # 树
add_subdirectory(${CMAKE_SOURCE_DIR}/sort) # 排序