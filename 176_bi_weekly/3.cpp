#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<long long>> dp;
    long long recursion(int idx, int prev, vector<int> &nums, vector<int> &colors)
    {
        if (idx == nums.size())
            return 0;

        if (dp[idx][prev] != -1)
        {
            return dp[idx][prev];
        }

        long long take = 0;
        if (prev == 0)
        {
            take = nums[idx] + recursion(idx + 1, 1, nums, colors);
        }
        else if (idx > 0 && prev == 1 && colors[idx] != colors[idx - 1])
        {
            take = nums[idx] + recursion(idx + 1, 1, nums, colors);
        }

        long long skip = 0;
        skip = recursion(idx + 1, 0, nums, colors);

        return dp[idx][prev] = max(take, skip);
    }

public:
    long long rob(vector<int> &nums, vector<int> &colors)
    {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        long long ans = recursion(0, 0, nums, colors);

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 4, 3, 5};
    vector<int> colors = {1, 1, 2, 2};

    Solution s;
    cout << s.rob(nums, colors);

    return 0;
}