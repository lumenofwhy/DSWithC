project(Sort)

# 此处设置目的为练习CMake使用
add_subdirectory(bubbleSort)
add_subdirectory(heapSort)
add_subdirectory(insertSort)
add_subdirectory(mergeSort)
add_subdirectory(quickSort)
add_subdirectory(selectSort)
add_subdirectory(shellSort)
add_subdirectory(radixSort)

add_executable(${PROJECT_NAME} testSort.c)

target_link_libraries(${PROJECT_NAME}
    bubbleSort
    heapSort
    insertSort
    mergeSort
    quickSort
    selectSort
    shellSort
    radixSort
)