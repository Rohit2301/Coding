#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums(1);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    stack<pair<int, int>> s;
    vector<int> ans(nums.size(), -1);

    for (int i = 0; i < nums.size(); i++)
    {
        while (s.size() && s.top().second < nums[i])
        {
            ans[s.top().first] = nums[i];
            s.pop();
        }
        s.push({i, nums[i]});
    }
    int ind = 0;
    while (s.size())
    {
        while (ind < nums.size() && s.top().second >= nums[ind])
        {
            ind++;
        }

        if (ind == nums.size())
        {
            break;
        }

        ans[s.top().first] = nums[ind];
        s.pop();
    }
    for (int n : ans)
    {
        cout << n << " ";
    }

    return 0;
}
