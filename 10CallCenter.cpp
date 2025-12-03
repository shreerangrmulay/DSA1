#include <iostream>
using namespace std;

struct Node{
    char data;
    struct Node* next;
};
struct Node* Front = NULL, *Rear = NULL;

void enQueue(char x){
    struct Node* temp;
    temp = (struct Node*) malloc(sizeof (struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if (Rear == NULL)
    {
        Rear = Front = temp;
    } else {
        Rear -> next = temp;
        Rear = temp;
    }
    return;
}
char deQueue(){
    struct Node* temp;
    char x = -1;
    if (Front !=NULL)
    {
        x = Front -> data;
        temp = Front;
        if(Front == Rear) Front = Rear = NULL;
        else Front = Front -> next;
        delete temp;
    } else {
        cout << "Queue is empty";
        return x;
    }
}
void display() {
    if (Front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Calls in queue: ";
    Node* temp = Front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int choice;
    char call;

    do {
        cout << "1. New Call (Enqueue)\n";
        cout << "2. Serve Call (Dequeue)\n";
        cout << "3. Display Waiting Calls\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter call ID (char): ";
                cin >> call;
                enQueue(call);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exit\n";
                break;
            default:
                break;
        }
    } while (choice != 4);

    return 0;
}