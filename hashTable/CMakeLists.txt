project(hashTable)

file(GLOB_RECURSE SOURCES_hashlinklist "src/hashlinklist/*.cpp" "src/hashlinklist/*.c")
file(GLOB_RECURSE SOURCES_hashopen "src/hashopen/*.cpp" "src/hashopen/*.c")



add_executable(${PROJECT_NAME}_hashlinklist ${SOURCES_hashlinklist})
add_executable(${PROJECT_NAME}_hashopen ${SOURCES_hashopen})



target_include_directories(${PROJECT_NAME}_hashlinklist
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_hashopen
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
