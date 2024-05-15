#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "atm.hpp"
#include "mock_bank_server.hpp"


/**
 * @brief Data structure defining input
 * @arg test_accounts_data- tuple holding [account number, money]
 */
std::vector<std::tuple<int, int>> test_accounts_data_atm = {
    {123456, 10000},
    {123666, 20000},
    {123777, 30000},
    {123888, 5000},
    {123999, 100}
};

class ATMTest: public testing::TestWithParam<std::tuple<int, int>> {
protected:
  ATM atm;
  std::shared_ptr<MockBankServer> pMockBankServer;

  ATMTest(): atm(nullptr) {};

  void SetUp() override {
    pMockBankServer = std::make_shared<MockBankServer>();
    atm = ATM(pMockBankServer);
  }
};

INSTANTIATE_TEST_SUITE_P(
    atm_test,
    ATMTest,
    testing::ValuesIn(test_accounts_data_atm)
);

TEST_P(ATMTest, getBalanaceTest) {
    auto p = GetParam();
    int account_number = std::get<0>(p);
    int balance = std::get<1>(p);  

    EXPECT_CALL(*pMockBankServer, connect());
    EXPECT_CALL(*pMockBankServer, getBalance(account_number))
        .WillOnce(testing::Return(balance));
    EXPECT_CALL(*pMockBankServer, disconnect());

    atm.displayBalance(account_number);
}

TEST_P(ATMTest, addMoneyTest) {
    auto p = GetParam();
    int account_number = std::get<0>(p);
    int money2add = std::get<1>(p);

    EXPECT_CALL(*pMockBankServer, connect());
    EXPECT_CALL(*pMockBankServer, credit(account_number, money2add))
      .WillOnce(testing::Return());
    EXPECT_CALL(*pMockBankServer, disconnect());

    ASSERT_EQ(atm.addMoney(account_number, money2add), true);
}

TEST_P(ATMTest, doubel_transaction_3_times_fail_test) {
    auto p = GetParam();
    int account_number = std::get<0>(p);
    int val_1 = std::get<1>(p);
    int val_2 = std::get<1>(p) + 1;

    EXPECT_CALL(*pMockBankServer, connect());
    ON_CALL(*pMockBankServer, 
      doubleTransaction(account_number, val_1, val_2))
        .WillByDefault(testing::Return(false));
    EXPECT_CALL(*pMockBankServer, doubleTransaction(account_number, val_1, val_2))
        .Times(3);
    EXPECT_CALL(*pMockBankServer, disconnect());

    ASSERT_FALSE(atm.doubleTransaction(account_number, val_1, val_2));
}

TEST_P(ATMTest, doubel_transaction_2_times_fail_then_pass_test) {
    auto p = GetParam();
    int account_number = std::get<0>(p);
    int val_1 = std::get<1>(p);
    int val_2 = std::get<1>(p) + 1;

    EXPECT_CALL(*pMockBankServer, connect());
    EXPECT_CALL(*pMockBankServer, 
      doubleTransaction(account_number, val_1, val_2))
        .WillOnce(testing::Return(false))
        .WillOnce(testing::Return(false))
        .WillOnce(testing::Return(true));
    EXPECT_CALL(*pMockBankServer, disconnect());

    ASSERT_TRUE(atm.doubleTransaction(account_number, val_1, val_2));
}