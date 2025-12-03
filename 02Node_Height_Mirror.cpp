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

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

void mirror(Node* root) {
    if (root == NULL)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "1. Insert a node\n";
        cout << "2. Display (Preorder Traversal)\n";
        cout << "3. Count total number of nodes\n";
        cout << "4. Compute height of the BST\n";
        cout << "5. Create mirror image of BST\n";
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
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Total number of nodes: " << countNodes(root) << endl;
            break;

        case 4:
            cout << "Height of BST: " << height(root) << endl;
            break;

        case 5:
            mirror(root);
            cout << "Mirror image created successfully!\n";
            cout << "Preorder of mirror BST: ";
            preorder(root);
            cout << endl;
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
