#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    };

    Node(int val)
    {
        data = val;
        next = NULL;
    };
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
    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void reverseMiddle(Node *mid)
{

    Node *prev = mid;
    Node *curr = mid->next;

    while (curr->next)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
}

void reorderList(Node *head)
{
    if (!head || !head->next)
        return;

    Node *mid = middleNode(head);
    reverseMiddle(mid);

    Node *p1 = head;
    Node *p2 = mid->next;
    while (p1 != mid)
    {
        mid->next = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = mid->next;
    }
}

int main()
{
    Node *head = new Node(1);

    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    return 0;
}
