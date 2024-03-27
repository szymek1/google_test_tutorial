if(BUILD_TESTING)
    add_executable(project_tests my_stack_impl_test.cpp my_stack_utils_test.cpp my_stack_utils_func_combs_test.cpp)
    target_link_libraries(project_tests PRIVATE tutorial_lib GTest::gtest_main)
    
    include(GoogleTest)
    gtest_discover_tests(project_tests)
endif()