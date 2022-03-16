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

Node *merget(Node *head1, Node *head2)
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

Node *mergeSort(vector<Node *> &lists, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    if (l == r)
    {
        return lists[l];
    }
    int mid = (l + r) / 2;
    Node *l1 = mergeSort(lists, l, mid);
    Node *l2 = mergeSort(lists, mid + 1, r);

    return merget(l1, l2);
}
Node *mergek(vector<Node *> &lists)
{
    Node *head = mergeSort(lists, 0, lists.size() - 1);
    return head;
}
int main()
{
    vector<Node *> lists(3);
    for (int i = 0; i < lists.size(); i++)
    {
        Node *head = new Node();
        for (int i = 0; i < 3; i++)
        {
            int n;
            cin >> n;
            add(head, n);
        }
        lists[i] = head->next;
    }

    Node *merge = mergek(lists);
    cout << endl;
    print(merge);

    return 0;
}
