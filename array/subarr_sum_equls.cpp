#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums(3);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    int count = 0;
    int sum = 0;
    map<int, int> presum;
    presum[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (presum.find(sum - k) != presum.end())
        {
            count += presum[sum - k];
        }
        presum[sum]++;
    }

    cout << "\nans is " << count;

    return 0;
}