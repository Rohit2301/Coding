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

int maxPalin(Node *head)
{
    int cnt = 0;
    stack<int> st;
    Node *def = head;
    int n = 0;
    int mac = 0;
    Node *slow = def;
    while (slow)
    {
        n++;
        st.push(slow->data);
        slow = slow->next;
    }
    for (int i = 0; i < n; i++)
    {

        while (st.size() > 0)
        {
            if (head->data == st.top())
            {
                st.pop();
                cnt++;
                head = head->next;
                cout << cnt;
            }
            else
            {
                cnt = 0;
                head = def;
                st.pop();
            }
            cout << endl;
        }
        mac = max(cnt, mac);
        def = def->next;
        slow = def;
        while (slow)
        {
            st.push(slow->data);
            slow = slow->next;
        }
    }

    return mac;
}

int main()
{
    Node *head = new Node(13);

    for (int i = 0; i < 6; i++)
    {
        int n;
        cin >> n;
        add(head, n);
    }

    cout << "\nmaximum is " << maxPalin(head);

    return 0;
}
