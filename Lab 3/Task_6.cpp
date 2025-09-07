#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *createCircle(int n)
{
    Node *head = new Node(1);
    Node *prev = head;
    for (int i = 2; i <= n; ++i)
    {
        Node *node = new Node(i);
        prev->next = node;
        prev = node;
    }
    prev->next = head;
    return head;
}

int josephus(int n, int k)
{
    Node *head = createCircle(n);
    Node *prev = nullptr;
    Node *curr = head;
    int count = n;
    while (count > 1)
    {
        for (int i = 1; i < k; ++i)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        Node *temp = curr;
        curr = curr->next;
        delete temp;
        count--;
    }
    int survivor = curr->data;
    delete curr;
    return survivor;
}

int main()
{
    int n = 7, k = 3;
    cout << "Survivor position for n=" << n << ", k=" << k << ": " << josephus(n, k) << endl;
    return 0;
}
