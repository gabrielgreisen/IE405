#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter an integer :";
    cin >> num;

    int product = 1;
    int sum = 0;

    

    while (num != 0) {
        int digit = num % 10;
        num = num/10;

        sum = sum + digit;
        product = product*digit;

    }

    cout << "Sum is " << sum << " and Product is " << product << endl;

    return 0;
}