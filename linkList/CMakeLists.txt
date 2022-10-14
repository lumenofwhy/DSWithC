project(linkList)

file(GLOB_RECURSE SOURCES_clist "src/clist/*.cpp" "src/clist/*.c")
file(GLOB_RECURSE SOURCES_dlist "src/dlist/*.cpp" "src/dlist/*.c")
file(GLOB_RECURSE SOURCES_linkedlist "src/linkedlist/*.cpp" "src/linkedlist/*.c")
file(GLOB_RECURSE SOURCES_poly "src/poly/*.cpp" "src/poly/*.c")
file(GLOB_RECURSE SOURCES_josephus "src/josephus/*.cpp" "src/josephus/*.c")


add_executable(${PROJECT_NAME}_clist ${SOURCES_clist})
add_executable(${PROJECT_NAME}_dlist ${SOURCES_dlist})
add_executable(${PROJECT_NAME}_linkedlist ${SOURCES_linkedlist})
add_executable(${PROJECT_NAME}_poly ${SOURCES_poly})
add_executable(${PROJECT_NAME}_josephus ${SOURCES_josephus})


target_include_directories(${PROJECT_NAME}_clist
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_dlist
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_linkedlist
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_poly
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_josephus
PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
