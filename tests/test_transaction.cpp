#include "Transaction.h"
#include "Account.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Throw;

TEST(TransactionTest, TransferSuccess) {
  SimpleAccount from, to;
  from.Deposit(200);
  MoneyTransaction tr;
  ASSERT_TRUE(tr.Make(from, to, 100));
  ASSERT_EQ(from.GetBalance(), 100);
  ASSERT_EQ(to.GetBalance(), 100);
}

TEST(TransactionTest, TransferNegativeAmountFails) {
  SimpleAccount from, to;
  MoneyTransaction tr;
  ASSERT_FALSE(tr.Make(from, to, -50));
}

TEST(TransactionTest, TransferInsufficientFundsFails) {
  SimpleAccount from, to;
  from.Deposit(50);
  MoneyTransaction tr;
  ASSERT_FALSE(tr.Make(from, to, 100));
}

TEST(TransactionTest, TransferZeroAmountFails) {
  SimpleAccount from, to;
  MoneyTransaction tr;
  ASSERT_FALSE(tr.Make(from, to, 0));
}

TEST(TransactionTest, TransferToSelfFails) {
  SimpleAccount acc;
  acc.Deposit(200);
  MoneyTransaction tr;
  ASSERT_FALSE(tr.Make(acc, acc, 100));
}

TEST(TransactionTest, DepositFailureRollsBack) {
  SimpleAccount from;
  from.Deposit(200);

  // Мок аккаунта с ошибкой при Deposit
  class MockAccount : public Account {
  public:
    MOCK_METHOD(void, Deposit, (double), (override));
    MOCK_METHOD(void, Withdraw, (double), (override));
    MOCK_METHOD(double, GetBalance, (), (const, override));
  };

  MockAccount mockTo;
  EXPECT_CALL(mockTo, Deposit(100))
    .WillOnce(Throw(std::runtime_error("Deposit failed")));

  MoneyTransaction tr;
  ASSERT_FALSE(tr.Make(from, mockTo, 100));
  ASSERT_EQ(from.GetBalance(), 200); // Проверка отката
}

TEST(TransactionTest, CreateTransactionFactory) {
  Transaction* tr = CreateTransaction();
  ASSERT_NE(tr, nullptr);
  delete tr;
}
