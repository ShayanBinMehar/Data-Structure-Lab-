#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *reverseKGroup(Node *head, int k)
{
    Node *curr = head;
    int count = 0;

    while (curr && count < k)
    {
        curr = curr->next;
        count++;
    }
    if (count < k)
        return head;

    curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    count = 0;
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
    {
        head->next = reverseKGroup(next, k);
    }
    return prev;
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    Node *head = new Node(arr[0]);
    Node *curr = head;
    for (int i = 1; i < n; ++i)
    {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    cout << "Original list: ";
    printList(head);
    head = reverseKGroup(head, k);
    cout << "Reversed in groups of " << k << ": ";
    printList(head);
    // Free memory
    curr = head;
    while (curr)
    {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
    return 0;
}
