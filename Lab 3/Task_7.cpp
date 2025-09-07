#include <iostream>
using namespace std;

struct SNode
{
    int data;
    SNode *next;
    SNode(int val) : data(val), next(nullptr) {}
};

struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

SNode *createSinglyList(int arr[], int n)
{
    SNode *head = new SNode(arr[0]);
    SNode *curr = head;
    for (int i = 1; i < n; ++i)
    {
        curr->next = new SNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

DNode *convertToDoubly(SNode *head)
{
    if (!head)
        return nullptr;
    DNode *dhead = new DNode(head->data);
    DNode *dcurr = dhead;
    head = head->next;
    while (head)
    {
        DNode *node = new DNode(head->data);
        dcurr->next = node;
        node->prev = dcurr;
        dcurr = node;
        head = head->next;
    }
    return dhead;
}

SNode *convertToCircular(SNode *head)
{
    if (!head)
        return nullptr;
    SNode *curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = head;
    return head;
}

void printSingly(SNode *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printDoubly(DNode *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printCircular(SNode *head, int n)
{
    SNode *curr = head;
    for (int i = 0; i < n; ++i)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    SNode *sHead = createSinglyList(arr, n);
    cout << "Singly Linked List: ";
    printSingly(sHead);
    DNode *dHead = convertToDoubly(sHead);
    cout << "Doubly Linked List: ";
    printDoubly(dHead);
    SNode *cHead = convertToCircular(sHead);
    cout << "Circular Linked List: ";
    printCircular(cHead, n * 2);
    return 0;
}
