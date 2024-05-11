#include "account.hpp"


struct Account::ImplAccount {

    ImplAccount(int account_number, int money) 
        : _account_number(account_number), _money(money) {};
    ~ImplAccount() = default;

    int getMoney() const {
        return _money;
    };

    void addMoney(int value) {
        if (value > 0) {
        _money = _money + value;
        } else {
            throw std::invalid_argument("Given value cannot be negative");
        }
    }

    void withdrewMoney(int value) {
        if ((value > 0) && (_money >= value)) {
            _money = _money - value;
        } else {
            std::cout << "Not enough money to withdrew: " << value << std::endl;
        }
    }

    int getAccountNumber() const {
        return _account_number;
    };

private:
    int _money;
    int _account_number;

};

Account::Account(int account_number, int money) 
    : pImplAccount(std::make_unique<ImplAccount>(account_number, money)) {}

Account::~Account() = default;

void Account::depositMoney(int value) {
    pImplAccount->addMoney(value);
}

void Account::withdrewMoney(int value) {
    pImplAccount->withdrewMoney(value);
}

int Account::getBalance() const {
    return pImplAccount->getMoney();
}

int Account::getAccountNumber() const {
    return pImplAccount->getAccountNumber();
}
