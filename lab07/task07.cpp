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
    int output[50];
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
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int scores[50];
    cout << "Enter 50 student scores (0-100):\n";
    for (int i = 0; i < 50; i++)
        cin >> scores[i];

    radixSort(scores, 50);

    cout << "\nScores in Ascending Order:\n";
    for (int i = 0; i < 50; i++)
        cout << scores[i] << " ";

    cout << "\n\nRanks (Highest Score = Rank 1):\n";
    int rank = 1;
    for (int i = 49; i >= 0; i--) {
        cout << "Score: " << scores[i] << " | Rank: " << rank << endl;
        rank++;
    }
    return 0;
}
