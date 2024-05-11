#ifndef MY_BANK_SERVER_HPP
#define MY_BANK_SERVER_HPP

#include <iostream>

#include "bank_server.hpp"
#include "account.hpp"


class MyBankServer: public BankServer {
public:
    MyBankServer() = default;
    ~MyBankServer() = default;
    void connect();
    void disconnect();
    void credit(int account_number, int value);
    void debit(int account_number, int value);
    bool doubleTransaction(int account_number, int value_1, int value_2);
    int getBalance(int account_number) const;
};

#endif