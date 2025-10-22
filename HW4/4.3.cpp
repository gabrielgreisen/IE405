#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int main() {
    const int SIZE = 5;
    int lottery[SIZE];
    int user[SIZE];
    int count = 0;

    
    srand(time(0));

    cout << "Lottery numbers: ";
    for (int i = 0; i < SIZE; i++) {
        lottery[i] = rand() % 10;
        cout << lottery[i] << " ";
    }
    cout << endl;

    cout << "Enter your 5 digits (0–9): ";
    for (int i = 0; i < SIZE; i++) {
        cin >> user[i];
    }


    for (int i = 0; i < SIZE; i++) {
        if (abs(lottery[i] - user[i]) <= 1) { 
            count++;
        }
    }

    
    cout << "You have " << count << " digits within ±1 of the lottery numbers." << endl;

    if (count == SIZE) {
        cout << "Congratulations! You’re a big prize winner! " << endl;
    }

    return 0;
}