#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack
{
    char arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}
    void push(char x) 
    { arr[++top] = x; }
    char pop() 
    { return arr[top--]; }
    char peek() 
    { return arr[top]; }
    bool isEmpty()
    { return top == -1; }
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

void infixToPostfix(const char *infix, char *postfix)
{
    Stack s;
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (c >= '0' && c <= '9')
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                postfix[j++] = s.pop();
            if (!s.isEmpty())
                s.pop(); // pop '('
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix[j++] = s.pop();
            s.push(c);
        }
    }
    while (!s.isEmpty())
        postfix[j++] = s.pop();
    postfix[j] = '\0';
}

int evalPostfix(const char *postfix)
{
    Stack s;
    int vals[MAX_SIZE], top = -1;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];
        if (c >= '0' && c <= '9')
        {
            vals[++top] = c - '0';
        }
        else if (isOperator(c))
        {
            int b = vals[top--];
            int a = vals[top--];
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
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    cout << "Enter infix expression (single-digit operands, e.g. (3+4)*2): ";
    cin >> infix;
    infixToPostfix(infix, postfix);
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluation result: " << evalPostfix(postfix) << endl;
    return 0;
}