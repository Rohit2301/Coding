#include <bits\stdc++.h>
using namespace std;

int main()
{
    vector<int> nums(6);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    int str = 0;
    int count = 0;
    int mac = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 1)
        {
            count++;
            mac = max(mac, count);
        }
        else
        {
            count = 0;
        }
    }
    cout << mac;

    return 0;
}