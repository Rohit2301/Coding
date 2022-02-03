#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int cnt = 0;
    int st = 0;
    unordered_map<char, int> freq;
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]] == 0)
        {
            freq[str[i]]++;
        }
        else if (freq[str[i]] == 1)
        {
            while (str[st] != str[i])
            {
                freq[str[st]]--;
                st++;
            }
            st++;
        }
        cnt += i - st + 1;
        cout << i - st + 1 << " ";
    }
    cout << endl
         << cnt;
    return 0;
}