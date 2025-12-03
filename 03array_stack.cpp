#include <iostream>
using namespace std;

#define SIZE 10   

class TwoStacks {
    int arr[SIZE];
    int top1, top2;

public:
    TwoStacks() {
        top1 = -1;        
        top2 = SIZE;      
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    void pop1() {
        if (top1 >= 0) {
            cout << "Popped from Stack 1: " << arr[top1--] << endl;
        } else {
            cout << "Stack Underflow in Stack 1\n";
        }
    }

    // Pop from stack 2
    void pop2() {
        if (top2 < SIZE) {
            cout << "Popped from Stack 2: " << arr[top2++] << endl;
        } else {
            cout << "Stack Underflow in Stack 2\n";
        }
    }

    // Display both stacks
    void display() {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "Stack 2: ";
        for (int i = SIZE - 1; i >= top2; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    TwoStacks ts;
    int choice, val;

    do {
        cout << "\n1.Push in Stack1"
             << "\n2.Push in Stack2"
             << "\n3.Pop from Stack1"
             << "\n4.Pop from Stack2"
             << "\n5.Display Stacks"
             << "\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            ts.push1(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            ts.push2(val);
            break;
        case 3:
            ts.pop1();
            break;
        case 4:
            ts.pop2();
            break;
        case 5:
            ts.display();
            break;
        case 6:
            break;
        default:
            break;
        }
    } while (choice != 6);

    return 0;
}
