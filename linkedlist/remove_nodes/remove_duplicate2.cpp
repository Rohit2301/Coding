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

Node *delDup(Node **head)
{
    Node *cur = *head;
    Node *prev = *head;

    while (cur == *head && *head != NULL)
    {
        int f = 0;
        while (cur->next != NULL && cur->next->data == cur->data)
        {
            f = 1;
            cur->next = cur->next->next;
        }
        if (f)
        {
            *head = cur->next;
        }
        cur = cur->next;
    }
    prev = *head;

    while (cur != NULL)
    {
        int f = 0;
        while (cur->next != NULL && cur->next->data == cur->data)
        {
            f = 1;
            cur->next = cur->next->next;
        }
        if (f)
        {
            prev->next = cur->next;
        }
        else
        {
            prev = prev->next;
        }

        cur = cur->next;
    }

    return *head;
}

int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    Node *head1 = new Node();
    head1 = delDup(&head);

    print(head1);

    return 0;
}