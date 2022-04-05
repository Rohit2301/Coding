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

Node *oddEvenList(Node *head)
{
    if (!head || !head->next)
        return NULL;

    Node *prev = head;
    Node *evenEnd = prev->next;

    Node *forw = head->next->next;
    Node *oddNxt = NULL;

    while (forw)
    {
        oddNxt = forw->next;

        forw->next = prev->next;
        prev->next = forw;
        evenEnd->next = oddNxt;

        prev = prev->next;
        evenEnd = evenEnd->next;
        if (!oddNxt)
            break;
        forw = oddNxt->next;
    }
    return head;
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
