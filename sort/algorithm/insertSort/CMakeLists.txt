# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

file(GLOB allCopyFiles "insertSort.h")
file(COPY ${allCopyFiles} DESTINATION ${PROJECT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)

add_library(insertSort SHARED ${DIR_LIB_SRCS})
SET_TARGET_PROPERTIES(insertSort PROPERTIES CLEAN_DIRECT_OUTPUT 1)

add_library(insertSort_static STATIC ${DIR_LIB_SRCS})
SET_TARGET_PROPERTIES(insertSort_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(insertSort_static PROPERTIES OUTPUT_NAME "insertSort")

set_target_properties(insertSort PROPERTIES VERSION 1.2 SOVERSION 2)



# set_target_properties(insertSort PROPERTIES PUBLIC_HEADER insertSort.h)

# INSTALL(TARGETS insertSort insertSort_static
#         LIBRARY DESTINATION sort/install/lib# 动态库
#         ARCHIVE DESTINATION sort/install/lib# 静态库
#         PUBLIC_HEADER DESTINATION sort/install/include/insertSort
# )
