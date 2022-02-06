#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int res;
    int size = 0;
    int temp = abs(num);
    vector<int> resVec;
    while (temp > 0)
    {
        int digit = temp % 10;
        temp /= 10;
        resVec.push_back(digit);
    }
    reverse(resVec.begin(), resVec.end());

    if (num >= 0)
    {
        sort(resVec.begin(), resVec.end());
        if (resVec.size() > 1 && resVec[0] == 0)
        {
            int str = 0;
            while (!resVec[str])
            {
                str++;
            }
            swap(resVec[0], resVec[str]);
        }
        for (int i = 0; i < resVec.size(); i++)
        {
            cout << resVec[i];
        }

        int number = 0;

        for (int i = 0; i < resVec.size(); i++)
        {
            number *= 10;
            number += resVec[i];
        }
        res = number;
    }
    else
    {
        sort(resVec.begin(), resVec.end(), greater<int>());
        int number = 0;

        for (int i = 0; i < resVec.size(); i++)
        {
            number *= 10;
            number += resVec[i];
        }
        res = -number;
    }

    cout << endl
         << res;

    return 0;
}