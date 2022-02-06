#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> nums(6);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int original;
    cin >> original;

    for (int i = 0; i < nums.size();)
    {
        if (original == nums[i])
        {
            cout << original << " " << i << "    ";
            original = original * 2;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    cout << "\nresult is  " << original;

    return 0;
}