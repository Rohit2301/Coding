#include <bits/stdc++.h>
using namespace std;

int checkParen(string s)
{
    stack<int> st;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else
            {
                st.push('{');
                cnt++;
            }
        }
    }
    while (!st.empty())
    {
        st.pop();
        if (!st.empty())
        {
            st.pop();
            cnt++;
        }
        else
        {
            return -1;
        }
    }

    return cnt;
}

int main()
{

    string s;
    cin >> s;
    cout << checkParen(s);

    return 0;
}
