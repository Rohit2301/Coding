#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1;
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin >> x;
        nums1.push_back(x);
    }

    vector<int> nums2;
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin >> x;
        nums2.push_back(x);
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n1 = (int)nums1.size(), n2 = (int)nums2.size();
    int itr1 = 0, itr2 = 0;
    vector<int> res;
    while (itr1 < n1 && itr2 < n2)
    {
        if (nums1[itr1] == nums2[itr2])
        {
            res.push_back(nums1[itr1]);
            itr1++;
            itr2++;
        }
        else if (nums1[itr1] > nums2[itr2])
        {
            itr2++;
        }
        else
        {
            itr1++;
        }
        while (itr1 > 0 && itr1 < n1 && nums1[itr1] == nums1[itr1 - 1])
            itr1++;
        while (itr2 > 0 && itr2 < n2 && nums2[itr2] == nums2[itr2 - 1])
            itr2++;
    }

    return 0;
}