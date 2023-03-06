# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

set(LIB_NAME "insertSort")

# 拷贝头文件到可执行文件目录
# file(GLOB allCopyFiles ${LIB_NAME}.h)
# file(COPY ${allCopyFiles} DESTINATION ${PROJECT_SOURCE_DIR}/sortAlgorithm/include)

# 生成动态库
add_library(${LIB_NAME} SHARED ${DIR_LIB_SRCS})
# 生成静态库
add_library(${LIB_NAME}_static STATIC ${DIR_LIB_SRCS})


# 设置库文件保存路径
set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)
# 指定静态库的输出名称
set_target_properties(${LIB_NAME}_static PROPERTIES OUTPUT_NAME ${LIB_NAME})
# 使动态库和静态库同时存在
set_target_properties(${LIB_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(${LIB_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)


# 指定动态库版本
# VERSION 动态库版本
# SOVERSION API版本
# set_target_properties(person PROPERTIES VERSION 1.0 SOVERSION 1)

# 将动态库与动态库同时安装到lib目录中

# 将头文件和共享库安装到指定目录
set_target_properties(${LIB_NAME} PROPERTIES PUBLIC_HEADER ${LIB_NAME}.h)

INSTALL(TARGETS ${LIB_NAME} ${LIB_NAME}_static
        RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/output/bin # executables and dll on Win
        LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/output/lib # shared libraries
        ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/output/lib # static libraries
        PUBLIC_HEADER DESTINATION ${PROJECT_SOURCE_DIR}/output/include/ # public headers
)