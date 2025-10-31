#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    double totalPrice;
};

int partition(Order arr[], int low, int high) {
    double pivot = arr[high].totalPrice;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].totalPrice <= pivot) {
            i++;
            Order temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Order temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(Order arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of orders: ";
    cin >> n;
    Order orders[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter Order ID, Customer Name, and Total Price: ";
        cin >> orders[i].orderID >> orders[i].customerName >> orders[i].totalPrice;
    }

    quickSort(orders, 0, n - 1);

    cout << "\nOrders sorted by Total Price (Ascending):\n";
    for (int i = 0; i < n; i++)
        cout << "OrderID: " << orders[i].orderID
             << " | Customer: " << orders[i].customerName
             << " | Total Price: " << orders[i].totalPrice << endl;

    return 0;
}
