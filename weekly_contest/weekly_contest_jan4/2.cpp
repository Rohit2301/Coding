#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> nums(4);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    vector<int> res;
    vector<int> left;
    vector<int> right;
    int count = 0;
    int maxcount = 0;

    for (int ind = 0; ind <= nums.size(); ind++)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < ind)
            {
                left.push_back(nums[i]);
                if (left[i] == 0)
                {
                    count++;
                }
            }
            else if (i >= ind)
            {
                right.push_back(nums[i]);
                if (right[i - ind] == 1)
                {
                    count++;
                }
            }
        }
        if (count > maxcount)
        {
            maxcount = count;
            res.clear();
            res.push_back(ind);
            cout << ind << " " << count << "   ";
        }
        else if (count == maxcount)
        {
            res.push_back(ind);
            cout << ind << " " << count << "   ";
        }

        count = 0;
        right.clear();
        left.clear();
    }
    cout << "\nRes  ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }

    return 0;
}