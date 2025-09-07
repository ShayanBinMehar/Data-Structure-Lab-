#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

Node *flatten(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->child)
        {
            Node *childTail = curr->child;
            while (childTail->next)
                childTail = childTail->next;
            childTail->next = curr->next;
            curr->next = curr->child;
            curr->child = nullptr;
        }
        curr = curr->next;
    }
    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example: 1 -> 2 -> 3, 2 has child 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    cout << "Original multilevel list: 1 -> 2 -> 3, 2 has child 4 -> 5" << endl;
    head = flatten(head);
    cout << "Flattened list: ";
    printList(head);
    // Free memory (not shown for brevity)
    return 0;
}
