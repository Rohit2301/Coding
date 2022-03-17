#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1(3);
    vector<int> nums2(4);

    vector<int> nums1, nums2;
    cout << "nums1" << endl;
    for (int i = 0; i < 3; i++)
    {
        int c;
        cin >> c;
        nums1.push_back(c);
    }
    cout << "nums2" << endl;
    for (int i = 0; i < 4; i++)
    {
        int c;
        cin >> c;
        nums2.push_back(c);
    }
    int k = 0;
    int ind = 0;
    vector<int> resu;
    map<int, int> freq;
    stack<int> st;
    for (int i = 0; i < nums2.size(); i++)
    {
        while (!st.empty() && st.top() < nums2[i])
        {
            freq[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    for (int j = 0; j < nums1.size(); j++)
    {
        if (freq.find(nums1[j]) != freq.end())
        {
            resu.push_back(freq[nums1[j]]);
        }
        else
        {
            resu.push_back(-1);
        }
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
