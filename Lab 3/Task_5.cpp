#include <iostream>
using namespace std;

struct SinglyNode
{
    int data;
    SinglyNode *next;
    SinglyNode(int val) : data(val), next(nullptr) {}
};

struct DoublyNode
{
    int data;
    DoublyNode *next;
    DoublyNode *prev;
    DoublyNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedListConverter
{
public:
    SinglyNode *createSinglyList(int arr[], int n)
    {
        if (n == 0)
            return nullptr;

        SinglyNode *head = new SinglyNode(arr[0]);
        SinglyNode *current = head;

        for (int i = 1; i < n; i++)
        {
            current->next = new SinglyNode(arr[i]);
            current = current->next;
        }

        return head;
    }

    DoublyNode *singlyToDoubly(SinglyNode *head)
    {
        if (head == nullptr)
            return nullptr;

        DoublyNode *dHead = new DoublyNode(head->data);
        DoublyNode *dCurrent = dHead;
        SinglyNode *sCurrent = head->next;
        DoublyNode *dPrev = nullptr;

        dCurrent->prev = dPrev;

        while (sCurrent != nullptr)
        {
            dPrev = dCurrent;
            dCurrent->next = new DoublyNode(sCurrent->data);
            dCurrent = dCurrent->next;
            dCurrent->prev = dPrev;

            sCurrent = sCurrent->next;
        }

        return dHead;
    }

    SinglyNode *singlyToCircular(SinglyNode *head)
    {
        if (head == nullptr)
            return nullptr;

        SinglyNode *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = head;

        return head;
    }

    void printSinglyList(SinglyNode *head)
    {
        SinglyNode *current = head;
        while (current != nullptr)
        {
            cout << current->data;
            if (current->next != nullptr)
            {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void printDoublyList(DoublyNode *head)
    {
        DoublyNode *current = head;
        while (current != nullptr)
        {
            cout << current->data;
            if (current->next != nullptr)
            {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void printDoublyListReverse(DoublyNode *head)
    {
        if (head == nullptr)
            return;

        DoublyNode *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        while (current != nullptr)
        {
            cout << current->data;
            if (current->prev != nullptr)
            {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << endl;
    }

    void printCircularList(SinglyNode *head, int n)
    {
        if (head == nullptr)
            return;

        SinglyNode *current = head;
        cout << "Circular list (first " << n << " nodes): ";

        for (int i = 0; i < n; i++)
        {
            cout << current->data;
            if (i < n - 1)
            {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " -> ... (loops back to " << head->data << ")" << endl;
    }

    void verifyCircular(SinglyNode *head)
    {
        if (head == nullptr)
        {
            cout << "Empty list" << endl;
            return;
        }

        SinglyNode *slow = head;
        SinglyNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cout << "✓ Verified: List is circular" << endl;
                return;
            }
        }

        cout << "✗ List is not circular" << endl;
    }

    void deleteSinglyList(SinglyNode *head)
    {
        while (head != nullptr)
        {
            SinglyNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteDoublyList(DoublyNode *head)
    {
        while (head != nullptr)
        {
            DoublyNode *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedListConverter converter;

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "=== LINKED LIST CONVERSIONS ===" << endl;

    SinglyNode *singlyList = converter.createSinglyList(arr, n);
    cout << "\n1. Original Singly Linked List:" << endl;
    converter.printSinglyList(singlyList);

    cout << "\n2. Converted to Doubly Linked List:" << endl;
    DoublyNode *doublyList = converter.singlyToDoubly(singlyList);
    cout << "Forward:  ";
    converter.printDoublyList(doublyList);
    cout << "Backward: ";
    converter.printDoublyListReverse(doublyList);

    cout << "\n3. Converted to Circular Linked List:" << endl;
    SinglyNode *circularList = converter.singlyToCircular(singlyList);
    converter.printCircularList(circularList, 8);
    converter.verifyCircular(circularList);

    cout << "\n=== ANOTHER EXAMPLE ===" << endl;
    int arr2[] = {10, 20, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    SinglyNode *singlyList2 = converter.createSinglyList(arr2, n2);
    cout << "Original: ";
    converter.printSinglyList(singlyList2);

    DoublyNode *doublyList2 = converter.singlyToDoubly(singlyList2);
    cout << "Doubly:   ";
    converter.printDoublyList(doublyList2);

    SinglyNode *circularList2 = converter.singlyToCircular(singlyList2);
    converter.printCircularList(circularList2, 6);
    converter.verifyCircular(circularList2);

    converter.deleteDoublyList(doublyList);
    converter.deleteDoublyList(doublyList2);

    return 0;
}