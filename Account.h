// Written by Nolan V.
// March 25, 2022

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>
#include "Money.h"

class Account : public Money {
private:
    Money balance;
    std::vector<Money> deposits;
    std::vector<Money> withdrawals;
    bool needsUpdate = false;


public:
    Account(Money m);
    friend std::ostream& operator<<(std::ostream &out, const Account &m);

    void makeDeposit(Money m);
    void makeWithdrawal(Money m);
    void updateBalance(std::vector<Money> d, std::vector<Money> w);
    static void makeString();
};



#endif // ACCOUNT_H





