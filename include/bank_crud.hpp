#ifndef BANKINGCLASS_HPP
#define BANKINGCLASS_HPP

#include <map>
#include <type_traits>
#include <stdexcept>


class BankingClass {
public:
  // Create a new account
  bool CreateAccount(int accountNumber, double initialBalance);

  // Retrieve account balance
  double GetBalance(int accountNumber) const;

  // Deposit funds into an account
  bool Deposit(int accountNumber, double amount);

  // Withdraw funds from an account
  bool Withdraw(int accountNumber, double amount);

  // Delete an existing account
  bool DeleteAccount(int accountNumber);

private:
  // Data structure to store account information (replace with your preferred implementation)
  std::map<int, double> accounts_;
};

#endif // BANKINGCLASS_HPP
