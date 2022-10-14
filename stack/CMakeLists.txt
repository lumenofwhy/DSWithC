project(stack)

file(GLOB_RECURSE SOURCES_lstack "src/lstack/*.cpp" "src/lstack/*.c")
file(GLOB_RECURSE SOURCES_seqstack "src/seqstack/*.cpp" "src/seqstack/*.c")



add_executable(${PROJECT_NAME}_lstack ${SOURCES_lstack})
add_executable(${PROJECT_NAME}_seqstack ${SOURCES_seqstack})



target_include_directories(${PROJECT_NAME}_lstack
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_seqstack
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
