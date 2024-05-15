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

bool ATM::doubleTransaction(int account_number, int value_1, int value_2) {
    int patienceThreshold = 0;
    bool isDoubleTransaction = false;

    _pBankServer->connect();
    
    do {
        isDoubleTransaction = _pBankServer->doubleTransaction(account_number, value_1, value_2);
        if (isDoubleTransaction == true) {  break; }
        patienceThreshold++;
    } while (patienceThreshold < 3);


    _pBankServer->disconnect();

    return isDoubleTransaction;
}
