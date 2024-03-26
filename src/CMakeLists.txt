set(SRC_FILES
    node_impl.cpp
    stack_impl.cpp
    stack_utils.cpp
)

add_library(tutorial_lib ${SRC_FILES})

target_include_directories(tutorial_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)