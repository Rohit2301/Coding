#include <bits\stdc++.h>
using namespace std;

void remove(int c, unordered_map<int, int> mapr)
{
    if (mapr[c] == 1)
    {
        mapr.erase(c);
    }
    else
    {
        mapr[c]--;
    }
}

int main()
{
    vector<int> nums(5);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;

    unordered_map<int, int> big;
    unordered_map<int, int> small;

    int cnt = 0;
    int is = -1;
    int ib = -1;
    int j = -1;

    if (k == 1)
    {
        while (true)
        {
            int f1 = 1;
            int f2 = 1;
            while (ib < nums.size() - 1)
            {
                f1 = 0;
                ib++;
                big[nums[ib]]++;
                if (big.size() == 2)
                {
                    remove(nums[ib], big);
                    ib--;
                    break;
                }
            }
            while (j < ib)
            {
                f2 = 0;
                if (big.size() == 1)
                {
                    cnt += ib - j;
                    cout << cnt << " ";
                }
                j++;
                remove(nums[j], big);
                if (big.size() < 1)
                {
                    break;
                }
            }
            if (f1 == 1 && f2 == 1)
            {
                break;
            }
        }
    }
    else
    {

        while (true)
        {

            int f1 = 1;
            int f2 = 1;
            int f3 = 1;

            while (ib < (nums.size() - 1))
            {
                cout << ib << " " << nums.size();
                ib++;
                cout << ib;
                f1 = 0;
                big[nums[ib]]++;
                if (big.size() == k + 1)
                {
                    remove(nums[ib], big);
                    ib--;
                    break;
                }
            }
            while (is < ib)
            {
                f2 = 0;
                is++;
                small[nums[is]]++;
                if (small.size() == k)
                {
                    remove(nums[is], small);
                    is--;
                    break;
                }
            }
            while (j < is)
            {
                f3 = 0;
                if (big.size() == k && small.size() == k - 1)
                {
                    cnt += ib - is;
                    cout << cnt << " ";
                }
                j++;
                remove(nums[j], small);
                remove(nums[j], big);
                if (big.size() < k || small.size() < k - 1)
                {
                    break;
                }
            }
            if (f1 == 1 && f2 == 1 && f3 == 1)
            {
                break;
            }
            cout << 1;
        }
    }

    cout << "\ncount is " << cnt;

    return 0;
}