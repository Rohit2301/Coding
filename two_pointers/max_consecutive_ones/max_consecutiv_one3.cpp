#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums(11);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;

    int str = 0;
    int mac = 0;
    int zero = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 0)
        {
            zero++;
        }

        while (zero >= k + 1)
        {
            if (nums[str] == 0)
            {
                zero--;
                str++;
            }
            else
            {
                str++;
            }
        }

        cout << str << " ";
        mac = max(mac, j - str + 1);
    }
    cout << endl
         << mac;

    return 0;
}