#include <iostream>
using namespace std;
int F = -1,R = -1;
#define size 10
int Q[size];

int emptyQ(){
    if(F == -1) return -1;
    else return 0;
}

int fullQueue(){
    if(R == size-1) return 1;
    else return 0;
}

char dequeue(){
    char x;
    if (!emptyQ())
    {
        x = Q[R];
        if (F == R)
            F = R = -1;
        else 
            F = F + 1;
        return x;
    } else {
        cout << "Queue is empty";
        return -1;
    }
}
void queue(int x){
    if (!fullQueue())
    {
        R = R + 1;
        Q[R] = x;
        if (F == -1)
            F = R;
    } else {
        cout << "Queue is full";
    }
    
}
void display() {
    if (emptyQ()) {
        cout << "No patients in waiting queue.\n";
        return;
    }
    cout << "Patients waiting: ";
    for (int i = F; i <= R; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main(){
    int choice, patientID;

    do {
        cout << "1. Check-in Patient\n";
        cout << "2. Assign Patient to Doctor\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> patientID;
                queue(patientID);
                break;
            case 2:
                dequeue();
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
    } while(choice != 4);

    return 0;
}