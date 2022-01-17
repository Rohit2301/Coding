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
    vector<int> maxar(height.size(), 0);
    int result = 0;

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int bdth = j - i;
            int heit = min(height[i], height[j]);
            int area = bdth * heit;
            maxar[i] = max(maxar[i], area);
        }
        result = max(maxar[i], result);
    }

    cout << "\nresult is : " << result << endl;

    return 0;
}
