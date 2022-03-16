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

Node *delZero(Node **head)
{
    Node *cur = *head;
    Node *prev = *head;
    int sum = 0;
    unordered_map<int, Node *> freq;
    freq[0] = *head;
    while (cur)
    {
        sum += cur->data;
        if (sum == 0 && freq.find(0) != freq.end())
        {
            *head = freq[sum];
            (*head)->next = cur->next;
        }
        else if (freq.find(sum) == freq.end())
        {
            freq[sum] = cur;
        }
        else
        {
            prev = freq[sum];
            prev->next = cur->next;
        }
        cur = cur->next;
    }

    return *head;
}

int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;

    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    Node *head1 = new Node();
    head1 = delZero(&head);

    print(head1);

    return 0;
}