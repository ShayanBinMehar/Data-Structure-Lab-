#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *a, ListNode *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    if (a->val <= b->val)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    while (a && b)
    {
        if (a->val <= b->val)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    tail->next = (a ? a : b);
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(3);
    ListNode *a3 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;

    ListNode *b1 = new ListNode(2);
    ListNode *b2 = new ListNode(4);
    ListNode *b3 = new ListNode(6);
    b1->next = b2;
    b2->next = b3;

    ListNode *merged = mergeTwoLists(a1, b1);
    printList(merged);

    while (merged)
    {
        ListNode *nxt = merged->next;
        delete merged;
        merged = nxt;
    }
    return 0;
}