#include "Transaction.h"

bool MoneyTransaction::Make(Account& from, Account& to, double amount) {
  if (amount <= 0 || &from == &to) {
    return false;
  }

  try {
    from.Withdraw(amount);
  } catch (const std::exception&) {
    return false;
  }

  try {
    to.Deposit(amount);
  } catch (const std::exception&) {
    from.Deposit(amount); // Откат
    return false;
  }

  return true;
}

Transaction* CreateTransaction() {
  return new MoneyTransaction();
}
