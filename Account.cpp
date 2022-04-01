// Written by Nolan V.
// March 25, 2022
// editted by Christian Jovel Serpas
// March 31, 2022

#include <iostream>
#include <sstream>
#include <vector>
#include "Account.h"
#include "Money.h"

// Constructors

Account::Account(Money &m) {
    initBalance = m;
    currentBalance = m;
};

// Operators

std::ostream& operator<<(std::ostream &out, Account &a) {
    std::stringstream ss;
    Money currentBalance = a.getBalance();
    Money m;
    int numDeposits = a.deposits.size();
    int numWithdrawals = a.withdrawals.size();
    int i;
    ss << "Account Details" << '\n';
    ss << "--------------------------" << '\n';
    ss << "Current Balance: " << currentBalance << '\n';
    ss << "--------------------------" << '\n';
    ss << "Number of Deposits: " << numDeposits << '\n';
    ss << "--------------------------" << '\n';
    for (i = 0; i < numDeposits; i++) {
        m = a.deposits[i];
        ss << "(" << i + 1 << ") " << m << '\n';
    }
    ss << "--------------------------" << '\n';
    ss << "Number of Withdrawals: " << numWithdrawals << '\n';
    ss << "--------------------------" << '\n';
    for (i = 0; i < numWithdrawals; i++) {
        m = a.withdrawals[i];
        ss << "(" << i + 1 << ") " << m << '\n';
    }
    std::string output = ss.str();
    out << output;
    return out;
}

// Methods

void Account::makeDeposit(Money &m) {
    deposits.push_back(m);
    needsUpdate = true;
};

void Account::makeWithdrawal(Money &m) {
    withdrawals.push_back(m);
    needsUpdate = true;
};

Money Account::getBalance() {
    if (!needsUpdate) {
        return currentBalance;
    }
    Money balanceCalc = initBalance;
    for (Money m : deposits) {
        balanceCalc = balanceCalc + m;
    }
    for (Money m : withdrawals) {
        balanceCalc = balanceCalc - m;
    }
    currentBalance = balanceCalc;
    needsUpdate = false;
    return balanceCalc;
}