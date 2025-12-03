#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

string queueArr[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1);
}

bool isFull() {
    return (rear == SIZE - 1);
}

void enqueue(string name) {
    if (isFull()) {
        cout << "Queue is full! No more passengers can be added.\n";
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queueArr[rear] = name;
    cout << "Passenger " << name << " added to the queue.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! No passenger to remove.\n";
        return;
    }
    cout << "Passenger " << queueArr[front] << " has been served and removed from the queue.\n";
    if (front == rear) {
        front = rear = -1; 
    } else {
        front++;
    }
}

void showFront() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Passenger at front: " << queueArr[front] << endl;
    }
}

int countPassengers() {
    if (isEmpty()) return 0;
    return (rear - front + 1);
}

int main() {
    int choice;
    string name;

    do {
        cout << "1. Add Passenger\n";
        cout << "2. Serve Passenger (Remove)\n";
        cout << "3. Show Front Passenger\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name;
                enqueue(name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                showFront();
                break;
            case 4:
                cout << "Program terminated.\n";
                cout << "Passengers left in queue: " << countPassengers() << endl;
                break;
            default:
                break;
        }
    } while (choice != 4);

    return 0;
}
