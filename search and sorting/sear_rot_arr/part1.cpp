#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

using namespace std;

int main()
{
    vector<int> nums(7);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    int n = nums.size();
    int target = 3;
    int start = 0, end = nums.size() - 1;
    int mid = -1;
    int ind = -1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        cout << mid << "";
        if (target == nums[mid])
        {
            ind = mid;
            break;
        }
        else if (nums[end] < nums[mid] && !(nums[start] <= target && target < nums[mid]))
        {
            start = mid + 1;
        }
        else if (nums[start] > nums[mid] && !(nums[mid] < target && target <= nums[end]))
        {
            end = mid - 1;
        }

        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else if (target < nums[mid])
        {
            end = mid - 1;
        }
    }
    cout << "\nind " << ind;

    return 0;
}