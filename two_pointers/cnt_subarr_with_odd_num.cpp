#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums(5);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int cnt = 0;
    int oddb = 0;
    int odds = 0;
    int itb = 0;
    int its = 0;
    int str = 0;

    if (k == 1)
    {
        while (true)
        {
            int f1 = 0;
            int f3 = 0;
            while (itb < nums.size())
            {
                f1 = 1;
                if (oddb == 1 && nums[itb] % 2 != 0)
                {
                    itb--;
                    break;
                }
                else if (nums[itb] % 2 != 0)
                {
                    oddb++;
                    itb++;
                }
                else
                {
                    itb++;
                }
            }
            while (str <= itb)
            {
                f3 = 1;
                if (itb == nums.size())
                {
                    itb--;
                    cnt += itb - str + 1;
                    f3 = 0;
                    break;
                }

                cnt += itb - str + 1;
                cout << str << itb << " ";
                if (nums[str] % 2 != 0)
                {
                    oddb--;
                    if (itb == 3)
                    {
                        cout << oddb;
                    }

                    itb++;
                    str++;
                    break;
                }
                str++;
            }
            if (f1 == 0 && f3 == 0)
            {
                break;
            }
        }
    }
    else
    {
        while (true)
        {
            int f1 = 0;
            int f2 = 0;
            int f3 = 0;

            while (itb < nums.size())
            {
                f1 = 1;
                if (nums[itb] % 2 != 0)
                {
                    oddb++;
                    itb++;
                }
                else
                {
                    itb++;
                }

                if (oddb == k + 1)
                {
                    oddb--;
                    itb--;
                    break;
                }
            }
            while (its < itb)
            {
                f2 = 1;
                if (nums[its] % 2 != 0)
                {
                    odds++;
                    its++;
                }
                else
                {
                    its++;
                }

                if (odds == k)
                {
                    odds--;
                    its--;
                    break;
                }
            }
            while (str < its)
            {
                f3 = 1;
                cnt += itb - its;
                if (nums[str] % 2 != 0)
                {
                    oddb--;
                    odds--;
                }
                str++;
                if (oddb < k || odds < k - 1)
                {
                    break;
                }
            }
            if (f1 == 0 && f2 == 0 && f3 == 0)
            {
                break;
            }
        }
    }

    cout << endl
         << cnt;

    return 0;
}