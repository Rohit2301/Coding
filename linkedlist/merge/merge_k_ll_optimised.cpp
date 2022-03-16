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

struct compare
{
    bool operator()(const Node *l, const Node *r)
    {
        return l->val > r->val;
    }
};
Node *mergek(vector<int> &lists)
{
    priority_queue<Node *, vector<Node *>, compare> q;
    for (auto l : lists)
    {
        if (l)
            q.push(l);
    }
    if (q.empty())
        return NULL;

    Node *result = q.top();
    q.pop();
    if (result->next)
        q.push(result->next);
    Node *tail = result;
    while (!q.empty())
    {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if (tail->next)
            q.push(tail->next);
    }
    return result;
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
