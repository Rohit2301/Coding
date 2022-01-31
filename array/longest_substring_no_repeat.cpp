#include <bits\stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int str = 0;
    int mac = 0;
    vector<int> alpha(256, -1);

    for (int i = 0; i < s.length(); i++)
    {
        if (alpha[s[i]] < str)
        {
            alpha[s[i]] = i;
        }
        else
        {
            str = alpha[s[i]] + 1;
            alpha[s[i]] = i;
        }
        mac = max(mac, i - str + 1);
    }

    cout << "\n max length " << mac;

    return 0;
}