#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;
int main()
{
    vector<int> nums;
    for (int i = 0; i < 6; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    unordered_map<int, int> umap;
    int pos = 0, neg = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            umap[pos] = nums[i];
            pos = pos + 2;
        }
        else
        {
            umap[neg] = nums[i];
            neg = neg + 2;
        }
    }
    for (auto it = umap.begin(); it != umap.end(); it++)
    {

        cout << it->first << "  " << it->second << endl;
    }
    int ind = 0;
    auto itr = umap.begin();
    while (ind < nums.size())
    {
        itr = umap.find(ind);
        nums[ind] = itr->second;
        ind++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}