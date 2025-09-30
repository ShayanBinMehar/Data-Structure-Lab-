#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack
{
    char arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void reverse(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void swapBrackets(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}

void infixToPrefix(const char *infix, char *prefix)
{
    char revInfix[MAX_SIZE], revPrefix[MAX_SIZE];
    int i = 0;
    while (infix[i] != '\0')
    {
        revInfix[i] = infix[i];
        i++;
    }
    revInfix[i] = '\0';
    reverse(revInfix);
    swapBrackets(revInfix);

    Stack s;
    int j = 0;
    for (int k = 0; revInfix[k] != '\0'; k++)
    {
        char c = revInfix[k];
        if (c >= '0' && c <= '9')
        {
            revPrefix[j++] = c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                revPrefix[j++] = s.pop();
            if (!s.isEmpty())
                s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.peek()) > precedence(c))
                revPrefix[j++] = s.pop();
            s.push(c);
        }
    }
    while (!s.isEmpty())
        revPrefix[j++] = s.pop();
    revPrefix[j] = '\0';
    reverse(revPrefix);
    i = 0;
    while (revPrefix[i] != '\0')
    {
        prefix[i] = revPrefix[i];
        i++;
    }
    prefix[i] = '\0';
}

int evalPrefix(const char *prefix)
{
    int vals[MAX_SIZE], top = -1;
    int len = 0;
    while (prefix[len] != '\0')
        len++;
    for (int i = len - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (c >= '0' && c <= '9')
        {
            vals[++top] = c - '0';
        }
        else if (isOperator(c))
        {
            int a = vals[top--];
            int b = vals[top--];
            int res = 0;
            switch (c)
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
            case '^':
            {
                res = 1;
                for (int k = 0; k < b; k++)
                    res *= a;
                break;
            }
            }
            vals[++top] = res;
        }
    }
    return vals[top];
}

int main()
{
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    cout << "Enter infix expression (single-digit operands, e.g. (3+4)*2): ";
    cin >> infix;
    infixToPrefix(infix, prefix);
    cout << "Prefix: " << prefix << endl;
    cout << "Evaluation result: " << evalPrefix(prefix) << endl;
    return 0;
}