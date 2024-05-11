#include "atm.hpp"
#include "account.hpp"

/*
ATM::ATM(std::unique_ptr<BankServer> server) 
    : _pBankServer(std::move(server)) {}
*/
ATM::ATM(std::shared_ptr<BankServer> server) 
    : _pBankServer(server) {}
ATM::~ATM() = default;

bool ATM::withdrewMoney(int account_number, int value) {
    bool isWithdrew = false;

    _pBankServer->connect();
    _pBankServer->debit(account_number, value);
    isWithdrew = true;
    _pBankServer->disconnect();

    return isWithdrew;
}

bool ATM::addMoney(int account_number, int value) {
    bool isAdd = false;

    _pBankServer->connect();
    _pBankServer->credit(account_number, value);
    isAdd = true;
    _pBankServer->disconnect();

    return isAdd;
}

void ATM::displayBalance(int account_number) const {
    _pBankServer->connect();
    std::cout << _pBankServer->getBalance(account_number) << std::endl;
    _pBankServer->disconnect();
}
