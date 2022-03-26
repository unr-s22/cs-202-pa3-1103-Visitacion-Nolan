// written by Christian Jovel Serpas
// March 25, 2022

#include <iostream>
#include "Money.h"

//
// constructors
//

Money::Money(int d, int c) {
    dollars = d;
    cents = c;
}

//
// operators
//

std::ostream& operator<<(std::ostream &out, const Money &m) {
    out << "$" << m.dollars << "." << m.cents << std::endl;
    return out;
}

bool Money::operator<(const Money &m) {
    return dollars < m.dollars || (dollars == m.dollars && cents < m.cents);
}

bool Money::operator>(const Money &m) {
    return dollars > m.dollars || (dollars == m.dollars && cents > m.cents);
}

bool Money::operator<=(const Money &m) {
    return dollars < m.dollars || (dollars == m.dollars && m.cents <= m.cents);
}

bool Money::operator>=(const Money &m) {
    return dollars > m.dollars || (dollars == m.dollars && cents >= m.cents);
}

bool Money::operator!=(const Money &m) {
    return dollars != m.dollars || cents != m.cents;
}

bool Money::operator==(const Money &m) {
    return dollars == m.dollars && cents == m.cents;
}

Money Money::operator+(const Money &m) {
    int dollars_sum = dollars + m.dollars;
    int cents_sum = cents + m.cents;
    if (cents_sum >= 100) {
        cents_sum -= 100;
        dollars_sum += 1;
    }
    Money result(dollars_sum, cents_sum);
    return result;
}

Money Money::operator-(const Money &m) {
    int dollars_difference = dollars - m.dollars;
    int cents_difference = cents - m.cents;
    if (cents_difference < 0) {
        cents_difference += 100;
        dollars_difference -= 1;
    }
    Money result(dollars_difference, cents_difference);
    return result;
}