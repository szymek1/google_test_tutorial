#include <iostream>
#include <chrono>
#include <string>

#include <gtest/gtest.h>

#include "stack_impl.hpp"


class StackTest : public ::testing::Test {
protected:
    
    static void SetUpTestSuite() {
        if (expensive_object == nullptr) {
            expensive_object = new std::string("Im shared a resource");
        }
        std::cout << *expensive_object << std::endl;
    }

    static void TearDownTestSuite() {
        std::cout << "Finishing all tests" << std::endl;
        delete expensive_object;
        expensive_object = nullptr;
    }
    

    void SetUp() override {
        char letters[5] = {'a', 'b', 'c', 'd', 'e'};

        start_time_ms = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < 5; i++) {
            s_correct.push(letters[i]);
        }

    }

    void TearDown() override {
        auto end_time_ms = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            end_time_ms - start_time_ms
        );
        std::cout << "==== TESTS FINISHED " << duration.count() <<" ms ====" << std::endl;
    }

    StackImpl s_correct;
    StackImpl s_corrupt;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_ms;

    static std::string* expensive_object; // shared by all tests
};

std::string* StackTest::expensive_object = nullptr;

/*=============== TESTS BEGIN BELOW =====================*/

TEST_F(StackTest, TestTop) {
    EXPECT_EQ(s_correct.top(), 'e');
    EXPECT_THROW(s_corrupt.top(), std::runtime_error);
}

TEST_F(StackTest, TestIsEmpty) {
    ASSERT_TRUE(s_corrupt.isEmpty());
}

TEST_F(StackTest, TestPop) {
    int i = 0;
    while (i < 5) {
        s_correct.pop();
        i++;
    }

    ASSERT_TRUE(s_correct.isEmpty());
    EXPECT_THROW(s_correct.top(), std::runtime_error);
}
