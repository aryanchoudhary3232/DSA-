#include <bits/stdc++.h>
using namespace std;

// brute force
//  class Solution
//  {
//  public:
//      vector<pair<int, int>> zeroIndex;

//     void setZeroes(vector<vector<int>> &matrix)
//     {
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[0].size(); j++)
//             {
//                 if (matrix[i][j] == 0)
//                 {
//                     zeroIndex.push_back({i, j});
//                 }
//             }
//         }

//         for (auto idx : zeroIndex)
//         {
//             int row = idx.first;
//             int col = idx.second;

//             for (int j = 0; j < matrix[0].size(); j++)
//             {
//                 matrix[row][j] = 0;
//             }
//             for (int i = 0; i < matrix.size(); i++)
//             {
//                 matrix[i][col] = 0;
//             }
//         }
//     }
// };

// int main()
// {
//     vector<vector<int>> mat = {
//         {0, 1, 2, 0},
//         {3, 4, 5, 2},
//         {1, 3, 1, 5}};

//     Solution s;
//     s.setZeroes(mat);

//     for (auto i : mat)
//     {
//         for (auto j : i)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// optimal approach

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int firstRowZero = 0;
        int firstColZero = 0;

        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
            {
                firstRowZero = 1;
                break;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                firstColZero = 1;
                break;
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowZero)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (firstColZero)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};

    Solution s;
    s.setZeroes(mat);

    for (auto i : mat)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
