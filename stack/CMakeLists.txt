project(stack_structure)

set(SOURCES_lstack
    lstack.c
    testLstack.c
)

set(SOURCES_seqstack
    seqstack.c
    testSeqstack.c
)

add_executable(${PROJECT_NAME} ${SOURCES_lstack})

# add_executable(${PROJECT_NAME} ${SOURCES_seqstack})
