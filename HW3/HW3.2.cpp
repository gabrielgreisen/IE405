
#include <iostream>
using namespace std;

void squareNreverse(int arr[], int length) {

    for (int i = 0; i < length; i++) {
        arr[i] = arr[i] * arr[i];
    }

    for (int i = 0;  i < length/2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
    }
}


int main() {
    const int size = 5;
    int numbers[size];

    cout << "enter 5 integers: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    squareNreverse(numbers, size);

    cout << "Squared and reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}