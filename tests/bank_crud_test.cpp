#include <gtest/gtest.h>

#include "bank_crud.hpp"


TEST(CRUD_ops, CreatAccount) {
    BankingClass bank = BankingClass();

    ASSERT_TRUE(bank.CreateAccount(12345, 1000.45));
    EXPECT_EQ(bank.GetBalance(12345), 1000.45);

    EXPECT_NO_THROW(bank.CreateAccount(-1, 100.0));
}

TEST(CRUD_ops, Deposit) {
    BankingClass bank = BankingClass();

    ASSERT_TRUE(bank.CreateAccount(12345, 1000.45));
    EXPECT_TRUE(bank.Deposit(12345, 200));
    EXPECT_EQ(bank.GetBalance(12345), 1200.45);
}

TEST(CRUD_ops, Withdraw) {
    BankingClass bank = BankingClass();

    ASSERT_TRUE(bank.CreateAccount(12345, 1000.45));
    EXPECT_TRUE(bank.Withdraw(12345, 200.45));
    EXPECT_EQ(bank.GetBalance(12345), 800);
} 

TEST(CRUD_ops, MultipleAccountsManagement) {
    BankingClass bank = BankingClass();

    bank.CreateAccount(12345, 1000); // #1
    bank.CreateAccount(12346, 2000); // #2
    bank.CreateAccount(12347, 3000); // #3

    ASSERT_TRUE(bank.DeleteAccount(12345));

    ASSERT_TRUE(bank.DeleteAccount(12346));
    
    EXPECT_EQ(bank.GetBalance(12347), 3000);
    ASSERT_TRUE(bank.DeleteAccount(12347));
}