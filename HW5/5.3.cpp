#include <iostream>
using namespace std;


int* MergeArrays(int* a, int* b, int sizea, int sizeb) {
    int* merged = new int[sizea + sizeb];  
    int i = 0, j = 0, k = 0;

    while (i < sizea && j < sizeb) {
        if (a[i] <= b[j])
            merged[k++] = a[i++];
        else
            merged[k++] = b[j++];
    }

    while (i < sizea)
        merged[k++] = a[i++];

    while (j < sizeb)
        merged[k++] = b[j++];

    return merged;  
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9, 14};
    int arr2[] = {2, 4, 6, 8, 10, 12, 13, 14};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int* merged = MergeArrays(arr1, arr2, size1, size2);

    cout << "Merged sorted array: ";
    for (int i = 0; i < size1 + size2; i++)
        cout << merged[i] << " ";
    cout << endl;

    delete[] merged;

    return 0;
}
