#include <iostream>
using namespace std;

struct Song {
    int playCount;
    string title;
    Song* left;
    Song* right;

    Song(int count, string name) {
        playCount = count;
        title = name;
        left = right = nullptr;
    }
};

Song* insert(Song* root, int count, string name) {
    if (root == nullptr)
        return new Song(count, name);

    if (count < root->playCount)
        root->left = insert(root->left, count, name);
    else if (count > root->playCount)
        root->right = insert(root->right, count, name);
    else
        cout << "Duplicate play count not allowed!\n";

    return root;
}

Song* search(Song* root, int count) {
    if (root == nullptr || root->playCount == count)
        return root;

    if (count < root->playCount)
        return search(root->left, count);
    else
        return search(root->right, count);
}

void inorder(Song* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->title << " (" << root->playCount << " plays)\n";
    inorder(root->right);
}

void postorder(Song* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << "Removing: " << root->title << " (" << root->playCount << " plays)\n";
}

Song* findMin(Song* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

Song* deleteSong(Song* root, int count) {
    if (root == nullptr) return root;

    if (count < root->playCount)
        root->left = deleteSong(root->left, count);
    else if (count > root->playCount)
        root->right = deleteSong(root->right, count);
    else {
        if (root->left == nullptr) {
            Song* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Song* temp = root->left;
            delete root;
            return temp;
        }

        Song* temp = findMin(root->right);
        root->playCount = temp->playCount;
        root->title = temp->title;
        root->right = deleteSong(root->right, temp->playCount);
    }
    return root;
}

int main() {
    Song* root = nullptr;

    root = insert(root, 50, "Song A");
    root = insert(root, 30, "Song B");
    root = insert(root, 70, "Song C");
    root = insert(root, 20, "Song D");
    root = insert(root, 40, "Song E");
    root = insert(root, 60, "Song F");
    root = insert(root, 80, "Song G");

    cout << "\n--- Songs in Inorder (Least → Most Played) ---\n";
    inorder(root);

    int searchCount;
    cout << "\nEnter play count to search: ";
    cin >> searchCount;

    Song* found = search(root, searchCount);
    if (found != nullptr)
        cout << "Found: " << found->title << " (" << found->playCount << " plays)\n";
    else
        cout << "No song found with play count " << searchCount << ".\n";

    cout << "\n--- Songs in Postorder (Reverse Popularity) ---\n";
    postorder(root);

    int delCount;
    cout << "\nEnter play count of song to delete: ";
    cin >> delCount;
    root = deleteSong(root, delCount);

    cout << "\n--- Updated Playlist (Inorder) ---\n";
    inorder(root);

    return 0;
}
