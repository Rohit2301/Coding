#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void add(Node *head, int val)
{
    while (head->next != NULL)
    {
        head = head->next;
    }

    Node *temp = new Node();
    temp->data = val;
    temp->next = NULL;
    head->next = temp;
}

void del(Node *head, int val)
{
}

Node *delDup(Node *head)
{

    return head;
}

int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    add(head, 1);
    add(head, 2);
    add(head, 3);
    add(head, 3);

    print(head);

    return 0;
}