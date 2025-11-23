#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* n) {
    return (n == nullptr ? 0 : n->height);
}

int maxH(int a, int b) {
    return (a > b ? a : b);
}

int getBalance(Node* n) {
    return (n == nullptr ? 0 : getHeight(n->left) - getHeight(n->right));
}

Node* createNode(int price) {
    Node* n = new Node;
    n->price = price;
    n->left = n->right = nullptr;
    n->height = 1;
    return n;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxH(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxH(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxH(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxH(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int price) {
    if (root == nullptr)
        return createNode(price);

    if (price < root->price)
        root->left = insert(root->left, price);
    else if (price > root->price)
        root->right = insert(root->right, price);
    else
        return root;

    root->height = 1 + maxH(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && price < root->left->price)
        return rotateRight(root);

    if (balance < -1 && price > root->right->price)
        return rotateLeft(root);

    if (balance > 1 && price > root->left->price) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && price < root->right->price) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void rangeQuery(Node* root, int X, int Y) {
    if (root == nullptr) return;

    if (root->price > X)
        rangeQuery(root->left, X, Y);

    if (root->price >= X && root->price <= Y)
        cout << root->price << " ";

    if (root->price < Y)
        rangeQuery(root->right, X, Y);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->price << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int choice, price, X, Y;

    while (true) {
        cout << "\n--- Product Price AVL Menu ---\n";
        cout << "1. Insert product price\n";
        cout << "2. Display all prices (sorted)\n";
        cout << "3. Range Query (X - Y)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter price: ";
            cin >> price;
            root = insert(root, price);
            cout << "Inserted.\n";
        }
        else if (choice == 2) {
            cout << "Product Prices (sorted): ";
            inorder(root);
            cout << endl;
        }
        else if (choice == 3) {
            cout << "Enter X: ";
            cin >> X;
            cout << "Enter Y: ";
            cin >> Y;

            cout << "Prices in range [" << X << ", " << Y << "]: ";
            rangeQuery(root, X, Y);
            cout << endl;
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
