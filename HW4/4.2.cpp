#include <iostream>
using namespace std;

int reverse(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10; 
        n /= 10;                 
    }
    return rev;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int reversed = reverse(n);
    cout << "Reversed number: " << reversed << endl;

    return 0;
}