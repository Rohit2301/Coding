#include <bits\stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    vector<int> alpha(256, 0);
    vector<int> copy(256, 0);
    int len = s1.length();
    int str = 0;

    for (int j = 0; j < len; j++)
    {
        alpha[s1[j]]++;
    }

    for (int i = 0; i < s2.length(); i++)
    {

        if (alpha[s2[i]] > copy[s2[i]] && alpha[s2[i]] > 0)
        {
            copy[s2[i]]++;
            len--;
        }
        else
        {
            while (s2[str] != s2[i])
            {
                if (alpha[s2[str]] > 0)
                {
                    alpha[s2[i]]--;
                    len++;
                }

                str++;
            }
            str++;
        }

        if (len == 0)
        {
            cout << "true";
            break;
        }
    }

    return 0;
}