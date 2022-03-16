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

Node *Merge(Node *head1, Node *head2)
{
    Node *head = new Node();
    Node *merged = new Node();
    head = merged;
    while (head1 && head2)
    {
        if (head1->data > head2->data)
        {
            merged->next = head2;
            merged = merged->next;
            head2 = head2->next;
        }
        else
        {
            merged->next = head1;
            merged = merged->next;
            head1 = head1->next;
        }
    }

    while (head1)
    {
        merged->next = head1;
        merged = merged->next;
        head1 = head1->next;
    }
    while (head2)
    {
        merged->next = head2;
        merged = merged->next;
        head2 = head2->next;
    }

    return head->next;
}

int main()
{
    Node *head1 = new Node(2);

    for (int i = 0; i < 2; i++)
    {
        int n;
        cin >> n;
        add(head1, n);
    }
    Node *head2 = new Node(5);

    for (int i = 0; i < 3; i++)
    {
        int n;
        cin >> n;
        add(head2, n);
    }

    Node *merge = Merge(head1, head2);
    cout << endl;
    print(merge);

    return 0;
}
