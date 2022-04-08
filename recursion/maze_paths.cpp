#include <bits/stdc++.h>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> hpath;
    vector<string> vpath;

    if (sc < dc)
    {
        hpath = getMazePaths(sr, sc + 1, dr, dc); // h
    }

    if (sr < dr)
    {
        vpath = getMazePaths(sr + 1, sc, dr, dc); // v
    }
    vector<string> paths;

    for (string i : hpath)
    {
        paths.push_back("h" + i);
    }
    for (string i : vpath)
    {
        paths.push_back("v" + i);
    }

    return paths;
}

void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = getMazePaths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}