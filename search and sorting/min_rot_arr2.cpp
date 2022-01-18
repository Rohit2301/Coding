#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    vector<int> nums;
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    int n = nums.size();
    int start = 0, end = n - 1;
    int mid = 0;
    int mini = std::numeric_limits<int>::max();
    if (nums[start] < nums[end])
    {
        mini = min(mini, nums[start]);
    }
    else if (n == 1)
    {
        mini = nums[0];
    }
    else
    {
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            cout << mid << " ";
            if (nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else if (nums[mid] < nums[start])
            {
                end = mid;
                start++;
            }
            else
            {
                end--;
            }
        }
        mini = nums[start];
    }

    cout << "\nminimum " << mini;

    return 0;
}