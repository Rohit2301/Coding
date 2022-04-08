#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> comb(int n, int k, int cnt, int i)
{
    if (cnt == k)
    {
        vector<vector<int>> fnd = {{}};
        return fnd;
    }
    else if (i > n)
    {
        return {{-1}};
    }
    vector<vector<int>> fndY;
    vector<vector<int>> fndN;
    vector<vector<int>> ans;

    fndY = comb(n, k, cnt + 1, i + 1);
    if (fndY[0][0] != -1)
    {
        for (int j = 0; j < fndY.size(); j++)
        {
            fndY[j].push_back(i);
            ans.push_back(fndY[j]);
        }
    }
    fndN = comb(n, k, cnt, i + 1);
    if (fndN[0][0] != -1)
    {
        for (int j = 0; j < fndN.size(); j++)
        {
            ans.push_back(fndN[j]);
        }
    }
    
    if (ans.size() == 0)
        return {{-1}};
    return ans;
}

int main()
{
    vector<vector<int>> ans;
    ans = comb(4, 2, 0, 1);
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