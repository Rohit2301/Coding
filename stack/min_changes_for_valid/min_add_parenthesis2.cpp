#include <bits/stdc++.h>
using namespace std;

int checkParen(string s)
{
    stack<int> paren;
    int r = 0;
    int curr = 0;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            if (!curr)
            {
                paren.push(s[i]);
                curr++;
                // cout << i << cnt << " ";
            }
            else
            {
                if (r > 0)
                {
                    paren.pop();
                    paren.pop();
                    curr--;
                    r--;
                }
                else
                {
                    paren.pop();
                    curr--;
                    cnt++;
                }
            }
        }
        else if (curr != 0 && s[i] == '(')
        {
            if (r > 0)
            {
                paren.pop();
                paren.pop();
                curr--;
                cnt++;
                r--;
            }
            else
            {
                paren.pop();
                curr--;
                cnt += 2;
            }
            paren.push(s[i]);
            r++;
        }
        else
        {
            paren.push(s[i]);
            r++;
            if (i == 10)
                cout << cnt << i << " ";
        }
    }
    if (curr > 0 && r > 0)
    {
        r--;
        cnt++;
        curr--;
    }
    else if (curr > 0)
    {
        cnt += 2;
    }

    cout << cnt;
    cnt += (2 * r);

    return cnt;
}

int main()
{

    string s;
    cin >> s;
    cout << endl
         << checkParen(s);

    return 0;
}
