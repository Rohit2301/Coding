#include <bits/stdc++.h>
using namespace std;

int checkParen(string s)
{
    stack<int> paren;
    for (int i = 0; i < s.length(); i++)
    {
        if (paren.empty() || (!paren.empty() && paren.top() == ')'))
        {
            paren.push(s[i]);
        }
        else if (!paren.empty())
        {
            if (paren.top() == s[i])
            {
                paren.push(s[i]);
            }
            else
            {
                paren.pop();
            }
        }
    }

    return paren.size();
}

int main()
{

    string s;
    cin >> s;
    cout << checkParen(s);

    return 0;
}
