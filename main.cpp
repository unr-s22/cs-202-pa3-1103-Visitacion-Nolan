// testing operators for money class part written by Christian Jovel Serpas
// March 25 2022

#include <iostream>
#include "Money.h"
#include "Account.h"

int main() {
    // Starting + Deposit Instances Of Money Object
    Money s1(300,23);
    Money d1(200,00);
    Money d2(300,24);
    Money d3(501,23);
    Money w1(300,10);
    Money w2(201,34);
    // Create Account Object With Starting Balance $300.23
    Account account(s1);
    // print the account object
    std::cout << account << std::endl;
    // Make 3 Deposits Into "account" Object
    account.makeDeposit(d1);
    account.makeDeposit(d2);
    account.makeDeposit(d3);
    // print the account object again
    std::cout << account << std::endl;
    // make 2 withdrawals
    account.makeWithdrawal(w1);
    account.makeWithdrawal(w2);
    // print the account object a final time
    std::cout << account << std::endl;
    // test all operators for money class
    Money m1(1, 30);
    Money m2(20, 70);
    Money m3 = m1 + m2; // 22.00
    Money m4 = m1 - m2; // -19.40
    Money m5(2, 0);
    Money m6 = m4 + m5; // -17.40
    
    // greater than
    if (m1 > m2) {
        std::cout << "m1 greater than m2" << std::endl;
    } else {
        std::cout << "m1 is not greater than m2" << std::endl;
    }
    // less than
    if (m1 < m2) {
        std::cout << "m1 less than m2" << std::endl;
    } else {
        std::cout << "m1 is not less than m2" << std::endl;
    }
    // equal to & not equal to
    if (m1 == m2) {
        std::cout << "m1 is equal to m2" << std::endl;
    } else if (m1 != m2) {
        std::cout << "m1 not equal to m2" << std::endl;
    }
    // greater than or equal to
    if (m1 >= m3) {
        std::cout << "m1 is greater than or equal to m3" << std::endl;
    } else {
        std::cout << "m1 is not greater than or equal to m3" << std::endl;
    }
    // less than or equal to
    if (m1 <= m3) {
        std::cout << "m1 is less than or equal to m3" << std::endl;
    } else {
        std::cout << "m1 is not less than or equal to m3" << std::endl;
    }

    // adding and subtracting
    std::cout << "m3 = m1 + m2 = " << m3 << std::endl;
    std::cout << "m4 = m1 - m2 = " << m4 << std::endl;
    std::cout << "m6 = m4 + m5 = " << m6 << std::endl;

    // expected output:
    /*
    m1 is not greater than m2
    m1 less than m2
    m1 not equal to m2
    m1 is not greater than or equal to m3
    m1 is less than or equal to m3
    m3 = m1 + m2 = $22.00
    m4 = m1 - m2 = -$19.40
    m6 = m4 + m5 = -$17.40
    */

    return 0;
}