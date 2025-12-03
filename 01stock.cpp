#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* record(int value, struct Node* top){
    struct Node* temp;
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp -> data = value;
    temp -> next = top;
    top = temp;
    return top;
}

int isEmpty(struct Node* top){
    if (top == NULL)
    {
        return 1;
    } else {
        return 0;
    }
}

struct Node* remove(struct Node* top){
    struct Node* temp;
    temp = top;
    if (! isEmpty(top))
    {
        top = top -> next;
        cout << temp -> data <<"popped\n";
        delete temp;
        return top;
    } else {
        cout << "Stack is empty";
        return top; 
    }
}

struct Node* latest(struct Node* top){
    struct Node* temp;
    temp = top;
    if (! isEmpty(top))
    {
        cout << "Latest Price : " << top -> data;
    } else {
        cout << "Stack is empty";
        return top; 
    }
}

void display(struct Node* top){
    struct Node* p;
    p = top;
    while (p != NULL)
    {
        cout << "->" << p->data;
        p = p->next;
    }
    
}

int main(){
    struct Node* top = NULL;
    int choice,price;
    do
    {   
        cout << "\n1.Enter the price : " << "\n2.Remove the record : " << "\n3.See the latest record : " << "\n4.Display all the prices : " << "\n5.Exit : \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the price : ";
            cin >> price;
            top = record(price,top);
            break;
        case 2:
            top = remove(top);
            break;
        case 3:
            top = latest(top);
            break;
        case 4:
            display(top);
            break;
        default:
            break;
        }
    } while (choice != 5);
    return 0;
}