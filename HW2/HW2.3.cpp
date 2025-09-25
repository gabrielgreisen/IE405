#include <iostream>
using namespace std;

int main() {
    for (int n = 10; n <= 25; n++) {
        int T = n * (n+1)/2;
        cout << "T(" << n << ") = " << T << endl;
    }
    return 0;
}