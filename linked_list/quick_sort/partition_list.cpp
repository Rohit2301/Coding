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

Node *partition(Node *head, int x)
{

    if (!head)
        return NULL;
    Node *dummy = new Node();
    dummy->next = head;
    Node *prev = new Node();
    prev->next = head;
    int f = 0;
    while (prev->next->data < x)
    {
        f = 1;
        prev = prev->next;
        if (!prev->next)
        {
            return dummy->next;
        }
    }
    Node *cur = prev->next;
    while (cur->next)
    {
        if (cur->next->data < x)
        {
            Node *temp = new Node();
            temp = cur->next;
            cur->next = cur->next->next;
            Node *temp2 = prev->next;
            prev->next = temp;
            temp->next = temp2;
            if (!f)
            {
                f = 1;
                dummy->next = prev->next;
            }
            prev = prev->next;
        }
        else
        {
            cur = cur->next;
        }
    }

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

    Node *merge = partition(head->next, 2);
    cout << endl;
    print(merge);

    return 0;
}
