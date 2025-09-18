#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    double price;
    Node* prev;
    Node* next;

    Node(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
        prev = nullptr;
        next = nullptr;
    }
};

class Cart {
private:
    Node* head;
    Node* tail;

public:
    Cart() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int id, string name, double price) {
        Node* newNode = new Node(id, name, price);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Item added at end.\n";
    }

    void insertAtFront(int id, string name, double price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Item added at front.\n";
    }

    void removeFirst() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        cout << "First item removed.\n";
    }

    void removeLast() {
        if (!tail) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        cout << "Last item removed.\n";
    }

    void searchByID(int id) {
        Node* current = head;
        while (current) {
            if (current->id == id) {
                cout << "Item found: ID=" << current->id << ", Name=" << current->name << ", Price=$" << current->price << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void updatePriceByID(int id, double newPrice) {
        Node* current = head;
        while (current) {
            if (current->id == id) {
                current->price = newPrice;
                cout << "Price updated.\n";
                return;
            }
            current = current->next;
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void displayFromFront() {
        Node* current = head;
        if (!current) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "Cart (Front to End):\n";
        while (current) {
            cout << "ID=" << current->id << ", Name=" << current->name << ", Price=$" << current->price << "\n";
            current = current->next;
        }
    }

    void displayFromEnd() {
        Node* current = tail;
        if (!current) {
            cout << "Cart is empty.\n";
            return;
        }
        cout << "Cart (End to Front):\n";
        while (current) {
            cout << "ID=" << current->id << ", Name=" << current->name << ", Price=$" << current->price << "\n";
            current = current->prev;
        }
    }

    void countItems() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        cout << "Total items in cart: " << count << "\n";
    }

    void findMostExpensiveItem() {
        if (!head) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* current = head;
        Node* maxNode = head;
        while (current) {
            if (current->price > maxNode->price) {
                maxNode = current;
            }
            current = current->next;
        }
        cout << "Most expensive item: ID=" << maxNode->id << ", Name=" << maxNode->name << ", Price=$" << maxNode->price << "\n";
    }
};

int main() {
    Cart cart;
    int choice, id;
    string name;
    double price;

    do {
        cout << "\n1. Insert at End\n2. Insert at Front\n3. Remove First\n4. Remove Last\n";
        cout << "5. Search by ID\n6. Update Price by ID\n7. Display Front to End\n";
        cout << "8. Display End to Front\n9. Count Items\n10. Most Expensive Item\n11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Price: ";
                cin >> id >> name >> price;
                cart.insertAtEnd(id, name, price);
                break;
            case 2:
                cout << "Enter ID, Name, Price: ";
                cin >> id >> name >> price;
                cart.insertAtFront(id, name, price);
                break;
            case 3:
                cart.removeFirst();
                break;
            case 4:
                cart.removeLast();
                break;
            case 5:
                cout << "Enter ID to search: ";
                cin >> id;
                cart.searchByID(id);
                break;
            case 6:
                cout << "Enter ID and new price: ";
                cin >> id >> price;
                cart.updatePriceByID(id, price);
                break;
            case 7:
                cart.displayFromFront();
                break;
            case 8:
                cart.displayFromEnd();
                break;
            case 9:
                cart.countItems();
                break;
            case 10:
                cart.findMostExpensiveItem();
                break;
            case 11:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 11);

    return 0;
}
