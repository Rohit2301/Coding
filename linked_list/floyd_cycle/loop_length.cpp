#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;
};

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

bool hasCycle(Node *head)
{
    if (!head)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            break;
        }
    }
    if (!fast || !fast->next)
    {
        return NULL;
    }
    int len = 1;

    while (head != slow)
    {
        slow = slow->next;
        head = head->next;
        len++;
    }
    while (head != fast)
    {
        head = head->next;
        len++;
    }

    return len;
}

int main()
{

    return 0;
}