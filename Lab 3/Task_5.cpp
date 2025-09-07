#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque
{
    Node *front;
    Node *rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}
    void insertFront(int x)
    {
        Node *node = new Node(x);
        if (!front)
        {
            front = rear = node;
        }
        else
        {
            node->next = front;
            front->prev = node;
            front = node;
        }
    }
    void insertRear(int x)
    {
        Node *node = new Node(x);
        if (!rear)
        {
            front = rear = node;
        }
        else
        {
            rear->next = node;
            node->prev = rear;
            rear = node;
        }
    }
    void deleteFront()
    {
        if (!front)
        {
            cout << "Deque is empty!\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front)
            front->prev = nullptr;
        else
            rear = nullptr;
        delete temp;
    }
    void deleteRear()
    {
        if (!rear)
        {
            cout << "Deque is empty!\n";
            return;
        }
        Node *temp = rear;
        rear = rear->prev;
        if (rear)
            rear->next = nullptr;
        else
            front = nullptr;
        delete temp;
    }
    int getFront()
    {
        if (!front)
        {
            cout << "Deque is empty!\n";
            return -1;
        }
        return front->data;
    }
    int getRear()
    {
        if (!rear)
        {
            cout << "Deque is empty!\n";
            return -1;
        }
        return rear->data;
    }
    void printDeque()
    {
        Node *curr = front;
        cout << "Deque: ";
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    ~Deque()
    {
        while (front)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    Deque dq;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);
    dq.printDeque();                            // 1 5 10 20
    cout << "Front: " << dq.getFront() << endl; // 1
    cout << "Rear: " << dq.getRear() << endl;   // 20
    dq.deleteFront();
    dq.printDeque(); // 5 10 20
    dq.deleteRear();
    dq.printDeque(); // 5 10
    dq.deleteFront();
    dq.deleteRear();
    dq.printDeque();  // empty
    dq.deleteFront(); // error
    dq.deleteRear();  // error
    return 0;
}
