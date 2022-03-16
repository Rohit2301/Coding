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

Node *removeEnd(Node *head, int n)
{
    Node *fast = new Node();
    Node *slow = new Node();
    fast = head;
    slow->next = head;
    if (!head)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (!fast)
    {
        slow->next = slow->next->next;
        return slow->next;
    }

    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;

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

    Node *head1 = removeEnd(head, 2);
    cout << endl;
    print(head1);

    return 0;
}
