#include <gtest/gtest.h>

#include "hello.hpp"


TEST(HelloClassTest, ConstructorInitTest) {
    std::string worker_name = "Marcin";
    utility::Hello worker(worker_name, 23);

    EXPECT_EQ(worker.sayName(), "Marcin");
}

TEST(HelloClassTest, NameAgeTest) {
    std::string worker_name = "Wojciech";
    utility::Hello worker(worker_name, 28);

    ASSERT_EQ(worker.sayName(), "Wojciech");
    ASSERT_EQ(worker.getAge(), 28);
}

TEST(HelloClassTest, ConstructorInitTest2) {
    std::string worker_name = "Alicja";
    utility::Hello worker(worker_name, 23);
    EXPECT_EQ(worker.sayName(), "Alicja");
}