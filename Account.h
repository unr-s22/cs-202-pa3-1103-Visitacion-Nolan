// Written by Nolan V.
// March 25, 2022

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include "Money.h"

class Account : public Money {
private:
    Money initBalance;
    Money currentBalance;
    std::vector<Money> deposits;
    std::vector<Money> withdrawals;
    bool needsUpdate = false;

private:
    void updateAccount();

public:
    Account(Money &m);
    friend std::ostream& operator<<(std::ostream &out, Account &a);
    void makeDeposit(Money &m);
    void makeWithdrawal(Money &m);
    Money getBalance();
};



#endif // ACCOUNT_H





