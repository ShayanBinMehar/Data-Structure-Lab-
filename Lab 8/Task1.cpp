#include <iostream>
using namespace std;

struct FamilyMember {
    string name;
    FamilyMember* mother; 
    FamilyMember* father; 

    FamilyMember(string n) {
        name = n;
        mother = nullptr;
        father = nullptr;
    }
};

FamilyMember* createFamilyTree() {
    FamilyMember* A = new FamilyMember("A"); 
    FamilyMember* B = new FamilyMember("B"); 
    FamilyMember* C = new FamilyMember("C"); 
    FamilyMember* D = new FamilyMember("D"); 
    FamilyMember* E = new FamilyMember("E"); 
    FamilyMember* F = new FamilyMember("F"); 
    FamilyMember* G = new FamilyMember("G"); 

    A->mother = B;
    A->father = C;

    B->mother = D;
    B->father = E;

    C->mother = F;
    C->father = G;

    return A;
}

void printRoot(FamilyMember* root) {
    if (root != nullptr)
        cout << "Root (Youngest Person): " << root->name << endl;
}

void printLeafNodes(FamilyMember* node) {
    if (node == nullptr)
        return;

    if (node->mother == nullptr && node->father == nullptr)
        cout << "Leaf Node (Ancestor): " << node->name << endl;

    printLeafNodes(node->mother);
    printLeafNodes(node->father);
}

int height(FamilyMember* node) {
    if (node == nullptr)
        return 0;

    int leftH = height(node->mother);
    int rightH = height(node->father);

    return 1 + (leftH > rightH ? leftH : rightH);
}

void printLevels(FamilyMember* node, int level) {
    if (node == nullptr)
        return;

    cout << "Member: " << node->name << " at Level: " << level << endl;

    printLevels(node->mother, level + 1);
    printLevels(node->father, level + 1);
}

int main() {
    FamilyMember* root = createFamilyTree();

    printRoot(root);
    cout << endl;

    cout << "Leaf Nodes:\n";
    printLeafNodes(root);
    cout << endl;

    int h = height(root);
    cout << "Height of Tree: " << h << endl << endl;

    cout << "Levels of Each Member:\n";
    printLevels(root, 0);

    return 0;
}
