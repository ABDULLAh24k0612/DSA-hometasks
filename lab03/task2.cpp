#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    double price;
    Node* next;
    
    Node(string itemName, double itemPrice) {
        name = itemName;
        price = itemPrice;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;
public:
    ShoppingCart() {
        head = nullptr;
    }

    void addItemToTail(string name, double price) {
        Node* newNode = new Node(name, price);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Added '" << name << "' to the cart.\n";
    }

    void deleteItemFromFront() {
        if (head == nullptr) {
            cout << "Cart is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        cout << "Removed '" << head->name << "' from the cart.\n";
        head = head->next;
        delete temp;
    }

    void searchByItemName(string name) {
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->name == name) {
                cout << "Item found at position " << position << ": " << temp->name << " - $" << temp->price << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Item '" << name << "' not found in the cart.\n";
    }

    void searchByPosition(int pos) {
        if (pos < 1) {
            cout << "Invalid position.\n";
            return;
        }
        Node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            if (index == pos) {
                cout << "Item at position " << pos << ": " << temp->name << " - $" << temp->price << "\n";
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "No item found at position " << pos << ".\n";
    }

    void displayEntireCart() {
        if (head == nullptr) {
            cout << "Cart is empty.\n";
            return;
        }
        Node* temp = head;
        int position = 1;
        cout << "Shopping Cart Items:\n";
        while (temp != nullptr) {
            cout << position << ". " << temp->name << " - $" << temp->price << "\n";
            temp = temp->next;
            position++;
        }
    }
};

int main() {
    ShoppingCart cart;
    int choice;
    string name;
    double price;
    int pos;

    do {
        cout << "\n1. Add Item to Tail\n";
        cout << "2. Delete Item from Front\n";
        cout << "3. Search by Item Name\n";
        cout << "4. Search by Position\n";
        cout << "5. Display Entire Cart\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item price: ";
                cin >> price;
                cart.addItemToTail(name, price);
                break;
            case 2:
                cart.deleteItemFromFront();
                break;
            case 3:
                cout << "Enter item name to search: ";
                cin >> name;
                cart.searchByItemName(name);
                break;
            case 4:
                cout << "Enter position to search: ";
                cin >> pos;
                cart.searchByPosition(pos);
                break;
            case 5:
                cart.displayEntireCart();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
