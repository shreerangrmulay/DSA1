#include <iostream>
#include <stack>
#include <queue>
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
    Node* newNode = createNode(value);
    if (root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else
            q.push(temp->left);

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else
            q.push(temp->right);
    }
    return root;
}

void inorderNonRecursive(Node* root) {
    if (root == NULL) return;
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderNonRecursive(Node* root) {
    if (root == NULL) return;
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right != NULL)
            s.push(curr->right);
        if (curr->left != NULL)
            s.push(curr->left);
    }
}

int countLeafNodes(Node* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL && temp->right == NULL)
            count++;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    return count;
}

void mirror(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        Node* t = temp->left;
        temp->left = temp->right;
        temp->right = t;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    cout << "Mirror image created successfully!\n";
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "1. Insert a node\n";
        cout << "2. Inorder Traversal (Non-Recursive)\n";
        cout << "3. Preorder Traversal (Non-Recursive)\n";
        cout << "4. Display Number of Leaf Nodes\n";
        cout << "5. Mirror Image of Tree\n";
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
            inorderNonRecursive(root);
            cout << endl;
            break;

        case 3:
            cout << "Preorder Traversal: ";
            preorderNonRecursive(root);
            cout << endl;
            break;

        case 4:
            cout << "Number of Leaf Nodes: " << countLeafNodes(root) << endl;
            break;

        case 5:
            mirror(root);
            cout << "Inorder after mirror: ";
            inorderNonRecursive(root);
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
