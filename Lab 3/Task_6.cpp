#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

class MultilevelList
{
public:
    Node *createSampleList()
    {
        Node *head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        head->next->next->next = new Node(4);
        head->next->next->next->next = new Node(5);
        head->next->next->next->next->next = new Node(6);

        head->child = new Node(7);
        head->child->next = new Node(8);
        head->child->next->next = new Node(9);

        head->next->next->child = new Node(10);
        head->next->next->child->next = new Node(11);

        head->next->next->next->child = new Node(12);
        head->next->next->next->child->next = new Node(13);

        return head;
    }

    Node *createExampleList()
    {

        Node *head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);

        head->child = new Node(4);
        head->child->next = new Node(5);

        return head;
    }

    Node *flattenList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *current = head;
        Node *tail = head;

        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        while (current != nullptr)
        {
            if (current->child != nullptr)
            {
                tail->next = current->child;

                Node *temp = current->child;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                tail = temp;

                current->child = nullptr;
            }
            current = current->next;
        }

        return head;
    }

    void printList(Node *head)
    {
        Node *current = head;
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

    void printMultilevelList(Node *head, int level = 0)
    {
        if (head == nullptr)
            return;

        Node *current = head;
        while (current != nullptr)
        {
            for (int i = 0; i < level; i++)
            {
                cout << "  ";
            }
            cout << current->data;
            if (current->child != nullptr)
            {
                cout << " -> (child)";
            }
            cout << endl;

            if (current->child != nullptr)
            {
                printMultilevelList(current->child, level + 1);
            }
            current = current->next;
        }
    }

    void deleteList(Node *head)
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    MultilevelList list;

    cout << "=== MULTILEVEL LINKED LIST FLATTENING ===" << endl;

    cout << "\n1. Example from problem:" << endl;
    cout << "Input structure:" << endl;
    cout << "1 -> 2 -> 3" << endl;
    cout << "|" << endl;
    cout << "4 -> 5" << endl;

    Node *exampleList = list.createExampleList();
    cout << "\nOriginal multilevel list:" << endl;
    list.printMultilevelList(exampleList);

    Node *flattenedExample = list.flattenList(exampleList);
    cout << "\nFlattened list: ";
    list.printList(flattenedExample);

    cout << "\n2. More complex example:" << endl;
    Node *complexList = list.createSampleList();

    cout << "Original multilevel list structure:" << endl;
    list.printMultilevelList(complexList);

    Node *flattenedComplex = list.flattenList(complexList);
    cout << "\nFlattened list: ";
    list.printList(flattenedComplex);

    list.deleteList(flattenedExample);
    list.deleteList(flattenedComplex);

    return 0;
}