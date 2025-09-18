#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ticketID;
    string customerName;
    string rideName;
    Node* next;

    Node(int id, string cust, string ride) {
        ticketID = id;
        customerName = cust;
        rideName = ride;
        next = nullptr;
    }
};

class CircularList {
private:
    Node* tail;

public:
    CircularList() {
        tail = nullptr;
    }

    void issueTicketAtEnd(int id, string customer, string ride) {
        Node* newNode = new Node(id, customer, ride);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Ticket issued at end.\n";
    }

    void issuePriorityTicketAtFront(int id, string customer, string ride) {
        Node* newNode = new Node(id, customer, ride);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
        cout << "Priority ticket issued at front.\n";
    }

    void cancelTicketByID(int id) {
        if (!tail) {
            cout << "No tickets to cancel.\n";
            return;
        }
        Node* curr = tail->next;
        Node* prev = tail;
        bool found = false;

        do {
            if (curr->ticketID == id) {
                found = true;
                if (curr == prev) {
                    delete curr;
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail)
                        tail = prev;
                    delete curr;
                }
                cout << "Ticket with ID " << id << " cancelled.\n";
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        if (!found) {
            cout << "Ticket with ID " << id << " not found.\n";
        }
    }

    void cancelFirstTicket() {
        if (!tail) {
            cout << "No tickets to cancel.\n";
            return;
        }
        Node* head = tail->next;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
        cout << "First ticket cancelled.\n";
    }

    void searchTicketByID(int id) {
        if (!tail) {
            cout << "No tickets found.\n";
            return;
        }
        Node* curr = tail->next;
        do {
            if (curr->ticketID == id) {
                cout << "Ticket found: ID=" << curr->ticketID << ", Customer=" << curr->customerName << ", Ride=" << curr->rideName << "\n";
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket with ID " << id << " not found.\n";
    }

    void displayAllTickets() {
        if (!tail) {
            cout << "No tickets to display.\n";
            return;
        }
        cout << "All tickets in circular order:\n";
        Node* curr = tail->next;
        do {
            cout << "ID=" << curr->ticketID << ", Customer=" << curr->customerName << ", Ride=" << curr->rideName << "\n";
            curr = curr->next;
        } while (curr != tail->next);
    }

    void countTotalTickets() {
        if (!tail) {
            cout << "Total tickets: 0\n";
            return;
        }
        int count = 0;
        Node* curr = tail->next;
        do {
            count++;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Total tickets: " << count << "\n";
    }

    void findNextTicketAfterID(int id) {
        if (!tail) {
            cout << "No tickets found.\n";
            return;
        }
        Node* curr = tail->next;
        do {
            if (curr->ticketID == id) {
                Node* nextTicket = curr->next;
                cout << "Next ticket after ID " << id << ": ID=" << nextTicket->ticketID << ", Customer=" << nextTicket->customerName << ", Ride=" << nextTicket->rideName << "\n";
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket with ID " << id << " not found.\n";
    }
};

int main() {
    CircularList bookings;
    int choice, id;
    string customer, ride;

    do {
        cout << "\n1. Issue Ticket at End\n2. Issue Priority Ticket at Front\n3. Cancel Ticket by ID\n";
        cout << "4. Cancel First Ticket\n5. Search Ticket by ID\n6. Display All Tickets\n7. Count Total Tickets\n";
        cout << "8. Find Next Ticket After ID\n9. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Ticket ID, Customer Name, Ride Name: ";
                cin >> id >> customer >> ride;
                bookings.issueTicketAtEnd(id, customer, ride);
                break;
            case 2:
                cout << "Enter Ticket ID, Customer Name, Ride Name: ";
                cin >> id >> customer >> ride;
                bookings.issuePriorityTicketAtFront(id, customer, ride);
                break;
            case 3:
                cout << "Enter Ticket ID to cancel: ";
                cin >> id;
                bookings.cancelTicketByID(id);
                break;
            case 4:
                bookings.cancelFirstTicket();
                break;
            case 5:
                cout << "Enter Ticket ID to search: ";
                cin >> id;
                bookings.searchTicketByID(id);
                break;
            case 6:
                bookings.displayAllTickets();
                break;
            case 7:
                bookings.countTotalTickets();
                break;
            case 8:
                cout << "Enter Ticket ID to find next ticket after: ";
                cin >> id;
                bookings.findNextTicketAfterID(id);
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while(choice != 9);

    return 0;
}
