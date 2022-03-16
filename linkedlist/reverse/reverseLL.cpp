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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *cur = head;
    if (!cur)
    {
        return NULL;
    }

    while (cur->next)
    {
        Node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    cur->next = prev;

    return cur;
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

    Node *head1 = reverse(head);

    print(head1);

    return 0;
}