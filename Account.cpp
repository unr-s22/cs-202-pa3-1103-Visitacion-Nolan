// Written by Nolan V.
// March 25, 2022
#include "Account.h"


// Constructors

Account::Account(Money m) {
    balance = m;
};

// Operators

std::ostream& operator<<(std::ostream &out, const Account &m) {
    std::stringstream ss; 
    
    ss << "Account Details" << std::endl << "--------------------------" << std::endl << "Current Balance: " << std::endl << m.balance << std::endl;
    ss << "--------------------------" << std::endl;
    ss << "Number of Deposits " << m.deposits.size() << std::endl << "--------------------" << std::endl;
    for (int i = 0; i < m.deposits.size(); i++)
        {
            ss << "(" << i << ")" << "$" << m.deposits[i] << std::endl;
        }
    ss << "Number of Withdrawals " << m.withdrawals.size() << std::endl << "--------------------" << std::endl;
    for (int i = 0; i < m.withdrawals.size(); i++)
        {
            ss << "(" << i << ")" << "$" << m.withdrawals[i] << std::endl;
        }
    std::string output = ss.str();
    std::cout << output;
    return out;
}

// Methods

void Account::makeDeposit(Money m) {
    deposits.push_back(m);
    needsUpdate = true;
};

void Account::makeWithdrawal(Money m) {
    withdrawals.push_back(m);
    needsUpdate = true;
};

void Account::updateBalance(std::vector<Money> d, std::vector<Money> w) {
    auto sum_deposits = std::accumulate(d.begin(), d.end(), balance);
    auto sum_withdrawals = std::accumulate(w.begin(), w.end(), balance);
        
        balance = sum_deposits - sum_withdrawals;
        needsUpdate = false;
};

void Account::makeString() {


}

