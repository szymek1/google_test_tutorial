#ifndef MOCK_BANK_SERVER_HPP
#define MOCK_BANK_SERVER_HPP

#include <gmock/gmock.h>

#include "bank_server.hpp"


class MockBankServer: public BankServer {
public:
    MOCK_METHOD(void, connect, (), (override));
    MOCK_METHOD(void, disconnect, (), (override));
    MOCK_METHOD(void, credit, (int account_number, int value), (override));
    MOCK_METHOD(void, debit, (int account_number, int value), (override));
    MOCK_METHOD(bool, doubleTransaction, (int account_number, int value_1, int value_2), (override));
    MOCK_METHOD(int, getBalance, (int account_number), (const, override));
};

#endif 