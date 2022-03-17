#include <bits/stdc++.h>
using namespace std;

string removeaDup(string s)
{
    map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    map<char, bool> appeared;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]--;
        if (!appeared[s[i]])
        {
            while (!st.empty() && (st.top() > s[i]) && (freq[st.top()] > 0))
            {
                appeared[st.top()] = false;
                st.pop();
            }
            st.push(s[i]);
            appeared[s[i]] = true;
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}