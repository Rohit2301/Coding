#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int target = 3;
    bool resu = false;

    int start = 0;
    int end = m - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (target >= matrix[mid][0] && target < matrix[mid + 1][0])
        {
            break;
        }
        else if (target < matrix[mid][0])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << mid;
    int rstrt = 0, rend = n - 1;
    while (rstrt <= rend)
    {
        int rmid = rstrt + (rend - rstrt) / 2;
        if (target > matrix[mid][rmid])
        {
            rstrt = rmid + 1;
        }
        else if (target < matrix[mid][rmid])
        {
            rend = rmid - 1;
        }
        else if (target == matrix[mid][rmid])
        {
            resu = true;
            break;
        }
    }

    cout << "\nresult " << resu;

    return 0;
}