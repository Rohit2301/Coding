#include <bits/stdc++.h>
using namespace std;

string checkParen(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        { // for open parentheses push into stack
            st.push(i);
        }
        else if (s[i] == ')')
        { // for closing parentheses
            // if no matching previous open parentheses found, we need to remove the index of that open parentheses from "s" so for now we are marking it with special character '#'
            if (st.empty())
            {
                s[i] = '#';
            }
            else
            {
                // if matching open parentheses found remove that from the stack
                st.pop();
            }
        }
    }
    cout << s[st.top()] << st.top() << endl;
    // if stack is not empty, that means it contains open parentheses indexes which don't have any matching closing parentheses
    while (!st.empty())
    {
        
        s[st.top()] = '#';
        st.pop();
    }
    cout << s << endl;
    string ans = "";
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != '#')
        { // append not marked character to the end of "ans"
            ans.push_back(s[i]);
        }
    }

    return ans;
}

int main()
{

    string s;
    cin >> s;
    cout << checkParen(s);

    return 0;
}
