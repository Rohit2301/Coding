#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<vector<int>> matrix(3, vector<int>(3));
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target = 3;
    bool resu = false;

    int start = 0;
    int end = m * n - 1;
    cout << "while loop";
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == matrix[mid / m][mid % m])
        {
            resu = true;
            break;
        }
        else if (target > matrix[mid / m][mid % m])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return 0;
}

