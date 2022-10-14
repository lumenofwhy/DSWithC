project(tree)

file(GLOB_RECURSE SOURCES_bittree "src/bittree/*.cpp" "src/bittree/*.c")

add_executable(${PROJECT_NAME}_bittree ${SOURCES_bittree})

target_include_directories(${PROJECT_NAME}_bittree
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
