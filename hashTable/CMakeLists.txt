project(hashTable_structure)

set(SOURCES_hashOpen
    hashOpen.c
    testHashOpen.c
)

set(SOURCES_hashLink
    hashLinkList.c
    testHashLinkList.c
)

add_executable(${PROJECT_NAME} ${SOURCES_hashOpen})

# add_executable(${PROJECT_NAME} ${SOURCES_hashLink})
