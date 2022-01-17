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
    int zero = 1;
    vector<int> chun(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        //chunk started
        if (arr[i] != i)
        {
            chun[arr[i]]++;
            chun[i]--;
        }
        else if (zero && arr[i] == i)
        {
            chunk++;
            continue;
        }
        for (auto x : chun)
        {
            if (x != 0)
            {
                zero = 0;
                break;
            }
            zero = 1;
        }

        if (zero)
        {
            chunk++;
        }
        cout << i << " :" << chunk << " ";
    }
    cout << "\nchunks : " << chunk;

    return 0;
}