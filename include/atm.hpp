#ifndef ATM_HPP
#define ATM_HPP

#include <memory>

#include "bank_server.hpp"


class ATM {
public:
    explicit ATM(std::shared_ptr<BankServer> server);
    ~ATM();

    bool withdrewMoney(int account_number, int value);
    bool addMoney(int account_number, int value);
    void displayBalance(int account_number) const;
    bool doubleTransaction(int account_number, int value_1, int value_2);

private:
    std::shared_ptr<BankServer> _pBankServer;
};

#endif
