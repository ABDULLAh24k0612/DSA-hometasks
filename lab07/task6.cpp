#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Employee* L = new Employee[n1];
    Employee* R = new Employee[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].salary >= R[j].salary) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Employee e[12];
    for (int i = 0; i < 12; i++) {
        cout << "Enter name, ID, and salary for employee " << i + 1 << ": ";
        cin >> e[i].name >> e[i].id >> e[i].salary;
    }

    mergeSort(e, 0, 11);

    cout << "\nEmployees sorted by salary (descending):\n";
    for (int i = 0; i < 12; i++)
        cout << e[i].name << " (ID: " << e[i].id << ", Salary: " << e[i].salary << ")\n";

    cout << "\nTop 3 Highest Paid Employees:\n";
    for (int i = 0; i < 3 && i < 12; i++)
        cout << e[i].name << " (ID: " << e[i].id << ", Salary: " << e[i].salary << ")\n";

    return 0;
}

