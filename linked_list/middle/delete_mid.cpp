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

Node *middleNode(Node *head)
{

    Node *fast = new Node();
    Node *slow = new Node();
    fast = head;
    slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *delMid(Node *head)
{
    Node *mid = middleNode(head);
    if (mid->next)
    {
        (*mid) = *(mid->next);
    }
    else if (mid->next == NULL)
    {
        mid = NULL;
    }

    return head;
}

int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    for (int i = 0; i < 1; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    Node *mid = NULL;
    mid = delMid(head);
    print(mid);

    return 0;
}