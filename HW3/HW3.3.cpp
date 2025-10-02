#include <iostream>

#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void coinToss(int flips) {
    srand(time(0));

    for (int i = 0; i < flips; i++) {
        int randomBit = (rand() % 2) + 1;

        if (randomBit == 1) {
            string out ="heads";
            cout << out << " ";
        } else {
            string out = "tails";
            cout << out << " ";
        }
    }
}

int main() {

    int flips;

    cout << "Number of flips: ";
    cin >> flips;

    
    coinToss(flips);

    
    cout << endl;

    return 0;
}