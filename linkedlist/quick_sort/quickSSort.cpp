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
Node *partition(Node *head, Node *tail)
{
    int pivot = head->data;
    Node *p = head;
    Node *q = head;
    while (q != tail)
    {
        if (q->data < pivot)
        {
            p = p->next;
            swap(p->data, q->data);
        }
        q = q->next;
    }
    swap(p->data, head->data);
    return p;
}

void quick(Node *head, Node *tail)
{
    if (head != tail)
    {
        Node *index = partition(head, tail);
        quick(head, index);
        quick(index->next, tail);
    }
}
void quickSort(Node **headRef)
{

    quick(*headRef, NULL);
}

int main()
{
    Node *head = new Node();
    for (int i = 0; i < 7; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    quickSort(&head->next);
    cout << endl;
    print(head->next);

    return 0;
}
