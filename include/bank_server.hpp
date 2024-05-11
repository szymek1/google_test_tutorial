#ifndef BANK_SERVER_HPP
#define BANK_SERVER_HPP

class BankServer {
public:
    virtual ~BankServer() {};
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void credit(int account_number, int value) = 0;
    virtual void debit(int account_number, int value) = 0;
    virtual bool doubleTransaction(int account_number, int value_1, int value_2) = 0;
    virtual int getBalance(int account_number) const = 0;
};

#endif
