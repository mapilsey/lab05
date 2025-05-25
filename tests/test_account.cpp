#include "Account.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockAccount : public Account {
public:
  MOCK_METHOD(void, Deposit, (double), (override));
  MOCK_METHOD(void, Withdraw, (double), (override));
  MOCK_METHOD(double, GetBalance, (), (const, override));
};

TEST(AccountTest, DepositValid) {
  SimpleAccount acc;
  acc.Deposit(100);
  ASSERT_EQ(acc.GetBalance(), 100);
}

TEST(AccountTest, DepositNegativeThrows) {
  SimpleAccount acc;
  EXPECT_THROW(acc.Deposit(-50), std::invalid_argument);
}

TEST(AccountTest, DepositZeroThrows) {
  SimpleAccount acc;
  EXPECT_THROW(acc.Deposit(0), std::invalid_argument);
}

TEST(AccountTest, WithdrawValid) {
  SimpleAccount acc;
  acc.Deposit(200);
  acc.Withdraw(100);
  ASSERT_EQ(acc.GetBalance(), 100);
}

TEST(AccountTest, WithdrawNegativeThrows) {
  SimpleAccount acc;
  EXPECT_THROW(acc.Withdraw(-50), std::invalid_argument);
}

TEST(AccountTest, WithdrawInsufficientFundsThrows) {
  SimpleAccount acc;
  acc.Deposit(50);
  EXPECT_THROW(acc.Withdraw(100), std::runtime_error);
}

TEST(AccountTest, InitialBalanceIsZero) {
  SimpleAccount acc;
  ASSERT_EQ(acc.GetBalance(), 0);
}

TEST(AccountTest, WithdrawExactBalance) {
  SimpleAccount acc;
  acc.Deposit(100);
  acc.Withdraw(100);
  ASSERT_EQ(acc.GetBalance(), 0);
}

TEST(AccountTest, CreateAndDeleteAccount) {
  Account* acc = CreateAccount();
  delete acc; // Покрываем деструктор
  SUCCEED();
}
