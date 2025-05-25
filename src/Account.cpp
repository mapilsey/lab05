#include "Account.h"

void SimpleAccount::Deposit(double amount) {
  if (amount <= 0) {
    throw std::invalid_argument("Amount must be positive");
  }
  balance_ += amount;
}

void SimpleAccount::Withdraw(double amount) {
  if (amount <= 0) {
    throw std::invalid_argument("Amount must be positive");
  }
  if (balance_ < amount) {
    throw std::runtime_error("Insufficient funds");
  }
  balance_ -= amount;
}

double SimpleAccount::GetBalance() const { 
  return balance_; 
}

Account* CreateAccount() {
  return new SimpleAccount();
}
