#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> comb(int n, int i)
// {
//     if (i > n)
//     {
//         vector<vector<int>> fnd = {{}};
//         return fnd;
//     }
//     vector<vector<int>> fndY;
//     vector<vector<int>> fndN;
//     vector<vector<int>> ans;

//     fndY = comb(n, i + 1);
//     for (int j = 0; j < fndY.size(); j++)
//     {
//         fndY[j].push_back(i);
//         ans.push_back(fndY[j]);
//     }
//     fndN = comb(n, i + 1);
//     for (int j = 0; j < fndN.size(); j++)
//     {
//         ans.push_back(fndN[j]);
//     }

//     return ans;
// }

vector<vector<int>> res;

void comb(vector<int> curr, int n, int k, int str)
{
    res.push_back(curr);
    for (int i = str; i < n + 1; i++)
    {
        curr.push_back(i);
        comb(curr, n, k, i + 1);
        curr.pop_back();
    }
}
void combine(int n, int k)
{
    vector<int> curr;
    comb(curr, n, k, 1);
    return;
}
int main()
{
    vector<vector<int>> ans;
    combine(3, 1);
    for (vector<int> i : res)
    {
        for (int num : i)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}