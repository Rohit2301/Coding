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

Node *delDup(Node *head)
{
    Node *temp = new Node();
    Node *org = new Node();
    org = head;
    while (head != NULL)
    {
        while (head->next != NULL && head->next->data == head->data)
        {
            temp = head->next;
            head->next = temp->next;
            delete (temp);
        }

        head = head->next;
    }

    return org;
}

int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    add(head, 1);
    add(head, 2);

    Node *head1 = new Node();
    head1 = delDup(head);

    print(head1);

    return 0;
}