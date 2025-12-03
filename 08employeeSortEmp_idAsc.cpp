#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int empID;
    string name;
    float salary;
    Employee* left;
    Employee* right;
};

Employee* createNode(int id, string name, float salary) {
    Employee* newNode = new Employee;
    newNode->empID = id;
    newNode->name = name;
    newNode->salary = salary;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Employee* insert(Employee* root, int id, string name, float salary) {
    if (root == NULL)
        return createNode(id, name, salary);

    if (id < root->empID)
        root->left = insert(root->left, id, name, salary);
    else if (id > root->empID)
        root->right = insert(root->right, id, name, salary);
    else
        cout << "Duplicate Employee ID not allowed!\n";

    return root;
}

Employee* search(Employee* root, int id) {
    if (root == NULL || root->empID == id)
        return root;

    if (id < root->empID)
        return search(root->left, id);
    else
        return search(root->right, id);
}

void displaySorted(Employee* root) {
    if (root != NULL) {
        displaySorted(root->left);
        cout << "EmpID: " << root->empID
             << " | Name: " << root->name
             << " | Salary: " << root->salary << endl;
        displaySorted(root->right);
    }
}

int main() {
    Employee* root = NULL;
    int choice, id;
    string name;
    float salary;

    do {
        cout << "1. Insert Employee Record\n";
        cout << "2. Search Employee by ID\n";
        cout << "3. Display All Employees (Sorted by EmpID)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Employee Salary: ";
            cin >> salary;
            root = insert(root, id, name, salary);
            cout << "Employee record inserted successfully.\n";
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            {
                Employee* emp = search(root, id);
                if (emp != NULL) {
                    cout << "\n--- Employee Found ---\n";
                    cout << "EmpID: " << emp->empID << endl;
                    cout << "Name: " << emp->name << endl;
                    cout << "Salary: " << emp->salary << endl;
                } else {
                    cout << "Employee with ID " << id << " not found.\n";
                }
            }
            break;

        case 3:
            cout << "\nEmployees Sorted by EmpID\n";
            displaySorted(root);
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
