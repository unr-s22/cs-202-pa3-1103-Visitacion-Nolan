// written by Christian Jovel Serpas
// March 25, 2022

#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money {
    private:
        int dollars;
        int cents;
    public:
        Money(): dollars {0}, cents {0} {};
        Money(int d, int c);
    public:
        friend std::ostream& operator<<(std::ostream &out, const Money &m);
        bool operator<(const Money &m);
        bool operator>(const Money &m);
        bool operator<=(const Money &m);
        bool operator>=(const Money &m);
        bool operator!=(const Money &m);
        bool operator==(const Money &m);
        Money operator+(const Money &m);
        Money operator-(const Money &m);
};

#endif // MONEY_H