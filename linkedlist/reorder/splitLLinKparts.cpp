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

vector<Node *> splitListToParts(Node *head, int k)
{
    int cnt = 0;
    Node *curr = head;

    while (curr)
    {
        curr = curr->next;
        cnt++;
    }
    int lastGrup = 0, grpOfK = 0;
    lastGrup = cnt % k;
    grpOfK = cnt / k;
    vector<Node *> ans(k);
    Node *temp = head, *prev = new Node();
    prev->next = head;

    if (cnt <= k)
    {
        for (int i = 0; i < cnt; i++)
        {
            ans[i] = temp;
            prev = temp;
            temp = temp->next;
            prev->next = NULL;
        }
        for (int j = 0; j < k - cnt; j++)
        {
            ans[cnt + j] = NULL;
        }
        return ans;
    }
    for (int i = 0; i < k; i++)
    {
        Node* previ = new Node();
        ans[i] = temp;
        previ->next = temp;
        for (int j = 0; j < grpOfK; j++)
        {
            temp = temp->next;
            previ = previ->next;
        }
        if (lastGrup > 0)
        {
            previ = previ->next;
            temp = temp->next;
            lastGrup--;
        }
        previ->next = NULL;
    }
    return ans;
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





