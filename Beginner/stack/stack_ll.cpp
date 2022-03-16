#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *top = NULL;
bool isEmpty()
{
    return top == NULL;
}
void push(int val)
{
    Node *temp = new Node();
    if (!temp)
    {
        cout << "stack overflow";
        exit(1);
    }

    temp->data = val;
    temp->next = top;
    top = temp;
}

int peek()
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        exit(1);
    }
}

int pop()
{
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    Node *temp = top;
    int val = top->data;
    top = top->next;
    free(temp);
    return val;
}

void display()
{
    Node *temp;
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    cout << "\n Top: " << peek();

    pop();
    pop();
    display();

    return 0;
}