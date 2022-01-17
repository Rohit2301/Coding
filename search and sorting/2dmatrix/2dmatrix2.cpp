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
    int i = 0, j = 0;
    for ( ; i < n && j < m; i++, j++)
    {
        if (target <= matrix[i][j])
        {
            break;
        }
    }

    for (int k = i; k > 0; k--)
    {
        
    }
    

    return 0;
}