#include <bits/stdc++.h>
using namespace std;

int prodLess(vector<int> &nums, int k)
{
    int l = 0, r = 0;
    int currProd = nums[0];
    int cnt = 0;
    while (r < nums.size())
    {
        while (currProd < k && r < nums.size())
        {
            cout << r << l << " " << currProd << "   ";
            cnt += r - l + 1;
            r++;
            if (r < nums.size())
            {
                currProd *= nums[r];
            }
        }
        cout << r << l << " ";
        while (l == r && currProd >= k && r < nums.size())
        {
            l++;
            r++;
            currProd = nums[l];
            cout << "here";
        }
        while (currProd >= k && l <= r && r < nums.size())
        {
            currProd = (currProd / nums[l]);
            l++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> nums;
    for (int i = 0; i < 3; i++)
    {
        int c;
        cin >> c;
        nums.push_back(c);
    }
    cout << endl
         << prodLess(nums, 0);

    return 0;
}