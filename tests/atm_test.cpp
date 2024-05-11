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

    // std::shared_ptr<MockBankServer> pMockBankServer = std::make_shared<MockBankServer>();
    // ATM atm = ATM(pMockBankServer);

    EXPECT_CALL(*pMockBankServer, connect());
    EXPECT_CALL(*pMockBankServer, getBalance(account_number))
        .WillOnce(testing::Return(balance));
    EXPECT_CALL(*pMockBankServer, disconnect());

    atm.displayBalance(account_number);
}
