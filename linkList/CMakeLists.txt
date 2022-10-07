project(linkList_structure)

set(SOURCES_clist
    clist.c
    testClist.c
)

set(SOURCES_dlist
    dlist.c
    testClist.c
)

set(SOURCES_linkedlist
    linkedlist.c
    testClist.c
)

set(SOURCES_poly
    poly.c
    testClist.c
)

add_executable(${PROJECT_NAME} ${SOURCES_clist})

# add_executable(${PROJECT_NAME} ${SOURCES_dlist})
# add_executable(${PROJECT_NAME} ${SOURCES_linkedlist})
# add_executable(${PROJECT_NAME} ${SOURCES_poly})
