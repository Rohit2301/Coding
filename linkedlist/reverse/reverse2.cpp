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

Node *reverseBetween(Node *head, int m, int n)
{
    Node *dummy = new Node, *pre = dummy, *cur;
    dummy->next = head;
    for (int i = 0; i < m - 1; i++)
    {
        pre = pre->next;
    }
    cur = pre->next;
    for (int i = 0; i < n - m; i++)
    {
        Node *temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
    }
    return dummy->next;
}

int main()
{
    Node *head = new Node();
    head->data = 0;
    head->next = NULL;

    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    Node *head1 = reverseBetween(head, 1, 3);

    print(head1);

    return 0;
}
