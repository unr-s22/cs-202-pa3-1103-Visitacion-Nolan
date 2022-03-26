// written by Christian Jovel Serpas
// March 25, 2022

#include <iostream>
#include <sstream>
#include "Money.h"

//
// internal functions
//

int get9s(int n) {
    int nines = 9;
    while (nines < n) {
        nines += nines * 10;
    }
    return nines;
}
int get10s(int n) {
    int tens = 10;
    while (tens < n) {
        tens *= 10;
    }
    return tens;
}
int get10sComp(int n, int nines) {
    int tensComp = nines - n + 1;
    return tensComp;
}
int getDif(int a, int b) {
    int b_nines = get9s(b);
    int b_tens = get10s(b);
    int b_tensComp = get10sComp(b, b_nines);
    int s = a + b_tensComp;
    if (s > b_nines) {
        s -= b_tens;
    } else {
        s = get10sComp(s, b_nines);
    }
    return s;
}

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
    std::cout << output;
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
    bool resultNeg;
    bool dollars_sum, cents_sum;
    if ((!isNegative && !m.isNegative) || (isNegative && m.isNegative)) {
        int dollars_sum = dollars + m.dollars;
        int cents_sum = cents + m.cents;
        if (cents_sum > 100) {
            dollars_sum += 1;
            cents_sum -= 100;
        }
        resultNeg = isNegative;
    } else {
        dollars_sum = getDif(dollars, m.dollars);
        cents_sum = getDif(cents, m.cents);
        resultNeg = dollars < m.dollars || (dollars == m.dollars && cents < m.cents) ? !isNegative : isNegative;
    }
    Money result(dollars_sum, cents_sum, resultNeg);
    return result;
}

Money Money::operator-(const Money &m) {
    bool resultNeg;
    int dollars_dif, cents_dif;
    if ((!isNegative && !m.isNegative) || (isNegative && m.isNegative)) {
        dollars_dif = getDif(dollars, m.dollars);
        cents_dif = getDif(cents, m.cents);
        resultNeg = dollars < m.dollars || (dollars == m.dollars && cents < m.cents) ? !isNegative : isNegative;
    } else {
        dollars_dif = dollars + m.dollars;
        cents_dif = dollars + m.dollars;
        if (cents_dif > 100) {
            dollars_dif += 1;
            cents_dif -= 100;
        }
        resultNeg = isNegative;
    }
    Money result(dollars_dif, cents_dif, resultNeg);
    return result;
}