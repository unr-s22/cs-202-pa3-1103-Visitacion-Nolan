// written by Christian Jovel Serpas
// March 25, 2022

#include <iostream>
#include <sstream>
#include "Money.h"

//
// operators
//

std::ostream& operator<<(std::ostream &out, const Money &m) {
    std::stringstream ss;
    if (m.isNegative) {
        ss << "-";
    }
    ss << "$" << m.dollars << ".";
    if (m.cents < 10) {
        ss << "0" << m.cents;
    } else {
        ss << m.cents;
    }
    std::string output = ss.str();
    out << output;
    return out;
}

bool Money::operator<(const Money &m) const {
    return dollars < m.dollars || (dollars == m.dollars && cents < m.cents);
}

bool Money::operator>(const Money &m) const {
    return dollars > m.dollars || (dollars == m.dollars && cents > m.cents);
}

bool Money::operator<=(const Money &m) const {
    return dollars < m.dollars || (dollars == m.dollars && m.cents <= m.cents);
}

bool Money::operator>=(const Money &m) const {
    return dollars > m.dollars || (dollars == m.dollars && cents >= m.cents);
}

bool Money::operator!=(const Money &m) const {
    return dollars != m.dollars || cents != m.cents;
}

bool Money::operator==(const Money &m) const {
    return dollars == m.dollars && cents == m.cents;
}

Money Money::operator+(const Money &m) const {
    bool resultNeg;
    int dollars_sum, cents_sum;
    if (isNegative == m.isNegative) {
        dollars_sum = dollars + m.dollars;
        cents_sum = cents + m.cents;
        if (cents_sum >= 100) {
            dollars_sum += 1;
            cents_sum -= 100;
        }
        resultNeg = isNegative;
    } else {
        dollars_sum = std::abs(dollars - m.dollars);
        cents_sum = std::abs(cents - m.cents);
        resultNeg = dollars < m.dollars || (dollars == m.dollars && cents < m.cents) ? !isNegative : isNegative;
    }
    Money result(dollars_sum, cents_sum, resultNeg);
    return result;
}

Money Money::operator-(const Money &m) const {
    bool resultNeg;
    int dollars_dif, cents_dif;
    if (isNegative == m.isNegative) {
        dollars_dif = std::abs(dollars - m.dollars);
        cents_dif = std::abs(cents - m.cents);
        resultNeg = dollars < m.dollars || (dollars == m.dollars && cents < m.cents) ? !isNegative : isNegative;
    } else {
        dollars_dif = dollars + m.dollars;
        cents_dif = dollars + m.dollars;
        if (cents_dif >= 100) {
            dollars_dif += 1;
            cents_dif -= 100;
        }
        resultNeg = isNegative;
    }
    Money result(dollars_dif, cents_dif, resultNeg);
    return result;
}