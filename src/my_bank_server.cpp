#include "my_bank_server.hpp"


void MyBankServer::connect() {
    std::cout << "Server connected" << std::endl;
}

void MyBankServer::disconnect() {
    std::cout << "Server disconnected" << std::endl;
}

void MyBankServer::credit(int account_number, int value) {
    std::cout << "Adding: " << value << " $ to account: " << account_number << std::endl;
}

void MyBankServer::debit(int account_number, int value) {
    std::cout << "Withdrawing: " << value << " $ from account: " << account_number << std::endl;
}

bool MyBankServer::doubleTransaction(int account_number, int value_1, int value_2) {
    bool isTransaction = false;
    std::cout << "Transaction details:\nNumber: " << account_number 
    << "\nValue 1: " << value_1 << "\nValue 2: " << value_2 << std::endl;
    isTransaction = true;
    return isTransaction;
}

int MyBankServer::getBalance(int account_number) const {
    int balance = 1000;
    std::cout << balance << std::endl;
}