#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        int start = intervals[0][0], end = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> result;

        for (int i = 1; i < n; i++)
        {
            int startingTime = intervals[i][0];
            int endingTime = intervals[i][1];
            if (startingTime <= end)
            {
                end = max(end, endingTime);
            }
            else
            {
                result.push_back({start, end});
                start = startingTime;
                end = endingTime;
            }
        }
        result.push_back({start, end});

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}};

    vector<vector<int>> ans = s.merge(intervals);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}