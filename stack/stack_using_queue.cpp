#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        for (int i = 1; i < q.size(); i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        q.pop();
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{

    return 0;
}