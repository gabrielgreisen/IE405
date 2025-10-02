#include <iostream>
#include <list>



using namespace std;

void toString(int integer) {
    
    if (integer == 0) {
        cout << "zero" << " ";
        cout << endl;
        return;
    }


    list<int> digits;

    while (integer != 0) {
        int digit = integer % 10;
        digits.push_front(digit);
        integer = integer/10;
    }

    for (int dig : digits) {
        if (dig == 1) {
            cout << "one" << " ";
        } else if (dig == 2) {
            cout << "two" << " ";
        } else if (dig == 3) {
            cout << "three" << " ";
        } else if (dig == 4) {
            cout << "four" << " ";
        } else if (dig == 5) {
            cout << "five" << " ";
        } else if (dig == 6) {
            cout << "six" << " ";
        } else if (dig == 7) {
            cout << "seven" << " ";
        } else if (dig == 8) {
            cout << "eight" << " ";
        } else if (dig == 9) {
            cout << "nine" << " ";
        } else {
            cout << "zero" << " ";
        }
    }
    cout << endl;
}


int main() {

    int input;

    cout << "Input an integer: ";
    cin >> input;

    toString(input);

    return 0;

}