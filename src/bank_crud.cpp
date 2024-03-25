#include "bank_crud.hpp"


bool BankingClass::CreateAccount(int accountNumber, double initialBalance) {
  // Implement logic to check for existing account number and create a new entry in the data structure
  if (!std::is_integral<decltype(accountNumber)>::value) {
        throw std::invalid_argument("Account number must be an integer");
  }
  if (accounts_.count(accountNumber) > 0) {
    return false; // Account already exists
  }
  accounts_[accountNumber] = initialBalance;
  return true;
}

double BankingClass::GetBalance(int accountNumber) const {
  // Implement logic to check for existing account and return balance
  if (accounts_.count(accountNumber) == 0) {
    return -1.0; // Account not found
  }
  return accounts_.at(accountNumber);
}

bool BankingClass::Deposit(int accountNumber, double amount) {
  // Implement logic to check for existing account and update balance
  if (accounts_.count(accountNumber) == 0) {
    return false; // Account not found
  }
  accounts_[accountNumber] += amount;
  return true;
}

bool BankingClass::Withdraw(int accountNumber, double amount) {
  // Implement logic to check for existing account, sufficient funds, and update balance
  if (accounts_.count(accountNumber) == 0) {
    return false; // Account not found
  }
  if (accounts_.at(accountNumber) < amount) {
    return false; // Insufficient funds
  }
  accounts_[accountNumber] -= amount;
  return true;
}

bool BankingClass::DeleteAccount(int accountNumber) {
  // Implement logic to check for existing account and remove it from the data structure
  if (accounts_.count(accountNumber) == 0) {
    return false; // Account not found
  }
  accounts_.erase(accountNumber);
  return true;
}
