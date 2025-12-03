#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
    int rollNo;
    Student* left;
    Student* right;
};

Student* createNode(string name, int marks) {
    Student* newNode = new Student;
    newNode->name = name;
    newNode->marks = marks;
    newNode->rollNo = 0; 
    newNode->left = newNode->right = NULL;
    return newNode;
}

Student* insert(Student* root, string name, int marks) {
    if (root == NULL)
        return createNode(name, marks);

    if (marks < root->marks)
        root->left = insert(root->left, name, marks);
    else
        root->right = insert(root->right, name, marks);

    return root;
}

void assignRollNumbers(Student* root, int &rollCounter) {
    if (root == NULL)
        return;

    assignRollNumbers(root->right, rollCounter);

    root->rollNo = rollCounter++;

    assignRollNumbers(root->left, rollCounter);
}

void display(Student* root) {
    if (root != NULL) {
        display(root->left);
        cout << "Roll No: " << root->rollNo 
             << " | Name: " << root->name 
             << " | Marks: " << root->marks << endl;
        display(root->right);
    }
}

int main() {
    Student* root = NULL;
    int n;
    string name;
    int marks;

    cout << "\nAssign Roll Numbers Based on Previous Year Marks\n";
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter marks of " << name << ": ";
        cin >> marks;

        root = insert(root, name, marks);
    }

    int rollCounter = 1;
    assignRollNumbers(root, rollCounter);

    cout << "\nStudents with Assigned Roll Numbers\n";
    display(root);

    return 0;
}
