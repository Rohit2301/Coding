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
    fast = head->next;
    slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    Node *mid = NULL;
    mid = middleNode(head);
    cout << mid->data;

    return 0;
}