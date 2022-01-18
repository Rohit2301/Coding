#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> houses(10);
    for (int i = 0; i < houses.size(); i++)
    {

        cin >> houses[i];
    }
    vector<int> heaters(10);
    for (int i = 0; i < heaters.size(); i++)
    {
        cin >> heaters[i];
    }
    sort(heaters.begin(), heaters.end());
    sort(houses.begin(), houses.end());
    for (int i = 0; i < houses.size(); i++)
    {
        cout << houses[i] << " ";
    }
    for (int i = 0; i < heaters.size(); i++)
    {
        cout << heaters[i] << " ";
    }

    int radi = 0;
    int closest = 0;

    for (int i = 0; i < houses.size();)
    {
        if (closest < heaters.size() - 1)
        {
            int diff1 = std::abs(houses[i] - heaters[closest]);
            int diff2 = std::abs(houses[i] - heaters[closest + 1]);

            if (diff1 <= diff2)
            {
                i++;
                radi = max(radi, diff1);
            }
            else
            {
                closest++;
            }
        }
        else
        {
            int diff1 = std::abs(houses[i] - heaters[closest]);
            i++;
            radi = max(radi, diff1);
        }
    }
    cout << "\nradius is :" << radi;

    return 0;
}
