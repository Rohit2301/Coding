#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> height;
    for (int i = 0; i < 9; i++)
    {
        int c;
        cin >> c;
        height.push_back(c);
    }

    for (int i = 0; i < height.size(); i++)
    {
        cout << height[i] << " ";
    }
    cout << endl;
    int maxar = 0;
    int start = 0, end = height.size() - 1;

    while (start < end)
    {
        int wth = end - start;
        maxar = max(maxar, wth * min(height[start], height[end]));
        if (height[start] > height[end])
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    cout << maxar;

    return 0;
}