# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

file(GLOB allCopyFiles "quickSort.h")
file(COPY ${allCopyFiles} DESTINATION ${PROJECT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)

add_library(quickSort SHARED ${DIR_LIB_SRCS})
SET_TARGET_PROPERTIES(quickSort PROPERTIES CLEAN_DIRECT_OUTPUT 1)

add_library(quickSort_static STATIC ${DIR_LIB_SRCS})
SET_TARGET_PROPERTIES(quickSort_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(quickSort_static PROPERTIES OUTPUT_NAME "quickSort")

set_target_properties(quickSort PROPERTIES VERSION 1.2 SOVERSION 2)


# set_target_properties(quickSort PROPERTIES PUBLIC_HEADER quickSort.h)

# INSTALL(TARGETS quickSort quickSort_static
#         LIBRARY DESTINATION sort/install/lib# 动态库
#         ARCHIVE DESTINATION sort/install/lib# 静态库
#         PUBLIC_HEADER DESTINATION sort/install/include/quickSort
# )
