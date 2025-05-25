#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdexcept>

class Account {
public:
  virtual ~Account() = default;
  virtual void Deposit(double amount) = 0;
  virtual void Withdraw(double amount) = 0;
  virtual double GetBalance() const = 0;
};

class SimpleAccount : public Account {
private:
  double balance_ = 0;

public:
  void Deposit(double amount) override;
  void Withdraw(double amount) override;
  double GetBalance() const override;
};

Account* CreateAccount();

#endif
