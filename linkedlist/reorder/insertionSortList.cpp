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

Node *insertionSortList(Node *head)
{
    Node *curr = head;
    Node *prev = new Node();
    prev->next = head;

    while (curr && curr->next)
    {
        if (curr->next->data >= curr->data)
        {
            curr = curr->next;
        }
        else
        {
            Node *temp = prev;
            while (temp->next->data < curr->next->data)
            {
                temp = temp->next;
            }
            Node *temp2 = temp->next;
            Node *temp3 = curr->next->next;
            temp->next = curr->next;
            curr->next->next = temp2;
            curr->next = temp3;
        }
    }
    return prev->next;
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
