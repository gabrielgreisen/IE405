#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


int sumPrimeFactors(int n) {
    int sum = 0;
    int x = n;

    while (x % 2 == 0) {
        sum += 2;
        x /= 2;
    }


    for (int f = 3; f * f <= x; f += 2) {
        while (x % f == 0) {
            sum += f;
            x /= f;
        }
    }


    if (x > 1)
        sum += x;

    return sum;
}

int main() {
    cout << "Numbers from 2 to 1000 whose prime factors sum to a prime:\n";
    for (int n = 2; n <= 1000; ++n) {
        int s = sumPrimeFactors(n);
        if (isPrime(s))
            cout << "Prime number: " << n << " -> " << "Sum of prime factors: " << s << endl;
    }
    return 0;
}
