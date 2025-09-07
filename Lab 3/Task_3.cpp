#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (!fast || !fast->next)
        return nullptr;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void printCycleStart(ListNode *start)
{
    if (start)
        cout << "Cycle starts at node with value: " << start->val << "\n";
    else
        cout << "No cycle\n";
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;

    ListNode *start = detectCycle(n1);
    printCycleStart(start);

    return 0;
}