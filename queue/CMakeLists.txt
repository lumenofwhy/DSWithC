project(queue_structure)

set(SOURCES_listqueue
    listqueue.c
    testListqueue.c

    # testSqqueue.c
)

set(SOURCES_sqqueue
    sqqueue.c
    testSqqueue.c
)

add_executable(${PROJECT_NAME} ${SOURCES_listqueue})

# add_executable(${PROJECT_NAME} ${SOURCES_sqqueue})
