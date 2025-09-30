#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack
{
    int arr[MAX_SIZE];
    int top;

public:
    Stack() { top = -1; }

    void push(int x)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack\n";
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from stack\n";
    }

    void peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack contents: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, value;
    do
    {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}