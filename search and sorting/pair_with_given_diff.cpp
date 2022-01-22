#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums(5);

    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int k = 0;
    int count = 0;

    if (k)
    {
        set<int> uniq;
        for (int i = 0; i < nums.size(); i++)
        {
            uniq.insert(nums[i]);
        }
        for (auto itr : uniq)
        {
            cout << itr << " ";
        }
        cout << endl;

        auto itr1 = uniq.begin();
        auto itr2 = uniq.begin();

        while (itr1 != uniq.end() && itr2 != uniq.end())
        {
            int diff = std::abs((*itr1) - (*itr2));
            cout << diff << " ";
            if (k == diff)
            {
                count++;
                itr1++;
                itr2++;
            }
            else if (k > diff)
            {
                itr2++;
            }
            else
            {
                itr1++;
            }
        }
    }
    else
    {
        unordered_map<int, int> same;
        for (int i = 0; i < nums.size(); i++)
        {
            if (same.find(nums[i]) == same.end())
            {
                same[nums[i]] = 1;
            }
            else
            {
                same[nums[i]]++;
            }
        }
        for (auto itr = same.begin(); itr != same.end(); itr++)
        {
            if (itr->second > 1)
            {
                count++;
            }
        }
    }
    cout << "\ncount " << count;

    return 0;
}