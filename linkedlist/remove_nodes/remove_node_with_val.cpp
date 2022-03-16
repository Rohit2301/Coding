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

Node *del(Node *head, int val)
{
    Node *cur = head;
    while (cur == head && cur != NULL && cur->data == val)
    {
        while (cur->next != NULL && cur->data == cur->next->data)
        {
            cur->next = cur->next->next;
        }
        head = cur->next;
        cur = cur->next;
    }
    Node *prev = head;
    if (!cur)
    {
        cur = cur->next;
    }

    while (cur != NULL)
    {
        if (cur->data == val && cur->next)
        {
            prev->next = cur->next;
            cur = cur->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
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
    head1 = del(head, 4);

    print(head1);

    return 0;
}