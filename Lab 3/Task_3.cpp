#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k <= 1)
        return head;

    ListNode *temp = head;
    for (int i = 0; i < k; i++)
    {
        if (!temp)
            return head;
        temp = temp->next;
    }

    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *nxt = nullptr;
    int count = 0;

    while (curr && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    head->next = reverseKGroup(curr, k);

    return prev;
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
    cout << endl;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    ListNode *n7 = new ListNode(7);
    ListNode *n8 = new ListNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    cout << "Original List:\n";
    printList(n1);

    int k = 3;
    ListNode *newHead = reverseKGroup(n1, k);

    cout << "\nList after reversing in groups of " << k << ":\n";
    printList(newHead);

    return 0;
}
