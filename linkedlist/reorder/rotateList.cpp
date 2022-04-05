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

Node *rotateList(Node *head, int k)
{

    if (!head || !head->next)
        return head;

    Node *nHead = NULL;
    int cnt=0;
    Node *nTail = head;
    Node *tail = head;
    Node *curr = head;
    while (k > 0)
    {
        tail = tail->next;
        cnt++;
        if (tail == NULL)
        {
            tail = curr;
            k = k%cnt;
            
        }

        k--;
    }
    while (tail->next)
    {
        tail = tail->next;
        nTail = nTail->next;
    }

    tail->next = curr;
    nHead = nTail->next;
    nTail->next = NULL;

    return nHead;
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
