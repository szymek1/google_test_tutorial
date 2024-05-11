#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <memory>
#include <stdexcept>
#include <iostream>

class Account {
public:
    explicit Account(int account_number, int money);
    ~Account();

    void depositMoney(int value);
    void withdrewMoney(int value);
    int getBalance() const;
    int getAccountNumber() const;

private:
    struct ImplAccount;
    std::unique_ptr<ImplAccount> pImplAccount; 
};

#endif