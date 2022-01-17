#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
    int max_curr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        max_curr = max(max_curr, arr[i]);
        if (max_curr == i)
        {
            chunk++;
        }
    }

    cout << "\nchunks : " << chunk;

    return 0;
}