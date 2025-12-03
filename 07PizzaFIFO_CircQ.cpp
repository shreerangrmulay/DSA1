#include <iostream>
using namespace std;

#define SIZE 5   

int front = -1, rear = -1;
int orders[SIZE];

bool isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

bool isEmpty() {
    return (front == -1);
}

void placeOrder(int orderID) {
    if (isFull()) {
        cout << "Sorry! No more orders can be accepted (Queue Full).\n";
        return;
    }
    if (front == -1) front = 0; 
    rear = (rear + 1) % SIZE;
    orders[rear] = orderID;
    cout << "Order " << orderID << " placed successfully.\n";
}

void serveOrder() {
    if (isEmpty()) {
        cout << "No pending orders to serve!\n";
        return;
    }
    cout << "Order " << orders[front] << " is served.\n";
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % SIZE;
    }
}

void displayOrders() {
    if (isEmpty()) {
        cout << "No pending orders.\n";
        return;
    }
    cout << "Pending Orders: ";
    int i = front;
    while (true) {
        cout << orders[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, orderID;
    do {
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> orderID;
                placeOrder(orderID);
                break;
            case 2:
                serveOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                cout << "Exit\n";
                break;
            default:
                break;
        }
    } while(choice != 4);

    return 0;
}
