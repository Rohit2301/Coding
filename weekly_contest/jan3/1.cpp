#include <bits/stdc++.h>

using namespace std;
int main()

{
    vector<int> nums;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    if (nums.size() < 3)
    {
        ans = 0;
    }
    else
    {
        int ans = nums.size() - 2;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[0] || nums[i] == nums[nums.size() - 1])
            {
                ans--;
            }
        }
    }

    cout << "\nminimum " << ans;

    return 0;
}