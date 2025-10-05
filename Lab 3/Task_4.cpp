#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

int josephus(int n, int k)
{
    if (n == 1)
        return 1;

    Node *head = new Node(1);
    Node *prev = head;

    for (int i = 2; i <= n; i++)
    {
        prev->next = new Node(i);
        prev = prev->next;
    }
    prev->next = head;

    Node *current = head;
    Node *previous = nullptr;

    while (current->next != current)
    {
        for (int count = 1; count < k; count++)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    int survivor = current->data;
    delete current;

    return survivor;
}

int main()
{
    int n = 7;
    int k = 3;

    int result = josephus(n, k);

    cout << "Josephus Problem: N = " << n << ", k = " << k << endl;
    cout << "The safe position is: " << result << endl;

    cout << "\nOther test cases:" << endl;
    cout << "N = 5, k = 2: " << josephus(5, 2) << endl;
    cout << "N = 14, k = 2: " << josephus(14, 2) << endl;
    cout << "N = 40, k = 7: " << josephus(40, 7) << endl;

    return 0;
}