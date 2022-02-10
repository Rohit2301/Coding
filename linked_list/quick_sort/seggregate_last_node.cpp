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
Node *middleNode(Node *head)
{

    Node *fast = new Node();
    Node *slow = new Node();
    fast = head->next;
    slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
vector<Node *> segg(Node *head)
{
    if (!head && !head->next)
    {
        return {head, head, head, head};
    }
    Node *cur = head;
    Node *mid = middleNode(head);

    Node *small = new Node();
    Node *large = new Node();
    Node *ldef = new Node();
    Node *sdef = new Node();
    ldef = large;
    sdef = small;

    while (cur)
    {
        if (cur->data <= mid->data)
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
    small->next = NULL;
    large->next = NULL;

    vector<Node *> list{sdef, small, mid, ldef};

    return list;
}

Node *quickSort(Node *head, Node *mid, Node *ldef)
{

    if (!head && !head->next)
    {
        return head;
    }
    vector<Node *> list = segg(head);
    Node *sdef = list[0];
    Node *small = list[1];
    Node *mid = list[2];
    Node *ldef = list[3];

    quickSort(sdef, mid, ldef);
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

    // Node *merge = quickSort(head->next);
    cout << endl;
    // print(merge);

    return 0;
}
