#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string url;
    Node *next;
    Node(string u) : url(u), next(nullptr) {}
};

class Stack
{
    Node *top;

public:
    Stack() : top(nullptr) {}

    void push(string url)
    {
        Node *newNode = new Node(url);
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << url << endl;
    }

    void pop()
    {
        if (!top)
        {
            cout << "No previous page (history empty)\n";
            return;
        }
        cout << "Going back from: " << top->url << endl;
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    void peek()
    {
        if (!top)
        {
            cout << "No current page\n";
            return;
        }
        cout << "Current page: " << top->url << endl;
    }

    void display()
    {
        if (!top)
        {
            cout << "History is empty\n";
            return;
        }
        cout << "Browser History:\n";
        Node *curr = top;
        while (curr)
        {
            cout << curr->url << endl;
            curr = curr->next;
        }
    }

    ~Stack()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack history;
    int choice;
    string url;
    do
    {
        cout << "\n1. Visit new page\n2. Back\n3. Current page\n4. Show history\n5. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter URL: ";
            getline(cin, url);
            history.push(url);
            break;
        case 2:
            history.pop();
            break;
        case 3:
            history.peek();
            break;
        case 4:
            history.display();
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