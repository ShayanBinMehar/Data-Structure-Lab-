#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n) {
    return (n == nullptr ? 0 : n->height);
}

int getBalance(Node* n) {
    return (n == nullptr ? 0 : height(n->left) - height(n->right));
}

int maxH(int a, int b) {
    return (a > b ? a : b);
}

Node* createNode(int key) {
    Node* n = new Node;
    n->key = key;
    n->left = n->right = nullptr;
    n->height = 1;
    return n;
}
Node* rotateRight(Node* y) {
    cout << "Rotation: RIGHT rotation on " << y->key << endl;

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxH(height(y->left), height(y->right)) + 1;
    x->height = maxH(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    cout << "Rotation: LEFT rotation on " << x->key << endl;

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxH(height(x->left), height(x->right)) + 1;
    y->height = maxH(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        cout << "Inserted " << key << endl;
        return createNode(key);
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + maxH(height(root->left), height(root->right));

    int balance = getBalance(root);

    cout << "Node " << root->key
         << " balance factor = " << balance << endl;

    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    if (balance > 1 && key > root->left->key) {
        cout << "Rotation: LEFT-RIGHT\n";
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && key < root->right->key) {
        cout << "Rotation: RIGHT-LEFT\n";
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* minValueNode(Node* n) {
    Node* current = n;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        cout << "Deleted " << key << endl;

        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + maxH(height(root->left), height(root->right));

    int balance = getBalance(root);

    cout << "Node " << root->key
         << " balance factor = " << balance << endl;

    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        cout << "Rotation: LEFT-RIGHT\n";
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        cout << "Rotation: RIGHT-LEFT\n";
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int n, x, del;
    cout << "How many roll numbers to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter roll: ";
        cin >> x;

        root = insert(root, x);
        cout << "Tree height = " << height(root) << endl;
        cout << "----------------------------\n";
    }

    cout << "\nHow many roll numbers to delete? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Delete roll: ";
        cin >> del;

        root = deleteNode(root, del);
        cout << "Tree height = " << height(root) << endl;
        cout << "----------------------------\n";
    }

    cout << "\nFinal AVL Tree (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
