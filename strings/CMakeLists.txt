project(strings)

file(GLOB_RECURSE SOURCES_string "src/string/*.cpp" "src/string/*.c")

add_executable(${PROJECT_NAME}_string ${SOURCES_string})


target_include_directories(${PROJECT_NAME}_string
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
