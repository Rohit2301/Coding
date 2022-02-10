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

Node *mergeSort(Node *head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    Node *mid = middleNode(head);
    Node *rhead = mid->next;
    mid->next = NULL;

    Node *node1 = mergeSort(head);
    Node *node2 = mergeSort(rhead);
    Node *sorted = Merge(node1, node2);
    return sorted;
}

int main()
{
    Node *head = new Node(-1);
    for (int i = 0; i < 6; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    Node *merge = mergeSort(head->next);
    cout << endl;
    print(merge);

    return 0;
}
