#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums(13);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    int str = 0;
    int mac = 0;
    int zero = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 0)
        {
            zero++;
        }

        if (zero == 2)
        {
            while (nums[str] != 0)
            {
                str++;
            }
            str++;
            zero--;
        }
        cout << str << " ";
        mac = max(mac, j - str + 1);
    }
    cout << endl
         << mac;

    return 0;
}