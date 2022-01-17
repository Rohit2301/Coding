#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> arr(7);
    int k = 7;
    int x = 3;
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    vector<int> resu(k);
    int n = arr.size();
    int mid = 0;

    if (x <= arr[0])
    {
        for (int i = 0; i < k; i++)
        {
            resu[i] = arr[i];
        }
    }
    else if (x >= arr[n - 1])
    {
        for (int i = n - 1; i >= 0; i--)
        {
            resu[i] = arr[i];
        }
    }
    else
    {
        resu.resize(0);
        int start = 0, end = n - 1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (arr[mid] == x)
            {
                break;
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        resu.push_back(arr[mid]);
        cout << " mid : " << mid << endl;
        int left = mid - 1, right = mid + 1;
        for (int i = 1; i < k; i++)
        {
            if ((right <= n - 1 && left >= 0) && (arr[mid] - arr[left]) > (arr[right] - arr[mid]))
            {
                resu.push_back(arr[right]);
                right++;
            }
            else if (left >= 0)
            {
                resu.insert(resu.begin(), arr[left]);
                left--;
            }
            else
            {
                resu.push_back(arr[right]);
                right++;
            }
        }
    }
    cout << "result : ";
    for (auto x : resu)
    {
        cout << x << " ";
    }

    return 0;
}