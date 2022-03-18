#include <bits/stdc++.h>
using namespace std;

int minSumLen(int s, vector<int> &nums)
{
    int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
    while (r < n)
    {
        sum += nums[r++];
        while (sum >= s)
        {
            len = min(len, r - l);
            sum -= nums[l++];
        }
    }
    return len == INT_MAX ? 0 : len;
}

int main()
{
    // int target;
    // cin >> target;
    vector<int> nums;
    for (int i = 0; i < 8; i++)
    {
        int c;
        cin >> c;
        nums.push_back(c);
    }
    int ans = minSumLen(11, nums);
    cout << endl
         << ans;

    return 0;
}