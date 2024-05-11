#include <memory>

#include "my_bank_server.hpp"
#include "atm.hpp"


int main() {

    std::unique_ptr<MyBankServer> pBank = std::make_unique<MyBankServer>();
    ATM atm = ATM(std::move(pBank));
    atm.addMoney(123456, 1000);
    atm.withdrewMoney(123456, 1000);
    atm.displayBalance(123456);
    


    return 0;
}