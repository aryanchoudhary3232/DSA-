#include <bits/stdc++.h>
using namespace std;

// recursive approach
class Solution
{
private:
    int recursion(int idx, int prevIdx, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            return 0;
        }

        int include = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
        {
            include = 1 + recursion(idx + 1, idx, nums);
        }

        int exclude = recursion(idx + 1, prevIdx, nums);

        return max(include, exclude);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = recursion(0, -1, nums);

        return ans;
    }
};
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    cout << s.lengthOfLIS(nums);
    return 0;
}