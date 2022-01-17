#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    vector<int> arr;
    for (int i = 0; i < 5; i++)
    {
        int c;
        cin >> c;
        arr.push_back(c);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int chunk = 0;
    vector<int> left_max(arr.size());
    left_max[0] = arr[0];
    cout << left_max[0] << " ";
    for (int i = 1; i < arr.size(); i++)
    {
        left_max[i] = max(left_max[i - 1], arr[i]);
        cout << left_max[i] << " ";
    }
    cout << endl;
    vector<int> right_min(arr.size() + 1, 0);
    int infin = std::numeric_limits<int>::max();

    right_min[arr.size()] = infin;
    cout << right_min[arr.size()] << " ";
    right_min[arr.size() - 1] = arr[arr.size() - 1];
    cout << right_min[arr.size() - 1] << " ";
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        right_min[i] = min(right_min[i + 1], arr[i]);
        cout << right_min[i] << " ";
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (left_max[i] <= right_min[i + 1])
        {
            chunk++;
        }
    }

    cout << "\nchunks :" << chunk;

    return 0;
}