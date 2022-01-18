#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> nums(6);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int n = nums.size();
    int target = 2;
    int start = 0, end = n - 1;

    vector<int> ind(2, -1);
    int mid = 0;
    //start index
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            ind[0] = mid;
            end = mid - 1;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    start = 0, end = n - 1;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            ind[1] = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "\nindex are : " << ind[0] << " " << ind[1];

    return 0;
}