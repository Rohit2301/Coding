#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;

    if (nums.size() < 4)
        return ans;

    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    int r = nums.size() - 1;
    int sumReq = 0;
    int sumHas = 0;
    while (i < nums.size() - 3)
    {
        while (j < nums.size() - 2)
        {
            j = i + 1;

            int l = j + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                sumReq = target - (nums[i] + nums[j]);
                sumHas = nums[l] + nums[r];

                if (sumHas == sumReq)
                {
                    vector<int> add;
                    add.push_back(nums[i]);
                    add.push_back(nums[j]);
                    add.push_back(nums[l]);
                    add.push_back(nums[r]);
                    ans.push_back(add);
                    do
                    {
                        l++;
                        r--;
                    } while ((nums[l] == nums[l + 1]) && (nums[r] == nums[r - 1]) && (l < r));
                }
                else if (sumHas > sumReq)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            j++;
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> nums;
    for (int i = 0; i < 4; i++)
    {
        int c;
        cin >> c;
        nums.push_back(c);
    }
    vector<vector<int>> ans = fourSum(nums, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}