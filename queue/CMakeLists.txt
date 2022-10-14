project(queue)

file(GLOB_RECURSE SOURCES_listqueue "src/listqueue/*.cpp" "src/listqueue/*.c")
file(GLOB_RECURSE SOURCES_sqqueue "src/sqqueue/*.cpp" "src/sqqueue/*.c")



add_executable(${PROJECT_NAME}_listqueue ${SOURCES_listqueue})
add_executable(${PROJECT_NAME}_sqqueue ${SOURCES_sqqueue})



target_include_directories(${PROJECT_NAME}_listqueue
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME}_sqqueue
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
