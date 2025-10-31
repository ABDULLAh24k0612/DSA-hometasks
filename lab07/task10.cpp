#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[20];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        cout << "After sorting with place " << exp << ": ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    int arr[20];
    cout << "Enter 20 product IDs (5-digit integers):\n";
    for (int i = 0; i < 20; i++)
        cin >> arr[i];

    cout << "\nOriginal Product IDs:\n";
    for (int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    cout << endl << endl;

    radixSort(arr, 20);

    cout << "\nSorted Product IDs (Ascending):\n";
    for (int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
