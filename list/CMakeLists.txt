project(list_structure)

set(SOURCES_dsqlist
    dsqlist.c
    testDsqlist.c
)

set(SOURCES_sqlist
    sqlist.c
    testSqlist.c
)

add_executable(${PROJECT_NAME} ${SOURCES_dsqlist})

# add_executable(${PROJECT_NAME} ${SOURCES_sqlist})
