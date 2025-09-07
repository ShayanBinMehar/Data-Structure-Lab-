#include <iostream>
using namespace std;

struct Node
{
    int key, value;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
    int capacity, size;
    Node *head, *tail;
    Node *map[100];
public:
    LRUCache(int cap) : capacity(cap), size(0), head(nullptr), tail(nullptr)
    {
        for (int i = 0; i < 100; ++i)
            map[i] = nullptr;
    }
    int get(int key)
    {
        if (key < 0 || key >= 100 || !map[key])
            return -1;
        Node *node = map[key];
        moveToFront(node);
        return node->value;
    }
    void put(int key, int value)
    {
        if (key < 0 || key >= 100)
            return;
        if (map[key])
        {
            map[key]->value = value;
            moveToFront(map[key]);
        }
        else
        {
            Node *node = new Node(key, value);
            map[key] = node;
            addToFront(node);
            size++;
            if (size > capacity)
            {
                removeLRU();
            }
        }
    }

private:
    void moveToFront(Node *node)
    {
        if (node == head)
            return;
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        if (node == tail)
            tail = node->prev;
        node->prev = nullptr;
        node->next = head;
        if (head)
            head->prev = node;
        head = node;
        if (!tail)
            tail = head;
    }
    void addToFront(Node *node)
    {
        node->prev = nullptr;
        node->next = head;
        if (head)
            head->prev = node;
        head = node;
        if (!tail)
            tail = head;
    }
    void removeLRU()
    {
        if (!tail)
            return;
        int k = tail->key;
        Node *prevTail = tail;
        if (tail->prev)
            tail->prev->next = nullptr;
        tail = tail->prev;
        if (!tail)
            head = nullptr;
        map[k] = nullptr;
        delete prevTail;
        size--;
    }
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << "get(1): " << cache.get(1) << std::endl; 
    cache.put(3, 30);                                     
    std::cout << "get(2): " << cache.get(2) << std::endl; 
    std::cout << "get(3): " << cache.get(3) << std::endl; 
    cache.put(1, 100);                                    
    std::cout << "get(1): " << cache.get(1) << std::endl;
    cache.put(4, 40);                                     
    std::cout << "get(3): " << cache.get(3) << std::endl;
    std::cout << "get(4): " << cache.get(4) << std::endl;
    return 0;
}
