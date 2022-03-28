#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    unordered_map<char, int> freq;
    int st = 0;
    int mac = 0;
    for (int r = 0; r < str.length(); r++)
    {
        freq[str[r]]++;
        if (freq.size() > 2)
        {
            while (freq.size() > 2)
            {
                freq[str[st]]--;
                if (freq[str[st]] == 0)
                {
                    freq.erase(str[st]);
                }

                st++;
            }
        }

        mac = max(mac, r - st + 1);
    }
    cout << "maximum " << mac;

    return 0;
}