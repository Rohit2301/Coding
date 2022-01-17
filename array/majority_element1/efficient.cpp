#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    for (int i = 0; i < 3; i++)
    {
        int c;
        cin >> c;
        nums.push_back(c);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int cnt = 0;
    int majo = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            majo = nums[i];
            cnt++;
        }
        else if (majo == nums[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    cout << majo << "  " << nums[7];
    return 0;
}