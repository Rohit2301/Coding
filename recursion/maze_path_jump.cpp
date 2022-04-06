#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{

    if (sc == dc && sr == dr)
    {
        vector<string> res;
        res.push_back("");
        return res;
    }

    vector<string> path;

    for (int js = 1; js <= dc - sc; js++)
    {
        vector<string> hpath = getMazePaths(sr, sc + js, dr, dc);
        for (string i : hpath)
        {
            path.push_back("h" + to_string(js) + i);
        }
    }
    for (int js = 1; js <= dr - sr; js++)
    {
        vector<string> vpath = getMazePaths(sr + js, sc, dr, dc);
        for (string i : vpath)
        {
            path.push_back("v" + to_string(js) + i);
        }
    }
    for (int js = 1; js <= dc - sc && js <= dr - sc; js++)
    {
        vector<string> dpath = getMazePaths(sr + js, sc + js, dr, dc);
        for (string i : dpath)
        {
            path.push_back("d" + to_string(js) + i);
        }
    }
    return path;
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
    vector<string> ans = getMazePaths(1, 1, n, m);
    display(ans);

    return 0;
}