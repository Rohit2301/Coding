#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    for (int i = 0; i < 7; i++)
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
    vector<int> res;
    int cnt1 = 0, cnt2 = 0;
    int cand1 = 0, cand2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cand1 == nums[i])
        {
            cnt1++;
        }
        else if (cand2 == nums[i])
        {
            cnt2++;
        }
        else if (cnt2 == 0)
        {
            cand2 = nums[i];
            cnt1++;
        }
        else if (cnt1 == 0)
        {
            cand1 = nums[i];
            cnt2++;
        }

        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == cand1)
        {
            ct1++;
        }
        else if (nums[i] == cand2)
        {
            ct2++;
        }
    }

    if (ct1 > (nums.size() / 3))
    {
        res.push_back(cand1);
    }
    if (ct2 > (nums.size() / 3))
    {
        res.push_back(cand2);
    }

    for (auto &x : res)
    {
        cout << x << " ";
    }

    return 0;
}