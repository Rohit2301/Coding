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

Node *reversek(Node *head, int k)
{
    Node *dummy = new Node();
    Node *start = new Node();
    Node *then = new Node();
    Node *pre = new Node();
    dummy->next = head;
    pre->next = head;
    int count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }
    int n = count / k;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {

            start = pre->next;
            then = start->next;
            for (int j = 0; j < k - 1; j++)
            {
                start->next = then->next;
                then->next = pre->next;
                pre->next = then;
                then = start->next;
            }
            if (i == 0)
            {
                dummy->next = pre->next;
            }
            pre = start;
        }
        else
        {
            for (int z = 0; z < k; z++)
            {
                pre = pre->next;
            }
        }
    }

    return dummy->next;
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

    Node *head1 = reversek(head, 2);
    cout << endl;
    print(head1);

    return 0;
}
