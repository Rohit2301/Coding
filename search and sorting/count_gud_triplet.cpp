#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> arr(6);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int res = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c)
                {
                    res++;
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    cout << res;

    return 0;
}