#include <bits/stdc++.h>
using namespace std;

int main()
{

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
    }

    return 0;
}
