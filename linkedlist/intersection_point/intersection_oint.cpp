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

Node* intersectionPt(Node* head1, Node* head2)
{
    0
   
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
