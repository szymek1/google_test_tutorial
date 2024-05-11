#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "account.hpp"


std::vector<std::tuple<int, int>> test_accounts_data = {
    {123456, 10000},
    {123666, 20000},
    {123777, 30000},
    {123888, 5000},
    {123999, 100}
};

class AccountTest: public testing::TestWithParam<
    std::tuple<int, int>> {};

INSTANTIATE_TEST_SUITE_P(
    account_tests,
    AccountTest,
    testing::ValuesIn(test_accounts_data)
);

TEST_P(AccountTest, withdrew_money) {
    auto p = GetParam();
    int number = std::get<0>(p);
    int init_money = std::get<1>(p);
    int money_to_withdrew = 100;

    Account account(number, init_money);
    account.withdrewMoney(money_to_withdrew);

    ASSERT_EQ(account.getBalance(), init_money - money_to_withdrew);
}

TEST_P(AccountTest, add_money) {
    auto p = GetParam();
    int number = std::get<0>(p);
    int money_to_add = std::get<1>(p);
    int init_money = 0;

    Account account(number, init_money);
    account.depositMoney(money_to_add);

    ASSERT_EQ(account.getBalance(), money_to_add);
}

class AccountExcpetionTest: public testing::TestWithParam<
    std::tuple<int, int>> {};

INSTANTIATE_TEST_SUITE_P(
    depositMoneyException,
    AccountExcpetionTest,
    testing::ValuesIn(test_accounts_data)
);

TEST_P(AccountExcpetionTest, add_money_excpetion_throw) {
    auto p = GetParam();
    int number = std::get<0>(p);
    int money_to_add = -1 * std::get<1>(p);
    int init_money = 0;

    Account account(number, init_money);

    ASSERT_THROW(account.depositMoney(money_to_add), std::invalid_argument);
}