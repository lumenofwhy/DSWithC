# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

file(GLOB allCopyFiles "bubbleSort.h")
file(COPY ${allCopyFiles} DESTINATION ${PROJECT_SOURCE_DIR}/include)

set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)

add_library(bubbleSort SHARED ${DIR_LIB_SRCS})
SET_TARGET_PROPERTIES(bubbleSort PROPERTIES CLEAN_DIRECT_OUTPUT 1)

add_library(bubbleSort_static STATIC ${DIR_LIB_SRCS})
SET_TARGET_PROPERTIES(bubbleSort_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(bubbleSort_static PROPERTIES OUTPUT_NAME "bubbleSort")

set_target_properties(bubbleSort PROPERTIES VERSION 1.2 SOVERSION 2)


# set_target_properties(bubbleSort PROPERTIES PUBLIC_HEADER bubbleSort.h)

# INSTALL(TARGETS bubbleSort bubbleSort_static
#         RUNTIME DESTINATION sort/install/bin # executables and dll on Win  ////new
#         LIBRARY DESTINATION sort/install/lib # shared libraries
#         ARCHIVE DESTINATION sort/install/lib # static libraries
#         PUBLIC_HEADER DESTINATION sort/install/include/bubbleSort # public headers
# )
