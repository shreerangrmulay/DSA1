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

bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "1. Insert a node\n";
        cout << "2. Display (Inorder Traversal)\n";
        cout << "3. Search for a value\n";
        cout << "4. Find Minimum value\n";
        cout << "5. Find Maximum value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << value << " found in the BST.\n";
            else
                cout << value << " not found in the BST.\n";
            break;

        case 4:
            cout << "Minimum value in BST: " << findMin(root) << endl;
            break;

        case 5:
            cout << "Maximum value in BST: " << findMax(root) << endl;
            break;

        case 6:
            cout << "Exit\n";
            break;

        default:
            break;
        }

    } while (choice != 6);

    return 0;
}
