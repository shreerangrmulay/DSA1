#include <iostream>
using namespace std;

#define SIZE 5

int q1[SIZE], q2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue(int q[], int &front, int &rear, int val) {
    if (rear == SIZE - 1) {
        cout << "Queue is full!\n";
        return;
    }
    if (front == -1) front = 0;
    q[++rear] = val;
    cout << val << " added successfully.\n";
}

void dequeue(int q[], int &front, int &rear) {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!\n";
        front = rear = -1;
        return;
    }
    cout << q[front] << " removed.\n";
    front++;
}

void display(int q[], int front, int rear) {
    if (front == -1 || front > rear) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, val, qChoice;

    do {
        cout << "1. Add to Queue\n";
        cout << "2. Delete from Queue\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: 
                cout << "Select Queue (1 or 2): ";
                cin >> qChoice;
                if (qChoice != 1 && qChoice != 2) {
                    cout << "Invalid queue choice!\n";
                    break;
                }
                cout << "Enter value: ";
                cin >> val;
                if (qChoice == 1) enqueue(q1, front1, rear1, val);
                else enqueue(q2, front2, rear2, val);
                break;
            case 2: 
                cout << "Select Queue (1 or 2): ";
                cin >> qChoice;
                if (qChoice != 1 && qChoice != 2) {
                    cout << "Invalid queue choice!\n";
                    break;
                }
                if (qChoice == 1) dequeue(q1, front1, rear1);
                else dequeue(q2, front2, rear2);
                break;
            case 3: 
                cout << "Select Queue (1 or 2): ";
                cin >> qChoice;
                if (qChoice != 1 && qChoice != 2) {
                    cout << "Invalid queue choice!\n";
                    break;
                }
                if (qChoice == 1) display(q1, front1, rear1);
                else display(q2, front2, rear2);
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

