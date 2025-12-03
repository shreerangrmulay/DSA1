#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

bool find(Node* root, int value) {
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    else if (value < root->data)
        return find(root->left, value);
    else
        return find(root->right, value);
}

void show(Node* root) {
    if (root != NULL) {
        show(root->left);
        cout << root->data << " ";
        show(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Show (Inorder Traversal)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Value inserted successfully.\n";
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Value deleted (if existed).\n";
            break;

        case 3:
            cout << "Enter value to find: ";
            cin >> value;
            if (find(root, value))
                cout << "Value found in BST.\n";
            else
                cout << "Value not found.\n";
            break;

        case 4:
            cout << "BST (Inorder Display): ";
            show(root);
            cout << endl;
            break;

        case 5:
            cout << "Exit\n";
            break;

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}
