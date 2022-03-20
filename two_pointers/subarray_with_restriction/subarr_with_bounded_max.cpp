#include <bits/stdc++.h>
using namespace std;

int boundedArr(vector<int> &nums, int mini, int maxum)
{
    int l = 0, r = 0;
    int cnt = 0;
    int prevc = 0;
    while (r < nums.size())
    {
        if (mini <= nums[r] && nums[r] <= maxum)
        {
            prevc = r - l + 1;
            cnt += prevc;
        }
        else if (mini > nums[r])
        {
            cnt += prevc;
        }
        else
        {
            prevc = 0;
            l = r + 1;
        }
        r++;
    }
    return cnt;
}

int main()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        int c;
        cin >> c;
        nums.push_back(c);
    }
    cout << endl
         << boundedArr(nums, 17, 33);

    return 0;
}