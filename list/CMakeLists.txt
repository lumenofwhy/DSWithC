project(list)

file(GLOB_RECURSE SOURCES_sqlist "src/sqlist/*.cpp" "src/sqlist/*.c")
file(GLOB_RECURSE SOURCES_dsqlist "src/dsqlist/*.cpp" "src/dsqlist/*.c")

add_executable(${PROJECT_NAME}_sqlist ${SOURCES_sqlist})
add_executable(${PROJECT_NAME}_dsqlist ${SOURCES_dsqlist})


target_include_directories(${PROJECT_NAME}_sqlist
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_dsqlist
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# add_executable(${PROJECT_NAME} ${SOURCES_sqlist})
