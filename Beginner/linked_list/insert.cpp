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

void add(Node **head, int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->next = *head;
    *head = temp;
}

int main()
{
    Node *head = new Node();
    head->data = 4;
    head->next = NULL;
    add(&head, 5);
    add(&head, 6);
    add(&head, 7);
    print(head);

    return 0;
}