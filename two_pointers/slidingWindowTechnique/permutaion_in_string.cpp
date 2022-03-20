#include <bits/stdc++.h>
using namespace std;

vector<int> checkPermu(string s1, string s2)
{
    vector<int> ans;
    map<char, int> freq;
    map<char, bool> exist;
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i]]++;
        exist[s1[i]] = true;
    }
    int l = 0, r = 0;
    while (r < s1.length())
    {
        if (exist[s2[r]])
        {
            if (freq[s2[r]] == 1)
            {
                freq.erase(s2[r]);
            }
            else
            {
                freq[s2[r]]--;
            }
        }
        r++;
    }
    r--;
    while (r < s2.length())
    {
        if (!freq.size())
        {
            ans.push_back(l);
        }
        if (exist[s2[l]])
        {
            freq[s2[l]]++;
            if (freq[s2[l]] == 0)
            {
                freq.erase(s2[l]);
            }
        }
        l++;
        r++;
        if (exist[s2[r]])
        {
            if (freq[s2[r]] == 1)
            {
                freq.erase(s2[r]);
            }
            else
            {
                freq[s2[r]]--;
            }
        }
        cout << "here";
    }

    return ans;
}

int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    vector<int> ans;
    ans = checkPermu(s1, s2);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }

    return 0;
}