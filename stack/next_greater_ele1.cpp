#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1(3);
    vector<int> nums2(4);

    for (int i = 0; i < nums1.size(); i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        cin >> nums2[i];
    }

    stack<int> s;
    unordered_map<int, int> m;
    for (int n : nums2)
    {
        while (s.size() && s.top() < n)
        {
            m[s.top()] = n;
            s.pop();
        }
        s.push(n);
    }
    vector<int> ans;
    for (int n : nums1)
    {
        ans.push_back(m.count(n) ? m[n] : -1);
    }
    for (int n : ans)
    {
        cout << n << " ";
    }

    return 0;
}
