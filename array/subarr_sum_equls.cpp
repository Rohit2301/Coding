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
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            if (sum == k)
            {
                count++;
                cout << j << " " << sum << " " << count << "   ";
            }

            if (sum > k)
            {
                break;
            }
        }
        sum = 0;
    }

    cout << "\nans is " << count;

    return 0;
}