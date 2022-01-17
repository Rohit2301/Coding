#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    for (int i = 0; i < 7; i++)
    {
        int c;
        cin >> c;
        nums.push_back(c);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;
        if (i != 0 && nums[i] != nums[i - 1])
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    cnt++;
                }
            }
        }
        else if (i == 0)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    cnt++;
                }
            }
        }

        if (cnt > (nums.size()) / 2)
        {
            cout << nums[i];
            break;
        }
    }

    return 0;
}