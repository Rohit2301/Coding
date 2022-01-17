#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
    for (int i = 0; i < 4; i++)
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

    int n = nums.size();
    vector<int> left(n);
    left[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        left[i] = left[i - 1] * nums[i];
        cout << left[i] << " ";
    }
    vector<int> right(n);
    right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i];
        cout << right[i] << " ";
    }
    cout << endl;
    vector<int> ans(n);
    ans[0] = right[1];
    ans[n - 1] = left[n - 2];
    // cout << ans[0] << ans[n - 1];

    for (int i = 1; i < n - 1; i++)
    {
        ans[i] = left[i - 1] * right[i + 1];
        // cout << i << " ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}