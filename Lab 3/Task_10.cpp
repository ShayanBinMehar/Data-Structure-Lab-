#include <iostream>
using namespace std;

struct PolyNode
{
    int coeff, exp;
    PolyNode *next;
    PolyNode(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

void insertTerm(PolyNode *&head, int coeff, int exp)
{
    if (coeff == 0)
        return;
    PolyNode *node = new PolyNode(coeff, exp);
    if (!head || exp > head->exp)
    {
        node->next = head;
        head = node;
        return;
    }
    PolyNode *curr = head;
    PolyNode *prev = nullptr;
    while (curr && curr->exp > exp)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->exp == exp)
    {
        curr->coeff += coeff;
        delete node;
        if (curr->coeff == 0)
        {
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;
            delete curr;
        }
    }
    else
    {
        node->next = curr;
        if (prev)
            prev->next = node;
        else
            head = node;
    }
}

PolyNode *addPoly(PolyNode *p1, PolyNode *p2)
{
    PolyNode *res = nullptr;
    while (p1)
    {
        insertTerm(res, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2)
    {
        insertTerm(res, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return res;
}

PolyNode *multiplyPoly(PolyNode *p1, PolyNode *p2)
{
    PolyNode *res = nullptr;
    for (PolyNode *a = p1; a; a = a->next)
    {
        for (PolyNode *b = p2; b; b = b->next)
        {
            insertTerm(res, a->coeff * b->coeff, a->exp + b->exp);
        }
    }
    return res;
}

void printPoly(PolyNode *head)
{
    PolyNode *curr = head;
    bool first = true;
    while (curr)
    {
        if (!first && curr->coeff > 0)
            cout << " + ";
        if (curr->exp == 0)
            cout << curr->coeff;
        else if (curr->exp == 1)
            cout << curr->coeff << "x";
        else
            cout << curr->coeff << "x^" << curr->exp;
        first = false;
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    // P1 = 3x^2 + 2x + 1
    PolyNode *P1 = nullptr;
    insertTerm(P1, 3, 2);
    insertTerm(P1, 2, 1);
    insertTerm(P1, 1, 0);
    // P2 = x^2 + x
    PolyNode *P2 = nullptr;
    insertTerm(P2, 1, 2);
    insertTerm(P2, 1, 1);
    cout << "P1: ";
    printPoly(P1);
    cout << "P2: ";
    printPoly(P2);
    PolyNode *sum = addPoly(P1, P2);
    cout << "P1 + P2 = ";
    printPoly(sum);
    PolyNode *prod = multiplyPoly(P1, P2);
    cout << "P1 * P2 = ";
    printPoly(prod);
    // Free memory (not shown for brevity)
    return 0;
}
