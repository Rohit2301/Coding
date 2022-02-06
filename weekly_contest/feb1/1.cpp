#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums(4);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    vector<int> res(nums.size());
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            even.push_back(nums[i]);
        }
        else
        {
            odd.push_back(nums[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());
    // for (int i = 0; i < even.size(); i++)
    // {
    //     cout << even[i];
    // }
    // cout << endl;
    // for (int i = 0; i < odd.size(); i++)
    // {
    //     cout << odd[i];
    // }

    for (int i = 0; i < res.size(); i++)
    {
        cout << i / 2 << " ";
        if (i % 2 == 0)
        {
            res[i] = (even[i / 2]);
        }
        else
        {
            res[i] = (odd[i / 2]);
        }
    }
    cout << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }

    return 0;
}