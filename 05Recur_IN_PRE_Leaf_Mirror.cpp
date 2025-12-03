#include <iostream>
using namespace std;

// Define structure of a node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node (for a general binary tree)
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    // For simplicity, insert smaller values to left and larger/equal to right
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// a) Recursive Inorder Traversal (Left → Root → Right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// b) Recursive Preorder Traversal (Root → Left → Right)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// c) Count the total number of leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// d) Create Mirror Image of Binary Tree
void mirror(Node* root) {
    if (root == NULL)
        return;

    // Swap left and right child pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively mirror the subtrees
    mirror(root->left);
    mirror(root->right);
}

// Main function
int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "1. Insert a node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Display Number of Leaf Nodes\n";
        cout << "5. Create Mirror Image\n";
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
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Total Number of Leaf Nodes: " << countLeafNodes(root) << endl;
            break;

        case 5:
            mirror(root);
            cout << "Mirror Image created successfully.\n";
            cout << "Inorder Traversal of Mirror Tree: ";
            inorder(root);
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
