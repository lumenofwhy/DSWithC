project(Sort)

# 此处设置目的为练习CMake使用,同时生成动态库与静态库
add_subdirectory(sortAlgorithm/bubbleSort)
add_subdirectory(sortAlgorithm/heapSort)
add_subdirectory(sortAlgorithm/insertSort)
add_subdirectory(sortAlgorithm/mergeSort)
add_subdirectory(sortAlgorithm/quickSort)
add_subdirectory(sortAlgorithm/selectSort)
add_subdirectory(sortAlgorithm/shellSort)
add_subdirectory(sortAlgorithm/radixSort)

# 需要将动态链接库的路径添加到系统环境变量 Path 里或者和程序在同一目录
# 如果没有设置的话，出现的情况就是exe编译成功，运行的时候不执行任何操作就结束
# 设置可执行文件输出路径
# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)


add_executable(${PROJECT_NAME} testSort.c)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/bubbleSort
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/heapSort
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/insertSort
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/mergeSort
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/quickSort
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/selectSort
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/shellSort
        ${PROJECT_SOURCE_DIR}/sortAlgorithm/radixSort
)

# 确定依赖顺序
ADD_DEPENDENCIES(${PROJECT_NAME}
        bubbleSort
        heapSort
        insertSort
        mergeSort
        quickSort
        selectSort
        shellSort
        radixSort
)

# 需要先对依赖库进行编译，再对 Sort 进行编译
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        libbubbleSort.so
        libheapSort.so
        libinsertSort.so
        libmergeSort.so
        libquickSort.so
        libselectSort.so
        libshellSort.so
        libradixSort.so
)

target_link_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/lib
)