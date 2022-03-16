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
Node *seggMid(Node *head)
{
    if (!head && !head->next)
    {
        return head;
    }
    Node *tail = NULL;
    Node *cur = head;
    while (head->next)
    {
        head = head->next;
    }
    tail = head;

    Node *small = new Node();

    Node *large = new Node();
    Node *ldef = new Node();
    ldef = large;
    while (cur)
    {
        if (cur->data <= tail->data)
        {
            small->next = cur;
            small = small->next;
        }
        else
        {
            large->next = cur;
            large = large->next;
        }
        cur = cur->next;
    }
    small->next = ldef->next;
    large->next = NULL;

    return small;
}

Node *quick_sort(Node *head)
{
    Node *dummy = new Node();
    dummy->next = head;

    return dummy->next;
}

int main()
{
    Node *head = new Node();
    for (int i = 0; i < 1; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    Node *merge = quick_sort(head->next);
    cout << endl;
    print(merge);

    return 0;
}
