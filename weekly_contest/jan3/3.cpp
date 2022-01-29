#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;
int main()
{
    vector<int> nums;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    unordered_map<int, int> umap;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (umap.find(nums[i]) == umap.end())
        {
            umap[nums[i]] = 1;
        }
        else
        {
            umap[nums[i]]++;
        }
    }
    for (auto it = umap.begin(); it != umap.end(); it++)
    {

        cout << it->first << "  " << it->second << endl;
    }
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        if (it->second < 2 && umap.find(it->first - 1) == umap.end() && umap.find(it->first + 1) == umap.end())
        {
            res.push_back(it->first);
        }
    }
    cout << "\nresult arr" << endl;
    for (auto x : res)
    {
        cout << x << "  ";
    }

    return 0;
}