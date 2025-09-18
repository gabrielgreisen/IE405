#include <iostream>

int main() {
    std::cout << "Enter the year to be tested: ";
    long year;
    if (!(std::cin >> year)) return 0;

    bool is_leap = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));

    if (is_leap) {
        std::cout << "Yep, it's a leap year.\n";
    } else {
        std::cout << "Nope, it's not a leap year.\n";
    }
    return 0;
}
