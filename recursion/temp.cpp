#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> ans = {{}};

    for (int i = 0; i < ans.size(); i++)
    {
        ans[i].push_back(5);
    }
    for (vector<int> i : ans)
    {
        for (int num : i)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}