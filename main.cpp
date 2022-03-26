// testing operators for money class part written by Christian Jovel Serpas
// March 25 2022

#include <iostream>
#include "Money.h"

int main() {
    // test all operators for money class
    Money m1(100, 99);
    Money m2(100, 99);
    Money m3 = m1 + m2;
    Money m4 = m1 - m2;
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
    return 0;
}