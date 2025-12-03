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
    int currY = now->tm_year + 1900;
    int currM = now->tm_mon + 1;
    int currD = now->tm_mday;

    if (y < currY) return true;
    if (y == currY && m < currM) return true;
    if (y == currY && m == currM && d < currD) return true;
    return false;
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
    }
}

void listExpiredProducts(Product* root) {
    if (root != NULL) {
        if (isExpired(root->expiryDate)) {
            cout << "----------------------------------------\n";
            cout << "Expired Product: " << root->name << endl;
            cout << "Product Code: " << root->code << endl;
            cout << "Price: " << root->price << endl;
            cout << "Quantity: " << root->quantity << endl;
            cout << "Expiry Date: " << root->expiryDate << endl;
        }
        listExpiredProducts(root->left);
        listExpiredProducts(root->right);
    }
}

int main() {
    Product* root = NULL;
    int choice, qty;
    string code, name, recDate, expDate;
    float price;

    do {
        cout << "1. Insert a Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. List Expired Products (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nEnter Product Code: ";
            cin >> code;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Date Received (DD/MM/YYYY): ";
            cin >> recDate;
            cout << "Enter Expiration Date (DD/MM/YYYY): ";
            cin >> expDate;
            root = insert(root, code, name, price, qty, recDate, expDate);
            cout << "Product inserted successfully.\n";
            break;

        case 2:
            cout << "\nProduct Inventory (Sorted by Name)\n";
            displayInorder(root);
            break;

        case 3:
            cout << "\nExpired Products\n";
            listExpiredProducts(root);
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
