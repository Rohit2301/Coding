#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

using namespace std;

int main()
{
    vector<int> nums(19);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    int n = nums.size();
    int target = 2;
    int start = 0, end = nums.size() - 1;
    int mid = -1;
    int ind = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        cout << mid << " ";
        if (target == nums[mid])
        {
            ind = mid;
            break;
        }
        else if ((nums[start] == nums[mid]) && (nums[end] == nums[mid]))
        {
            ++start;
            --end;
        }
        else if (nums[end] >= nums[mid])
        {
            if (nums[mid] < target && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else if (nums[start] <= nums[mid])
        {
            if (nums[start] <= target && target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    cout << "\nind " << ind;

    return 0;
}