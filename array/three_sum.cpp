#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums(4);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> res;
    int left = 1, right = nums.size() - 1;

    if (nums.size() >= 3)
    {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }

            if (nums[i - 1] != nums[i])
            {
                left = i + 1;
                right = nums.size() - 1;
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum == -nums[i])
                    {
                        vector<int> indi(3);
                        indi[0] = nums[i];
                        indi[1] = nums[left];
                        indi[2] = nums[right];

                        res.push_back(indi);
                        do
                        {
                            left++;
                            right--;
                        } while (nums[left - 1] == nums[left] && nums[right + 1] == nums[right] && left < right);
                    }
                    else if (sum > -nums[i])
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}