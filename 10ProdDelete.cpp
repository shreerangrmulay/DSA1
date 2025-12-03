#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Product {
    string code;
    string name;
    float price;
    int quantity;
    string dateReceived;
    string expiryDate;
    Product* left;
    Product* right;
};

Product* createNode(string code, string name, float price, int qty, string recDate, string expDate) {
    Product* newNode = new Product;
    newNode->code = code;
    newNode->name = name;
    newNode->price = price;
    newNode->quantity = qty;
    newNode->dateReceived = recDate;
    newNode->expiryDate = expDate;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Product* insert(Product* root, string code, string name, float price, int qty, string recDate, string expDate) {
    if (root == NULL)
        return createNode(code, name, price, qty, recDate, expDate);

    if (name < root->name)
        root->left = insert(root->left, code, name, price, qty, recDate, expDate);
    else if (name > root->name)
        root->right = insert(root->right, code, name, price, qty, recDate, expDate);
    else
        cout << "Duplicate Product Name not allowed.\n";

    return root;
}

bool isExpired(const string& expDate) {
    int d, m, y;
    sscanf(expDate.c_str(), "%d/%d/%d", &d, &m, &y);

    time_t t = time(0);
    tm* now = localtime(&t);
    int currD = now->tm_mday;
    int currM = now->tm_mon + 1;
    int currY = now->tm_year + 1900;

    if (y < currY) return true;
    if (y == currY && m < currM) return true;
    if (y == currY && m == currM && d < currD) return true;
    return false;
}

Product* findMin(Product* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Product* deleteByCode(Product* root, const string& code) {
    if (root == NULL)
        return NULL;

    root->left = deleteByCode(root->left, code);
    root->right = deleteByCode(root->right, code);

    if (root->code == code) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Product* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Product* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Product* temp = findMin(root->right);
            root->code = temp->code;
            root->name = temp->name;
            root->price = temp->price;
            root->quantity = temp->quantity;
            root->dateReceived = temp->dateReceived;
            root->expiryDate = temp->expiryDate;
            root->right = deleteByCode(root->right, temp->code);
        }
    }
    return root;
}

Product* deleteExpired(Product* root) {
    if (root == NULL)
        return NULL;

    root->left = deleteExpired(root->left);
    root->right = deleteExpired(root->right);

    if (isExpired(root->expiryDate)) {
        cout << "Deleting expired product: " << root->name << " (Code: " << root->code << ")\n";
        root = deleteByCode(root, root->code);
    }

    return root;
}

void displayInorder(Product* root) {
    if (root != NULL) {
        displayInorder(root->left);
        cout << "----------------------------------------\n";
        cout << "Product Code: " << root->code << endl;
        cout << "Product Name: " << root->name << endl;
        cout << "Price: " << root->price << endl;
        cout << "Quantity: " << root->quantity << endl;
        cout << "Date Received: " << root->dateReceived << endl;
        cout << "Expiry Date: " << root->expiryDate << endl;
        displayInorder(root->right);
    }
}

int main() {
    Product* root = NULL;
    int choice, qty;
    float price;
    string code, name, recDate, expDate;

    do {
        cout << "1. Insert Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. Delete Product by Code\n";
        cout << "4. Delete All Expired Products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Product Code: "; cin >> code;
            cout << "Enter Product Name: "; cin >> name;
            cout << "Enter Price: "; cin >> price;
            cout << "Enter Quantity: "; cin >> qty;
            cout << "Enter Date Received (DD/MM/YYYY): "; cin >> recDate;
            cout << "Enter Expiration Date (DD/MM/YYYY): "; cin >> expDate;
            root = insert(root, code, name, price, qty, recDate, expDate);
            cout << "Product inserted successfully.\n";
            break;

        case 2:
            cout << "\n--- Product Inventory (Sorted by Name) ---\n";
            displayInorder(root);
            break;

        case 3:
            cout << "Enter Product Code to delete: "; cin >> code;
            root = deleteByCode(root, code);
            cout << "Product deleted (if existed).\n";
            break;

        case 4:
            cout << "\nDeleting all expired products...\n";
            root = deleteExpired(root);
            cout << "Expired products deleted.\n";
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
