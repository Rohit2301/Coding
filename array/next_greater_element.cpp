#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> nums1, nums2;
    cout << "nums1" << endl;
    for (int i = 0; i < 3; i++)
    {
        int c;
        cin >> c;
        nums1.push_back(c);
    }
    cout << "nums2" << endl;
    for (int i = 0; i < 4; i++)
    {
        int c;
        cin >> c;
        nums2.push_back(c);
    }
    int k = 0;
    int ind = 0;
    vector<int> resu;
    for (int k = 0; k < nums1.size(); k++)
    {

        for (int j = 0; j < nums2.size(); ++j)
        {
            if (nums1[k] == nums2[j])
            {
                ind = j;
                break;
            }
        }
        for (int i = ind + 1; i < nums2.size(); ++i)
        {
            if (nums2[ind] < nums2[i] && ind != nums2.size() - 1)
            {
                resu.insert(resu.begin() + k, nums2[i]);
                break;
            }
            else
            {
                resu.insert(resu.begin() + k, -1);
            }
        }
        if (ind == nums2.size() - 1)
        {
            resu.insert(resu.begin() + k, -1);
        }
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << "";
    }
    cout << endl;
    for (int i = 0; i < nums2.size(); i++)
    {
        cout << nums2[i] << "";
    }
    cout << endl;
    resu.resize(nums1.size());
    for (int i = 0; i < resu.size(); i++)
    {
        cout << resu[i] << " ";
    }

    return 0;
}
