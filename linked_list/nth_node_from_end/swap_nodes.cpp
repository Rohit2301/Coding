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

Node *swapFn(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;
    Node *first = new Node();
    Node *second = new Node();

    for (int i = 0; i < n - 1; i++)
    {
        fast = fast->next;
    }
    first = fast;
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    second = slow;

    swap(first->data, second->data);

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

    Node *head1 = swapFn(head, 2);
    cout << endl;
    print(head1);

    return 0;
}
