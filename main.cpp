#include <iostream>
#include "Money.h"

int main() {
    Money chris(100, 9);
    Money andy(200, 10);
    std::cout << chris << std::endl;
    std::cout << andy << std::endl;
    return 0;
}