#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> comb(int n, int i)
{
    if (i > n)
    {
        vector<vector<int>> fnd = {{}};
        return fnd;
    }
    vector<vector<int>> fndY;
    vector<vector<int>> fndN;
    vector<vector<int>> ans;

    fndY = comb(n, i + 1);
    for (int j = 0; j < fndY.size(); j++)
    {
        fndY[j].push_back(i);
        ans.push_back(fndY[j]);
    }
    fndN = comb(n, i + 1);
    for (int j = 0; j < fndN.size(); j++)
    {
        ans.push_back(fndN[j]);
    }

    return ans;
}

int main()
{
    vector<vector<int>> ans;
    ans = comb(3, 1);
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