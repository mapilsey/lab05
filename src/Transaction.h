#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"

class Transaction {
public:
  virtual ~Transaction() = default;
  virtual bool Make(Account& from, Account& to, double amount) = 0;
};

class MoneyTransaction : public Transaction {
public:
  bool Make(Account& from, Account& to, double amount) override;
};

Transaction* CreateTransaction();

#endif
