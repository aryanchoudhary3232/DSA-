#include <bits/stdc++.h>
using namespace std;

// approach 1
// class Solution
// {
// public:
//     bool searchMatrix(vector<vector<int>> &matrix, int target)
//     {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int> arr(m * n);
//         int k = 0;
//         for (auto i : matrix)
//         {
//             for (auto j : i)
//             {
//                 arr[k++] = j;
//             }
//         }

//         int low = 0, high = m * n - 1;
//         while (low <= high)
//         {
//             int mid = (low + high) / 2;
//             if (arr[mid] == target)
//                 return true;

//             if (arr[mid] < target)
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }

//         return false;
//     }
// };

// int main()
// {
//     Solution s;
//     vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
//     int target = 13;

//     cout<<s.searchMatrix(matrix, target);
//     return 0;
// }

//approach 2
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m * n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid/n;
            int col = mid%n;
            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;

    cout<<s.searchMatrix(matrix, target);
    return 0;
}