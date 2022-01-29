#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

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
    int start = 0;
    int end = nums.size() - 1, mid = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid == 0 || mid == nums.size() - 1)
        {
            break;
        }

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            break;
        }
        else if (nums[mid] < nums[mid + 1])
        {
            start = mid + 1;
        }
        else if (nums[mid] < nums[mid - 1])
        {
            end = mid - 1;
        }
    }
    cout << "\nmid is " << mid;

    return 0;
}