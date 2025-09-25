#include <iostream>

using namespace std;

int main() {
    int number;

    do {
        cout << "Enter an integer: ";
        cin >> number;
    } while ((number % 5 != 0) && (number % 11 != 0));

    return 0;
}