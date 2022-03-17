#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int num = n;
    int ans = 0;
    map<int, int, greater<int>> no;
    while (num > 0)
    {
        no[num % 10]++;
        num = num / 10;
    }

    for (auto itr = no.begin(); itr != no.end();)
    {
        ans = ans * 10;
        ans += itr->first;
        itr->second--;
        if (itr->second == 0)
        {
            itr++;
        }
    }

    cout << n << " ans " << ans;

    return 0;
}
