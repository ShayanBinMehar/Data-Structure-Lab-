#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    while (head)
    {
        ListNode *nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *second = reverseList(slow->next);

    ListNode *p1 = head;
    ListNode *p2 = second;
    bool ok = true;
    while (p2)
    {
        if (p1->val != p2->val)
        {
            ok = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    slow->next = reverseList(second);
    return ok;
}

int main()
{

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(2);
    ListNode *n5 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    cout << boolalpha << isPalindrome(n1) << "\n";

    ListNode *cur = n1;
    while (cur)
    {
        ListNode *nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    return 0;
}